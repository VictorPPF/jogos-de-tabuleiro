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

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * Logica de teste para validar entrada do primeiro e do segundo jogador
 * @param campoJogador1 um objeto do tipo CampoTexto. Este parâmetro representa o campo de texto do primeiro 
 * jogador, contendo métodos para obter o texto digitado e verificar se o jogador pressionou "Enter".
 * @param campoJogador1 um objeto do tipo CampoTexto. Este parâmetro representa o campo de texto do segndo jogador,
 * tem o mesmo objetivo do primeiro 
 * @return true se ambos os campos não estiverem vazios e se ambos os jogadores pressionaram "Enter".
 */

bool dois_enter(CampoTexto campoJogador1, CampoTexto campoJogador2) {
        if (campoJogador1.obterTexto() != "" && campoJogador2.obterTexto() != "" && 
        campoJogador1.deu_enter == 1 && campoJogador2.deu_enter == 1) {
            return true;
        }
        return false;
    };

int main() {
    /**
     * Ele carrega a fonte font_arcade.ttf e trata exceções adequadamente. 
     * Se a fonte não for carregada, uma exceção std::runtime_error é lançada
     *  e o erro é reportado via std::cerr. Em seguida, a exceção é relançada para que o 
     * chamador possa tratá-la ou o programa seja encerrado adequadamente.
     */
    sf::Font fonte;
    try {
        if (!fonte.loadFromFile("font_arcade.ttf")) {
            throw std::runtime_error("Falha ao carregar a fonte.");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
    /**
     * Nesta etapa, carregamos os módulos para iniciar a tela do jogo nas dimensões da tela do usuário
     */

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
    /**
     * Nesta parte do código, temos algumas definições de variáveis, chamar as classes, entre outros.
     */
    /**
     * Cria um relógio para medir o tempo
     */
    sf::Clock relogio;
    /**
     * Essas linhas de código são responsáveis por criar instâncias das classes TelaMenu, JogoReversi, 
     * JogoLig4, TelaCadastro, TelaLista, TelaExcluirConta, TelaEstatisticas, FimDeJogoLig4, e FimDeJogoReversi. 
     * Cada uma dessas classes representa uma tela ou estado específico dentro do 
     * jogo e as instâncias são inicializadas com os mesmos parâmetros: window, fonte e, em alguns, event.
     */
    TelaMenu telaMenu (window,fonte,event);
    JogoReversi TelaReversi(window,fonte,event);
    JogoLig4 telaLig (window,fonte,event);
    TelaCadastro telaCadastro (window,fonte);
    TelaLista telaLista (window,fonte);
    TelaExcluirConta telaExcluir (window,fonte);
    TelaEstatisticas telaEstat (window,fonte);
    FimDeJogoLig4 fimDeJogoLig4 (window,fonte);
    FimDeJogoRevesi fimDeJogoReversi (window,fonte);

    /**
     * Aqui temos as variáveis que controlam os clique do mouse, evitando duplos clicks
     */
    bool nao_ignora_mouse = true;
    bool ignorarProximoClique = false;

     /**
     * Variáveis que testam se os jogadores estão logados, para liberar o acesso aos dois jogos
     */
    bool jogador1_valido = false; 
    bool jogador2_valido = false;
    std::string apelido_jogador1, apelido_jogador2;
    bool jogadores_validos= false;
    while (window.isOpen()) {
        /**
         * Checa todos os eventos que ocorreram desde a última iteração do loop
         */
        bool cadastro_valido = dois_enter(telaCadastro.campoNome,telaCadastro.campoApelido);
        bool jogador_existe = telaExcluir.campoApelido.obterTexto() != "";
        bool jogador_encontrado = telaEstat.campoPesquisa.obterTexto() != "";
        
        /**
         * pollEvent é uma função que retorna true se houver eventos na fila, nesse loop principal
         * que o jogo é executado.
         */
        while (window.pollEvent(event)) {
            /**
             * caso o jogador clique em fechar a tela, o jogo será encerrado.
             */    
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            /**
             * Nesta etapa, temos a dinâmica com a tela inicial 'Menu', onde temos os botões:
             * 
             * Inserir jogadores válidos, cadastrar novos jogadores, lista de todos os jogadores cadastrados,
             * estatisticas de um jogador especifico e excluir um jogador específico.
             */ 
            if (estadoAtual == "MenuPrincipal") {
                telaMenu.campoJogador1.processarEventos(event, window);
                telaMenu.campoJogador2.processarEventos(event, window);
                
                /**
                 * Quando entra com dois jogadores cadastrados, o botão para entrar nos jogos Reversi e Lig4 é liberado.
                 */ 
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

                /**
                 * Verifica se o jogador 1 foi logado com sucesso.
                 */ 
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
                    delete jogador1;
                }

                /**
                 * Verifica se o jogador 2 foi logado com sucesso.
                 */ 
                if(telaMenu.campoJogador2.deu_enter){ 
                    Jogador* jogador2 = new Jogador(telaMenu.campoJogador2.obterTexto());
                    if(jogador2->existeConta()){
                        std::cout<< "Jogador 2 foi logado com sucesso!" <<std::endl;
                        jogador2_valido=true;
                        apelido_jogador2=telaMenu.campoJogador2.obterTexto();
                    }else{
                        std::cout<< "Jogador 2 nao foi logado com sucesso!" <<std::endl;
                        jogador2_valido=false;
                    }
                    delete jogador2;   
                }
                if(jogador1_valido && jogador2_valido){jogadores_validos=true;}
            }

            if (estadoAtual == "Cadastro") {
                telaCadastro.campoNome.processarEventos(event, window);
                telaCadastro.campoApelido.processarEventos(event, window);
                if(telaCadastro.campoNome.deu_enter && telaCadastro.campoApelido.deu_enter || telaCadastro.botaoConfirma.foiClicado(window)){
                    /**
                     * Logico pra testar se o cadastro é valido e guardar ele
                     */ 
                    Jogador* cadastroJogador = new Jogador(telaCadastro.campoNome.obterTexto(),telaCadastro.campoApelido.obterTexto());
                    }

                    delete cadastroJogador;
                }
                
        
            if (estadoAtual == "ExcluirConta") {
                telaExcluir.campoApelido.processarEventos(event, window);
                if(telaExcluir.botaoExcluir.foiClicado(window)){
                    std::string apelidoDaConta = telaExcluir.campoApelido.obterTexto();
                    Jogador* excluiJogador = new Jogador(apelidoDaConta);
                    /**
                     * Se existe jogador cadastrado e o usuário quer exclui-lo, então será excluído
                     */
                    if(excluiJogador->existeConta()){
                        excluiJogador->excluirConta();
                        std::cout<< "Conta excluida com sucesso!" << std::endl;
                    }else{
                        std::cout<< "Conta nao existente!" << std::endl;
                    }

                    delete excluiJogador;
                }
            }

            if (estadoAtual == "Estatisticas") {
                telaEstat.campoPesquisa.processarEventos(event, window);
                if (!telaEstat.botaoPesquisa.passouMouse(window)) {
                        telaEstat.botaoPesquisa.setCor(sf::Color(150, 129, 200,200)); 
                    }

                    if(telaEstat.botaoPesquisa.foiClicado(window)){
                        std::string nomeJogador = telaEstat.campoPesquisa.obterTexto();
                        Jogador* estatisticaJogador = new Jogador(telaEstat.campoPesquisa.obterTexto());
                        /**
                         * Se o jogador está cadastrado, aqui ele mostra as estatísticas dele.
                         */
                        if(estatisticaJogador->existeConta()){
                            estatisticaJogador->getResultado();
                            telaEstat.setJogador(*estatisticaJogador);
                        }else{
                            std::cout << "Erro! Conta nao existente!" <<std::endl;
                        }
                        delete estatisticaJogador;
                    }
            }

            /**
            * Aqui verifica se as informações preenchidas nos campos são válidos.
            */
            
            if (jogadores_validos) { 
                telaMenu.play1.setCor(sf::Color(150, 129, 250));
                telaMenu.play2.setCor(sf::Color(150, 129, 250));
            }
            else {
                telaMenu.play1.setCor(sf::Color(50, 50, 50));
                telaMenu.play2.setCor(sf::Color(50, 50, 50));
            }
            
            if (cadastro_valido) { 
                telaCadastro.botaoConfirma.setCor(sf::Color(43, 246, 21,100));
                telaCadastro.botaoConfirma.setCorHover(sf::Color(43, 246, 21,200));
            }
            
            if (jogador_existe) { 
                telaExcluir.botaoExcluir.setCor(sf::Color(43, 246, 21,100));
                telaExcluir.botaoExcluir.setCorHover(sf::Color(43, 246, 21,200));
                
            }
            if (jogador_encontrado) { 
                telaEstat.botaoPesquisa.setCor(sf::Color(43, 246, 21,100));
                telaEstat.botaoPesquisa.setCorHover(sf::Color(43, 246, 21,200));
            }
            
            /**
            * Nesta etapa, verifica se os botões foram clicados, também inserimos uma lógica para evitar duplo click
            */
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                
                if (estadoAtual == "MenuPrincipal") {

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

                } else {
                    /**
                    * Aqui definimos uma regiao retangular padrao do "botao" de voltar só pra ALGUMAS telas.
                    * Quando clica em voltar, limpa os campos escritos.
                    */
                    if (mousePos.x > 358 && mousePos.x < 642 && mousePos.y > 557 && mousePos.y < 624 
                    && (estadoAtual == "Cadastro" || estadoAtual == "ListaDeJogadores" || 
                        estadoAtual == "ExcluirConta" || estadoAtual == "Estatisticas")) { 
                    
                        estadoAtual = "MenuPrincipal";
                        telaMenu.campoJogador1.deu_enter = 0;
                        telaMenu.campoJogador2.deu_enter = 0;

                        telaCadastro.campoNome.limparTexto();
                        telaCadastro.campoApelido.limparTexto();
                        telaEstat.campoPesquisa.limparTexto();
                    }
                }
                /**
                * Aqui conectamos os jogadores em seus respectivos jogos
                */
                if (estadoAtual == "Reversi") {
                    Jogador* jogador1 = new Jogador(apelido_jogador1);
                    Jogador* jogador2 = new Jogador(apelido_jogador2);
                    TelaReversi.setJogadores(*jogador1, *jogador2);

                    if (TelaReversi.botaoVoltar.passouMouse(window)) {
                        TelaReversi.jogadorDesistiu = true;
                        TelaReversi.LimpaTabuleiro();
                        estadoAtual = "FimDeJogoReversi";
                        nao_ignora_mouse = true;
                    } 
                    delete jogador1;
                    delete jogador2; 
                }
                if (estadoAtual == "Lig4") {
                    Jogador* jogador1 = new Jogador(apelido_jogador1);
                    Jogador* jogador2 = new Jogador(apelido_jogador2);
                    telaLig.setJogadores(*jogador1, *jogador2);
                    
                    if (telaLig.botaoVoltar.passouMouse(window)) { 
                        std::cout << "Botao voltar clicado" << std::endl;
                        telaLig.LimpaTabuleiro();
                        estadoAtual = "FimDeJogoLig4";
                        nao_ignora_mouse = true;
                    }
                    delete jogador1;
                    delete jogador2; 
                }

                /**
                * Aqui limpa os campos quando cadastramos novos jogadores. Além das alterações de cor dos botões ao cadastrar os usuários.
                */
                if (estadoAtual == "Cadastro") {
                    if (telaCadastro.botaoConfirma.passouMouse(window) && cadastro_valido) {
                        telaCadastro.campoNome.limparTexto();
                        telaCadastro.campoApelido.limparTexto();
                        telaCadastro.botaoConfirma.setCor(sf::Color(220, 100, 180,100)); 
                        telaCadastro.botaoConfirma.setCorHover(sf::Color(255, 0, 20, 100));
                        estadoAtual = "MenuPrincipal";                        
                    }
                }
                /**
                * Acessa o histórico de jogadores dentro da tela que exibe a lista de jogadores.
                */
                if (estadoAtual == "ListaDeJogadores") { 
                    Historico hist;
                    hist.acessarDados();
                }
                /**
                * Dinâmica para mudar as cores dos botões da tela excluir conta, quando existe um jogador válido.
                */
                if (estadoAtual == "ExcluirConta") {
                    if (telaExcluir.botaoExcluir.passouMouse(window) && jogador_existe) {
                        telaExcluir.campoApelido.limparTexto();
                        nao_ignora_mouse = false;
                        telaExcluir.botaoExcluir.setCor(sf::Color(220, 100, 180,100)); 
                        telaExcluir.botaoExcluir.setCorHover(sf::Color(255, 0, 20, 100));
                        estadoAtual = "MenuPrincipal";
                    }
                        
                }
                if (estadoAtual == "Estatisticas") {     

                    if (telaEstat.botaoPesquisa.passouMouse(window) && event.mouseButton.button == sf::Mouse::Left) {
                        telaEstat.botaoPesquisa.setCor(sf::Color(100, 129 - 50, 200));
                    }
                }
                /**
                * Nesta etapa, exibimos as telas de fim de jogo, quando a partida é finalizada.
                */
                if (estadoAtual == "FimDeJogoLig4") {

                    if (fimDeJogoLig4.botaoMenu.passouMouse(window)) {
                        telaLig.LimpaTabuleiro();
                        estadoAtual = "MenuPrincipal";
                        telaLig.fimDeJogo = false;
                        nao_ignora_mouse = true;
                    }
                    
                    if (fimDeJogoLig4.botaoRestart.foiClicado(window)){
                        telaLig.LimpaTabuleiro();
                        estadoAtual = "Lig4";
                        telaLig.fimDeJogo = false;
                        nao_ignora_mouse = true;
                    }
                    
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
            }
            
            
        }

        window.clear();

        /**
        * Nesta etapa, desenhamos cada tela das nossas paginas.
        */
        if (estadoAtual == "MenuPrincipal") {
                telaMenu.desenharMenu();
            } else if (estadoAtual == "Cadastro") { 
                telaCadastro.desenharJogo();  
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
