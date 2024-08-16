#include <SFML/Graphics.hpp>
#include <windows.h>

#include "../include/Wallpaper.hpp"
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"
#include "../include/CampoTexto.hpp"
#include "../include/Telas.hpp"

#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>
#include <iostream>

class TelaReversi {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;

public:
    Botao botaoApelido;
    Botao botaoVoltar;

    TelaReversi(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
        
        botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(223, 232, 106, 100), "", 15.f, false),
        botaoVoltar(284.f, 65.f, 0, 0, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108))
    {
        
        botaoApelido.criarBotoes();
        botaoVoltar.criarBotoes();
    }

    void desenharJogo() {
        Wallpaper wallpaper("wallpaperflare.jpg");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        botaoApelido.desenhar(window);
        botaoVoltar.desenhar(window);
    }
};

class TelaLig4 {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;

public:
    Botao botaoApelido;
    Botao botaoVoltar;

    TelaLig4(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
        
        
        botaoVoltar(284.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI !", 25.f, false, sf::Color(43, 0, 108))
    {
        
        botaoVoltar.criarBotoes();
    }

    void desenharJogo() {
        Wallpaper wallpaper("wallpaper_lig4.png");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        
        botaoVoltar.desenhar(window);
    }
};

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
    if (!fonte.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return 1;
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

    // Configurações iniciais de cor e forma
    sf::Color cor(255, 130, 190); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::CircleShape circulo(50.f);
    circulo.setFillColor(sf::Color::Blue);

    // Define a posição inicial do círculo
    circulo.setPosition(0.0, 0.0);
    //retangulo igual o circulo
    sf::RectangleShape retangulo(sf::Vector2f(100.f, 100.f));
    retangulo.setFillColor(sf::Color::Red);
    retangulo.setPosition(0.0, 0.0);

    // Cria dois pontos com coordenadas diferentes
    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);
    Movimentacao teste;
    
    
    // Cria um relógio para medir o tempo
    sf::Clock relogio;
    
    PontoF pos3 = pos1 + pos2;

    //cout << pos3 << endl;

    // Criação dos campos de texto
    float origemX = 238.0;
    float origemY = 166.0;
    int qtd_celulaX=7; //colunas
    int qtd_celulaY=6; //linhas
    float tamanho_celula= 75.0;
    Tabuleiro tabuleiroLIG4(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula);

    TelaMenu telaMenu (window,fonte,event);
    TelaReversi telaRever (window,fonte);
    TelaLig4 telaLig (window,fonte);
    TelaCadastro telaCadastro (window,fonte);
    TelaLista telaLista (window,fonte);
    TelaExcluirConta telaExcluir (window,fonte);
    TelaEstatisticas telaEstat (window,fonte);
    bool nao_ignora_mouse = true;

    while (window.isOpen()) {

        bool jogadores_validos = true; //dois_enter(telaMenu.campoJogador1,telaMenu.campoJogador2);
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

            }
            if (estadoAtual == "Cadastro") {
                telaCadastro.campoNome.processarEventos(event, window);
                telaCadastro.campoApelido.processarEventos(event, window);
            }
            if (estadoAtual == "ExcluirConta") {
                telaExcluir.campoApelido.processarEventos(event, window);

            }
            if (estadoAtual == "Estatisticas") {
                telaEstat.campoPesquisa.processarEventos(event, window);
                if (!telaEstat.botaoPesquisa.passouMouse(window)) {
                        telaEstat.botaoPesquisa.setCor(sf::Color(150, 129, 200,200)); 
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
                    }
                    //nao_ignora_mouse = true;
                    if (telaMenu.botaoListaJogadores.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "ListaDeJogadores";
                    }
                    //nao_ignora_mouse = true;
                    if (telaMenu.botaoExcluirConta.passouMouse(window)) {
                        estadoAtual = "ExcluirConta";
                    }
                    if (telaMenu.botaoEstatistica.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "Estatisticas";
                    }
                    // os botoes confirma e estatistica estão sobrepostos, então tem que ignorar o primeiro evento de clique
                    nao_ignora_mouse = true;

                    if (telaMenu.play1.passouMouse(window) && jogadores_validos) { //AQUI ENTRA NO JOGO REVERSI
                        telaMenu.campoJogador1.limparTexto();
                        telaMenu.campoJogador2.limparTexto();
                        estadoAtual = "Reversi";
                    }
                    if (telaMenu.play2.passouMouse(window) && jogadores_validos) { //AQUI ENTRA NO JOGO LIG4
                        telaMenu.campoJogador1.limparTexto();
                        telaMenu.campoJogador2.limparTexto();
                        estadoAtual = "Lig4";
                    }
                    
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
                        

                    }
                }
                if (estadoAtual == "Reversi") {
                    //botao de voltar do jogo vai ficar em posição diferente
                    if (telaRever.botaoVoltar.passouMouse(window)) { 
                        estadoAtual = "MenuPrincipal";
                        telaMenu.campoJogador1.deu_enter = 0;
                        telaMenu.campoJogador2.deu_enter = 0;
                    }
                }
                if (estadoAtual == "Lig4") {
                    //botao de voltar do jogo vai ficar em posição diferente
                    if (telaLig.botaoVoltar.passouMouse(window)) { 
                        estadoAtual = "MenuPrincipal";
                        telaMenu.campoJogador1.deu_enter = 0;
                        telaMenu.campoJogador2.deu_enter = 0;
                    }
                }
                
                if (estadoAtual == "Cadastro") {
                    if (telaCadastro.botaoConfirma.passouMouse(window) && cadastro_valido) {
                        telaCadastro.campoNome.limparTexto();
                        telaCadastro.campoApelido.limparTexto();
                        nao_ignora_mouse = false;
                        telaCadastro.botaoConfirma.setCor(sf::Color(220, 100, 180,100)); 
                        telaCadastro.botaoConfirma.setCorHover(sf::Color(255, 0, 20, 100));
                        estadoAtual = "MenuPrincipal";
                        
                    }
                }
                if (estadoAtual == "ListaDeJogadores") {
                    
                        
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
            }
            if (estadoAtual == "Reversi") {
                sf::Vector2i mousePos_jogo = sf::Mouse::getPosition(window);
                // Verifica as teclas pressionadas e move o círculo
                
                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    teste.mover(retangulo, sf::Keyboard::W);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        
                        teste.mover(retangulo, sf::Keyboard::A);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        teste.mover(retangulo, sf::Keyboard::S);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        teste.mover(retangulo, sf::Keyboard::D);
                    }
                }
                
            }
            if (estadoAtual == "Lig4") {
                sf::Vector2i mousePos_jogo = sf::Mouse::getPosition(window);
                // Verifica as teclas pressionadas e move o círculo
                
                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    teste.mover(circulo, sf::Keyboard::W);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        
                        teste.mover(circulo, sf::Keyboard::A);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        teste.mover(circulo, sf::Keyboard::S);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        teste.mover(circulo, sf::Keyboard::D);
                    }
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
                telaRever.desenharJogo();
                window.draw(retangulo);
            }else if (estadoAtual == "Lig4") {
                telaLig.desenharJogo();
                window.draw(circulo);
                tabuleiroLIG4.desenhar(window);
            }
            

        window.display();
    }

    return 0;
}

