#include <SFML/Graphics.hpp>
#include <windows.h>

#include "../include/Wallpaper.hpp"
#include "../include/ExecutaPartida.hpp"
#include <iostream>

using namespace std;

//declarações de função (prototipagem) eh boa pratica
void desenharMenu(sf::RenderWindow& window);
void desenharCadastro(sf::RenderWindow& window,sf::Font fonte);
void desenharListaDeJogadores(sf::RenderWindow& window,sf::Font fonte);
void desenharExcluirConta(sf::RenderWindow& window,sf::Font fonte);
void desenharEstatisticas(sf::RenderWindow& window,sf::Font fonte);

void desenharMenu(sf::RenderWindow& window) {
    Wallpaper wallpaper("menuInicial.png");
    wallpaper.redimensionar(window.getSize());

    Botao botaoJogador1(306.0, 49.f, 174.0, 206.f, sf::Color(223, 232, 106, 0), "Nick do Jogador 1", 15.f, false);
    botaoJogador1.criarBotoes();

    Botao botaoJogador2(306.0, 49.f, 177.0 + (306.0*1.5), 206.f, sf::Color(223, 232, 106, 0), "Nick do Jogador 2", 15.f, false);
    botaoJogador2.criarBotoes();

    Botao botaoCadastro(220.f, 65.f, 140.f, 368.f, sf::Color(150, 129, 250), "Cadastro", 25.f, false, sf::Color(43, 0, 108));
    botaoCadastro.criarBotoes();

    Botao botaoListaJogadores(500.f, 65.f, 390.f, 368.f, sf::Color(150, 129, 250), "Lista de Jogadores", 25.f, false, sf::Color(43, 0, 108));
    botaoListaJogadores.criarBotoes();

    Botao botaoExcluirConta(350.f, 65.f, 140.f, 458.f, sf::Color(150, 129, 250), "Excluir Conta", 25.f, false, sf::Color(43, 0, 108));
    botaoExcluirConta.criarBotoes();

    Botao botaoEstatistica(350.f, 65.f, 540.f, 458.f, sf::Color(150, 129, 250), "Estatisticas", 25.f, false, sf::Color(43, 0, 108));
    botaoEstatistica.criarBotoes();

    wallpaper.desenhar(window);
    botaoJogador1.desenhar(window);
    botaoJogador2.desenhar(window);
    botaoCadastro.desenhar(window);
    botaoListaJogadores.desenhar(window);
    botaoExcluirConta.desenhar(window);
    botaoEstatistica.desenhar(window);
}


void desenharCadastro(sf::RenderWindow& window,sf::Font fonte) { //quando o usuario clica em Cadastro, toda a lógica subseguinte será inteiramente implementada aqui dentro 
    
    Wallpaper wallpaper("menuCadastro.png");
    wallpaper.redimensionar(window.getSize());
    
    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    wallpaper.desenhar(window);
    botaoVoltar.desenhar(window);
}

void desenharListaDeJogadores(sf::RenderWindow& window,sf::Font fonte) { //quando o usuario clica em ListaDeJogadores, toda a lógica subseguinte será inteiramente implementada aqui dentro
    
    sf::Text title("Lista de Jogadores", fonte, 50);
    title.setPosition(300, 20);
    window.draw(title);

    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    botaoVoltar.desenhar(window);
}

void desenharExcluirConta(sf::RenderWindow& window,sf::Font fonte) { //quando o usuario clica em ExcluirConta, toda a lógica subseguinte será inteiramente implementada aqui dentro
    
    sf::Text title("Excluir Conta", fonte, 50);
    title.setPosition(300, 20);
    window.draw(title);

    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    botaoVoltar.desenhar(window);
}

void desenharEstatisticas(sf::RenderWindow& window,sf::Font fonte) { //quando o usuario clica em Estatisticas, toda a lógica subseguinte será inteiramente implementada aqui dentro
    
    sf::Text title("Estatísticas", fonte, 50);
    title.setPosition(300, 20);
    window.draw(title);

    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    botaoVoltar.desenhar(window);
}

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

    // Define as dimensões da janela
    int windowWidth = 1000;
    int windowHeight = 690;

    // Calcula a posição horizontal centralizada e define a posição vertical no topo da tela
    int windowPosX = (screenWidth - windowWidth) / 2;
    int windowPosY = 0;

    // Criação da janela com a posição ajustada
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Deluxe Collection");
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));

    string estadoAtual = "MenuPrincipal"; // I CANT STRESS ENOUGH HOW IMPORTANT THIS VARIABLE IS

    //---------------------------------------------------------------------------------------------//

    // Configurações iniciais de cor e forma
    sf::Color cor(255, 130, 190); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::CircleShape circulo(50.f);
    circulo.setFillColor(sf::Color::Blue);

    // Define a posição inicial do círculo
    circulo.setPosition(0.0, 0.0);

    // Cria dois pontos com coordenadas diferentes
    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);
    
    // Cria um relógio para medir o tempo
    sf::Clock relogio;
    
    PontoF pos3 = pos1 + pos2;

    //cout << pos3 << endl;

    // Cria um objeto Movimentacao para gerenciar o movimento
    Movimentacao movimentacao;

    while (window.isOpen()) {

        // Checa todos os eventos que ocorreram desde a última iteração do loop
        sf::Event event;
        while (window.pollEvent(event)) {    //pollEvent é uma função que retorna true se houver eventos na fila
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                //aparentemente a função mudar cor já tem conhecimento dessas regioes retangulares onde o mouse tá sobre
                //entao tem como dar uma boa otimizada e simplificar essas verificaçoes
                if (estadoAtual == "MenuPrincipal") {
                    if (mousePos.x > 140 && mousePos.x < 360) {  
                        if (mousePos.y > 368 && mousePos.y < 433) {
                            estadoAtual = "Cadastro";
                        }
                    }
                    if (mousePos.x > 390 && mousePos.x < 890) {
                        if (mousePos.y > 368 && mousePos.y < 433) {
                            estadoAtual = "ListaDeJogadores";
                        }
                    }
                    if (mousePos.x > 140 && mousePos.x < 490) {
                        if (mousePos.y > 458 && mousePos.y < 523) {
                            estadoAtual = "ExcluirConta";
                        }
                    }
                    if (mousePos.x > 540 && mousePos.x < 890) {
                        if (mousePos.y > 458 && mousePos.y < 523) {
                            estadoAtual = "Estatisticas";
                        }
                    }
                } else {
                    if (mousePos.x > 358 && mousePos.x < 642 && mousePos.y > 557 && mousePos.y < 624) { //regiao retangular padrao do "botao" de voltar
                        estadoAtual = "MenuPrincipal";
                    }
                }
            }
        }

        window.clear();

        if (estadoAtual == "MenuPrincipal") {
            desenharMenu(window);
        } else if (estadoAtual == "Cadastro") {
            desenharCadastro(window,fonte); //se o condicional da regiao do botao mudar o estadoAtual pra Cadastro entao chama a função desenharCadastro e assim por diante
        } else if (estadoAtual == "ListaDeJogadores") {
            desenharListaDeJogadores(window,fonte);
        } else if (estadoAtual == "ExcluirConta") {
            desenharExcluirConta(window,fonte);
        } else if (estadoAtual == "Estatisticas") {
            desenharEstatisticas(window,fonte);
        }

        window.display();
    }

    return 0;
}

