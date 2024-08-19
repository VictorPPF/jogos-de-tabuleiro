#include <SFML/Graphics.hpp>
#include <windows.h>

#include "../include/Wallpaper.hpp"
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"
#include "../include/CampoTexto.hpp"
#include "../include/Telas.hpp"
#include "../include/Jogador.hpp"
#include "../include/JogoLig4.hpp"
#include"../include/JogoReversi.hpp"
#include"../include/Jogo.hpp"

#include <iostream>

using namespace std;

 //logica idiota de teste pra validar entrada de campos de texto
bool dois_enter(CampoTexto campoJogador1, CampoTexto campoJogador2) {
        if (campoJogador1.obterTexto() != "" && campoJogador2.obterTexto() != "" && 
        campoJogador1.deu_enter == 1 && campoJogador2.deu_enter == 1) {
            // campoJogador1.deu_enter = 0;
            // campoJogador2.deu_enter = 0;
            return true;
        }
        return false;
    };

int main() {
    //carrega a fonte só uma vez 
    sf::Font fonte;
    // Carregar a fonte
    try {
        if (!fonte.loadFromFile("font_arcade.ttf")) {
            throw std::runtime_error("Falha ao carregar a fonte.");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        // Lançar a exceção para indicar falha de inicialização
        throw;
    }
    //--------------- MÓDULO PARA INICIAR A TELA DO JOGO NAS DIMENSÕES DA TELA DA PESSOA-----------------//
    // Obtém as dimensões da tela
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);
    int screenWidth = screenRect.right - screenRect.left;
    sf::Event event;
    // Define as dimensões da janela
    int windowLargura = 1000;
    int windowAltura = 690;

    // Calcula a posição horizontal centralizada e define a posição vertical no topo da tela
    int windowPosX = (screenWidth - windowLargura) / 2;
    int windowPosY = 0;

    // Criação da janela com a posição ajustada
    sf::RenderWindow window(sf::VideoMode(windowLargura, windowAltura), "Deluxe Collection");
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));

    string estadoAtual = "MenuPrincipal"; // I CANT STRESS ENOUGH HOW IMPORTANT THIS VARIABLE IS

    //---------------------------------------------------------------------------------------------//
    
    // Cria um relógio para medir o tempo
    sf::Clock relogio;

    //cout << pos3 << endl;

 
    TelaMenu telaMenu (window,fonte,event);
    JogoReversi TelaReversi(window,fonte,event);
    JogoLig4 telaLig (window,fonte,event);
    TelaCadastro telaCadastro (window,fonte);
    TelaLista telaLista (window,fonte);
    TelaExcluirConta telaExcluir (window,fonte);
    TelaEstatisticas telaEstat (window,fonte);
    FimDeJogoLig4 fimDeJogoLig4 (window,fonte);
    FimDeJogoRevesi fimDeJogoReversi (window,fonte);

    bool nao_ignora_mouse = true;
    bool ignorarProximoClique = false;

    //Variaveis que testam se os jogadores estão logados
    bool jogador1_valido = false; 
    bool jogador2_valido = false;
    std::string apelido_jogador1, apelido_jogador2;
    //bool jogadores_validos=false; *************TIRAR ESSE COMENTÁRIO QUANDO FOR DAR COMMIT
    bool jogadores_validos= false;
    while (window.isOpen()) {
        bool cadastro_valido = dois_enter(telaCadastro.campoNome,telaCadastro.campoApelido);
        bool jogador_existe = telaExcluir.campoApelido.obterTexto() != "";
        bool jogador_encontrado = telaEstat.campoPesquisa.obterTexto() != "";
        // Checa todos os eventos que ocorreram desde a última iteração do loop
        while (window.pollEvent(event)) {    //pollEvent é uma função que retorna true se houver eventos na fila
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (estadoAtual == "MenuPrincipal") {
                telaMenu.campoJogador1.processarEventos(event, window);
                telaMenu.campoJogador2.processarEventos(event, window);
                //Logica caso os jogadores estejam logados
                if(jogadores_validos){
                    telaMenu.play1.setCor(sf::Color(150, 129, 200,200));
                    telaMenu.play2.setCor(sf::Color(150, 129, 200,200));
                    if(telaMenu.play1.foiClicado(window)){//Testa se o botao Reversi foi clicado
                        std::cout << "Botao Reversi clicado!!!" << std::endl;
                        std::cout << "Vez do Jogador " << jogador1_valido << " - Cor: Vermelho" << std::endl;
                        telaMenu.campoJogador1.limparTexto();
                        telaMenu.campoJogador2.limparTexto();
                        estadoAtual = "Reversi";
                        nao_ignora_mouse = true;
                    }
                    if(telaMenu.play2.foiClicado(window)){//Testa se o botao Lig4 foi clicado
                        std::cout << "Botao Lig4 clicado!!!" << std::endl;
                        std::cout << "Vez do Jogador " << jogador1_valido << " - Cor: Vermelho" << std::endl;
                        telaMenu.campoJogador1.limparTexto();
                        telaMenu.campoJogador2.limparTexto();
                        estadoAtual = "Lig4";
                        nao_ignora_mouse = true;
                    }
                }

                if(telaMenu.campoJogador1.deu_enter){//Logica para jogador 1 logar
                    Jogador* jogador1 = new Jogador(telaMenu.campoJogador1.obterTexto());
                    if(jogador1->existeConta()){
                        std::cout<< "Jogador 1 foi logado com sucesso!" <<std::endl;
                        jogador1_valido=true;
                        apelido_jogador1=telaMenu.campoJogador1.obterTexto();
                    }else{
                        std::cout<< "Jogador 1 nao foi logado com sucesso!" <<std::endl;
                        jogador1_valido=false;
                    }
                }
                if(telaMenu.campoJogador2.deu_enter){ //Logica para jogador 2 logar
                    Jogador* jogador2 = new Jogador(telaMenu.campoJogador2.obterTexto());
                    if(jogador2->existeConta()){
                        std::cout<< "Jogador 2 foi logado com sucesso!" <<std::endl;
                        jogador2_valido=true;
                        apelido_jogador2=telaMenu.campoJogador2.obterTexto();
                    }else{
                        std::cout<< "Jogador 2 nao foi logado com sucesso!" <<std::endl;
                        jogador2_valido=false;
                    }   
                }
                if(jogador1_valido && jogador2_valido){jogadores_validos=true;}
            }

            if (estadoAtual == "Cadastro") {
                telaCadastro.campoNome.processarEventos(event, window);
                telaCadastro.campoApelido.processarEventos(event, window);
                if(telaCadastro.campoNome.deu_enter && telaCadastro.campoApelido.deu_enter || telaCadastro.botaoConfirma.foiClicado(window)){
                    //Logico pra testar se o cadastro é valido e guardar ele
                    Jogador* cadastroJogador = new Jogador(telaCadastro.campoNome.obterTexto(),telaCadastro.campoApelido.obterTexto());
                    }
                }
                
        
            if (estadoAtual == "ExcluirConta") {
                telaExcluir.campoApelido.processarEventos(event, window);
                if(telaExcluir.botaoExcluir.foiClicado(window)){
                    std::string apelidoDaConta = telaExcluir.campoApelido.obterTexto();
                    Jogador* excluiJogador = new Jogador(apelidoDaConta);
                    if(excluiJogador->existeConta()){
                        excluiJogador->excluirConta();
                        std::cout<< "Conta excluida com sucesso!" << std::endl;
                    }else{
                        std::cout<< "Conta nao existente!" << std::endl;
                    }
                }
            }

            if (estadoAtual == "Estatisticas") {
                telaEstat.campoPesquisa.processarEventos(event, window);
                if (!telaEstat.botaoPesquisa.passouMouse(window)) {
                        telaEstat.botaoPesquisa.setCor(sf::Color(150, 129, 200,200)); 
                    }

                    //Logica para mostrar estatisticas
                    if(telaEstat.botaoPesquisa.foiClicado(window)){
                        std::string nomeJogador = telaEstat.campoPesquisa.obterTexto();
                        Jogador* estatisticaJogador = new Jogador(telaEstat.campoPesquisa.obterTexto());
                        if(estatisticaJogador->existeConta()){
                            estatisticaJogador->getResultado();
                            telaEstat.setJogador(*estatisticaJogador);
                        }else{
                            std::cout << "Erro! Conta nao existente!" <<std::endl;
                        }
                        delete estatisticaJogador;
                    }
            }
            //agora se sabe q deu enter nos dois campos e tem condição pra comparar se sao validos
            //pra entrar na tela de jogo
            //logica idiota de teste pra validar entrada de campos de texto (substituir pela logica correta consultando no banco de dados)
            
            if (jogadores_validos) { 
                telaMenu.play1.setCor(sf::Color(150, 129, 250));
                telaMenu.play2.setCor(sf::Color(150, 129, 250));
            }
            else {
                telaMenu.play1.setCor(sf::Color(50, 50, 50));
                telaMenu.play2.setCor(sf::Color(50, 50, 50));
            }
            //logica idiota de teste pra validar entrada de campos de texto (substituir pela logica correta consultando no banco de dados)
            
            if (cadastro_valido) { 
                telaCadastro.botaoConfirma.setCor(sf::Color(43, 246, 21,100));
                telaCadastro.botaoConfirma.setCorHover(sf::Color(43, 246, 21,200));
            }
            //logica idiota de teste pra validar entrada de campos de texto (substituir pela logica correta consultando no banco de dados)
            
            if (jogador_existe) { 
                telaExcluir.botaoExcluir.setCor(sf::Color(43, 246, 21,100));
                telaExcluir.botaoExcluir.setCorHover(sf::Color(43, 246, 21,200));
                
            }
            if (jogador_encontrado) { 
                telaEstat.botaoPesquisa.setCor(sf::Color(43, 246, 21,100));
                telaEstat.botaoPesquisa.setCorHover(sf::Color(43, 246, 21,200));
            }
            

            if ( event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                
                if (estadoAtual == "MenuPrincipal") {
                    //sf::sleep(sf::milliseconds(1000)); // Atraso de 100 milissegundos
                    // os botoes excluir, estatistica e lista estão sobrepostos, então tem que ignorar o primeiro evento de clique
                    if (telaMenu.botaoCadastro.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "Cadastro";
                        nao_ignora_mouse = true;
                    }
                    //nao_ignora_mouse = true;
                    if (telaMenu.botaoListaJogadores.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "ListaDeJogadores";
                        nao_ignora_mouse = true;
                    }
                    //nao_ignora_mouse = true;
                    if (telaMenu.botaoExcluirConta.passouMouse(window)) {
                        estadoAtual = "ExcluirConta";
                        nao_ignora_mouse = true;
                    }
                    if (telaMenu.botaoEstatistica.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "Estatisticas";
                        nao_ignora_mouse = true;
                    }
                    // os botoes confirma e estatistica estão sobrepostos, então tem que ignorar o primeiro evento de clique
                    //nao_ignora_mouse = true;

                } else {
                    //regiao retangular padrao do "botao" de voltar só pra ALGUMAS telas
                    if (mousePos.x > 358 && mousePos.x < 642 && mousePos.y > 557 && mousePos.y < 624 
                    && (estadoAtual == "Cadastro" || estadoAtual == "ListaDeJogadores" || 
                        estadoAtual == "ExcluirConta" || estadoAtual == "Estatisticas")) { 
                    
                        estadoAtual = "MenuPrincipal";
                        telaMenu.campoJogador1.deu_enter = 0; //tem que desvalidar quem muda o estadoAtual para Jogo
                        telaMenu.campoJogador2.deu_enter = 0;

                        //pra nao ficar escrito na tela coisa antiga
                        telaCadastro.campoNome.limparTexto();
                        telaCadastro.campoApelido.limparTexto();
                        telaEstat.campoPesquisa.limparTexto();
                    }
                }
                if (estadoAtual == "Reversi") {
                    Jogador* jogador1 = new Jogador(apelido_jogador1);
                    Jogador* jogador2 = new Jogador(apelido_jogador2);
                    TelaReversi.setJogadores(*jogador1, *jogador2);

                    //botao de voltar do jogo vai ficar em posição diferente
                    if (TelaReversi.botaoVoltar.passouMouse(window)) {
                        TelaReversi.jogadorDesistiu = true;
                        TelaReversi.LimpaTabuleiro();
                        estadoAtual = "FimDeJogoReversi";
                        nao_ignora_mouse = true;
                    }  
                }
                if (estadoAtual == "Lig4") {
                    Jogador* jogador1 = new Jogador(apelido_jogador1);
                    Jogador* jogador2 = new Jogador(apelido_jogador2);
                    telaLig.setJogadores(*jogador1, *jogador2);
                    
                    //botao de voltar do jogo vai ficar em posição diferente
                    if (telaLig.botaoVoltar.passouMouse(window)) { 
                        std::cout << "Botao voltar clicado" << std::endl;
                        telaLig.LimpaTabuleiro();
                        estadoAtual = "FimDeJogoLig4";
                        nao_ignora_mouse = true;
                    }
                }
                if (estadoAtual == "Cadastro") {
                    if (telaCadastro.botaoConfirma.passouMouse(window) && cadastro_valido) {
                        telaCadastro.campoNome.limparTexto();
                        telaCadastro.campoApelido.limparTexto();
                        telaCadastro.botaoConfirma.setCor(sf::Color(220, 100, 180,100)); 
                        telaCadastro.botaoConfirma.setCorHover(sf::Color(255, 0, 20, 100));
                        estadoAtual = "MenuPrincipal";                        
                    }
                }
                if (estadoAtual == "ListaDeJogadores") { 
                    Historico hist;
                    hist.acessarDados();
                }
                if (estadoAtual == "ExcluirConta") {
                    if (telaExcluir.botaoExcluir.passouMouse(window) && jogador_existe) {
                        telaExcluir.campoApelido.limparTexto();
                        nao_ignora_mouse = false;
                        telaExcluir.botaoExcluir.setCor(sf::Color(220, 100, 180,100)); 
                        telaExcluir.botaoExcluir.setCorHover(sf::Color(255, 0, 20, 100));
                        estadoAtual = "MenuPrincipal";
                    }
                        
                }
                if (estadoAtual == "Estatisticas") { //AQUI CHAMA AS ESTATISTICAS CONSULTANDO O HISTÓRICO
    

                    if (telaEstat.botaoPesquisa.passouMouse(window) && event.mouseButton.button == sf::Mouse::Left) {
                        telaEstat.botaoPesquisa.setCor(sf::Color(100, 129 - 50, 200)); //150, 129, 250 roxo padrao
                    }
                }
                if (estadoAtual == "FimDeJogoLig4") {

                    if (fimDeJogoLig4.botaoMenu.passouMouse(window)) {
                        telaLig.LimpaTabuleiro();
                        estadoAtual = "MenuPrincipal";
                        telaLig.fimDeJogo = false;
                        nao_ignora_mouse = true;
                    }
                    /*
                    if (fimDeJogoLig4.botaoRestart.foiClicado(window)){
                        telaLig.LimpaTabuleiro();
                        estadoAtual = "Lig4";
                        telaLig.fimDeJogo = false;
                        nao_ignora_mouse = true;
                    }
                    */
                }
                if (estadoAtual == "FimDeJogoReversi") {

                    if (fimDeJogoReversi.botaoMenu.passouMouse(window)) { 
                        TelaReversi.fimDeJogo = false;
                        estadoAtual = "MenuPrincipal";
                        nao_ignora_mouse = true;
                    }
                    /*
                    if (fimDeJogoReversi.botaoRestart.passouMouse(window)){
                        estadoAtual = "Reversi";
                        TelaReversi.fimDeJogo = true;
                        nao_ignora_mouse = true;
                    }
                    */
                }
                // if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                //     nao_ignora_mouse = false;
                // }
            }
            if (estadoAtual == "Reversi") {
                sf::Vector2i mousePos_jogo = sf::Mouse::getPosition(window);

                if (TelaReversi.fimDeJogo){
                    estadoAtual = "FimDeJogoReversi";
                    //TelaReversi.fimDeJogo = false;
                }
                
            }
            if (estadoAtual == "Lig4") {
                sf::Vector2i mousePos_jogo = sf::Mouse::getPosition(window);
                
                if (telaLig.fimDeJogo){
                    estadoAtual = "FimDeJogoLig4";
                    telaLig.fimDeJogo = false;
                }

                //matriz
                
            }
            
            
        }

        window.clear();
        
        if (estadoAtual == "MenuPrincipal") {
                telaMenu.desenharMenu();
            } else if (estadoAtual == "Cadastro") { //se o condicional da regiao do botao mudar o estadoAtual
                telaCadastro.desenharJogo();  //pra Cadastro entao chama a função desenharCadastro e assim por diante
            } else if (estadoAtual == "ListaDeJogadores") {
                
                telaLista.desenharLista();
            } else if (estadoAtual == "ExcluirConta") {
                telaExcluir.desenharExcluirConta();
            } else if (estadoAtual == "Estatisticas") {
                telaEstat.desenharEstatisticas();
            } else if (estadoAtual == "Reversi") {
                TelaReversi.desenharJogo();
            }else if (estadoAtual == "Lig4") {
                telaLig.desenharJogo();
            }else if (estadoAtual == "FimDeJogoLig4") {
                std::string nomeVencedor = telaLig.getNomeVencedor();
                fimDeJogoLig4.desenharTelaFinal(nomeVencedor);
            }
            else if (estadoAtual == "FimDeJogoReversi") {
                std::string nomeVencedor = TelaReversi.getNomeVencedor();
                fimDeJogoReversi.desenharTelaFinal(nomeVencedor);
            }
            

        window.display();
    }
    return 0;
}
