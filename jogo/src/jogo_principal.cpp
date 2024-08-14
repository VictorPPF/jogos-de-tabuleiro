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

#include <SFML/Graphics.hpp>
#include <iostream>

class CampoTexto {
public:
    
    CampoTexto(float largura, float altura, float posicaoX, float posicaoY) :
        retangulo(sf::Vector2f(largura, altura)),
        texto("", fonte, 25),
        ativo(false) {
        retangulo.setPosition(posicaoX, posicaoY);
        retangulo.setFillColor(sf::Color(223, 232, 106, 100)); // Cor semi-transparente
        retangulo.setOutlineThickness(2);
        retangulo.setOutlineColor(sf::Color::Black);

        texto.setPosition(posicaoX + 5, posicaoY + 10); // Pequeno deslocamento para dentro do retângulo
        texto.setFillColor(sf::Color::Black);
        
        // Carrega a fonte (faça isso uma vez no início do programa)
        if (!fonte.loadFromFile("font_arcade.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
        }
    }
    int VERIFICA = 0;
    

    void desenhar(sf::RenderWindow& window) {
        window.draw(retangulo);
        window.draw(texto);
    }

    void processarEventos(sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (retangulo.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                ativar();
            } else {
                desativar();
            }
        }

        if (event.type == sf::Event::TextEntered) {
            if (ativo) {
                if (event.text.unicode == '\b') { // Backspace
                    removerUltimoCaractere();
                } else if (event.text.unicode < 128) {
                    adicionarCaractere(static_cast<char>(event.text.unicode));
                }
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                if (ativo) {
                    cout << "Texto inserido: " << obterTexto() << endl;
                    VERIFICA = 1;
                    desativar();
                }
            }
        }
    }

    string obterTexto() const {
        return texto.getString();
    }

private:
    void ativar() {
        ativo = true;
        retangulo.setFillColor(sf::Color(223, 232, 106, 200)); // Mais brilhante quando ativo
    }

    void desativar() {
        ativo = false;
        retangulo.setFillColor(sf::Color(223, 232, 106, 100));
    }

    void adicionarCaractere(char c) {
        texto.setString(texto.getString() + c);
    }

    void removerUltimoCaractere() {
        sf::String str = texto.getString();
        if (str.getSize() > 0) {
            str.erase(str.getSize() - 1);
            texto.setString(str);
        }
    }

    sf::RectangleShape retangulo;
    sf::Text texto;
    sf::Font fonte;
    bool ativo;
};

void desenharMenu(sf::RenderWindow& window, sf::Event& event) {
    Wallpaper wallpaper("menuInicial.png");
    wallpaper.redimensionar(window.getSize());

    /*botao recebe: largura, altura, posicao x, posicao y, cor em rgb (a última coluna é transparencia), 
    texto, tamanho da fonte, se for circulo é true, cor da fonte (o padrão é white)*/

    Botao botaoJogador1(306.0, 49.f, 174.0, 206.f, sf::Color(223, 232, 106, 0), "", 15.f, false);
    botaoJogador1.criarBotoes();

    Botao botaoJogador2(306.0, 49.f, 177.0 + (306.0*1.5), 206.f, sf::Color(223, 232, 106, 0), "", 15.f, false);
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

void desenharCadastro(sf::RenderWindow& window,sf::Font fonte) { 
    
    Wallpaper wallpaper("menuCadastro.png");
    wallpaper.redimensionar(window.getSize());

    Botao botaoNome(502.0, 49.f, 327.f, 283.f, sf::Color(223, 232, 106, 0), "", 15.f, false);
    botaoNome.criarBotoes();

    Botao botaoApelido(502.0, 49.f, 327.f, 359.f, sf::Color(223, 232, 106, 0), "", 15.f, false);
    botaoApelido.criarBotoes();
    
    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    wallpaper.desenhar(window);
    botaoNome.desenhar(window);
    botaoApelido.desenhar(window);
    botaoVoltar.desenhar(window);
}

void desenharListaDeJogadores(sf::RenderWindow& window,sf::Font fonte) { 
    
    Wallpaper wallpaper("menuListaJogadores.png");
    wallpaper.redimensionar(window.getSize());

    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    wallpaper.desenhar(window);
    botaoVoltar.desenhar(window);
}

void desenharExcluirConta(sf::RenderWindow& window,sf::Font fonte) { 
    
    Wallpaper wallpaper("menuExcluirConta.png");
    wallpaper.redimensionar(window.getSize());
        
    Botao botaoApelido(502.0, 49.f, 327.f, 264.f, sf::Color(223, 232, 106, 0), "", 15.f, false);
    botaoApelido.criarBotoes();

    Botao botaoExcluir(350.f, 65.f, 171.f, 345.f, sf::Color(150, 129, 250), "Excluir Conta", 25.f, false, sf::Color(43, 0, 108));
    botaoExcluir.criarBotoes();

    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    wallpaper.desenhar(window);
    botaoApelido.desenhar(window);
    botaoExcluir.desenhar(window);
    botaoVoltar.desenhar(window);
}

void desenharEstatisticas(sf::RenderWindow& window,sf::Font fonte) { 
    
    Wallpaper wallpaper("menuEstatisticas.png");
    wallpaper.redimensionar(window.getSize());

    Botao botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(223, 232, 106, 0), "", 15.f, false);
    botaoApelido.criarBotoes();

    Botao botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    wallpaper.desenhar(window);
    botaoApelido.desenhar(window);
    botaoVoltar.desenhar(window);
    
}

void desenharJogo(sf::RenderWindow& window,sf::Font fonte) { //quando o usuario clica em Estatisticas, toda a lógica subseguinte será inteiramente implementada aqui dentro
    
    Wallpaper wallpaper("wallpaperflare.jpg");
    wallpaper.redimensionar(window.getSize());

    Botao botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(223, 232, 106, 100), "", 15.f, false);
    botaoApelido.criarBotoes();

    Botao botaoVoltar(284.f, 65.f, 0, 0, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108));
    botaoVoltar.criarBotoes();

    wallpaper.desenhar(window);
    botaoApelido.desenhar(window);
    botaoVoltar.desenhar(window);
}

int pronto(CampoTexto campoJogador1, CampoTexto campoJogador2) {
        if (campoJogador1.obterTexto() != "" && campoJogador2.obterTexto() != "" && 
        campoJogador1.VERIFICA == 1 && campoJogador2.VERIFICA == 1) {
            cout << "Pronto para jogar!" << endl;
            return 1;
        }
        return 0;
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

    // Criação dos campos de texto
    CampoTexto campoJogador1(306.0, 49.f, 174.0, 206.f);
    CampoTexto campoJogador2(306.0, 49.f, 177.0 + (306.0 * 1.5), 206.f);

    

    while (window.isOpen()) {

        // Checa todos os eventos que ocorreram desde a última iteração do loop
        sf::Event event;
        while (window.pollEvent(event)) {    //pollEvent é uma função que retorna true se houver eventos na fila
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (estadoAtual == "MenuPrincipal") {
                
                campoJogador1.processarEventos(event, window);
                campoJogador2.processarEventos(event, window);

                //agora se sabe q deu enter nos dois campos e tem condição pra comparar se sao validos
                //pra entrar na tela de jogo
                if (pronto(campoJogador1, campoJogador2) == 1) { 
                    estadoAtual = "Jogo";
                }
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
                    //regiao retangular padrao do "botao" de voltar só pra ALGUMAS telas
                    if (mousePos.x > 358 && mousePos.x < 642 && mousePos.y > 557 && mousePos.y < 624 
                    && (estadoAtual == "Cadastro" || estadoAtual == "ListaDeJogadores" || 
                        estadoAtual == "ExcluirConta" || estadoAtual == "Estatisticas")) { 
                    
                        estadoAtual = "MenuPrincipal";
                        campoJogador1.VERIFICA = 0; //tem que desvalidar quem muda o estadoAtual para Jogo
                        campoJogador2.VERIFICA = 0;

                    }
                }
                if (estadoAtual == "Jogo") {
                    sf::Vector2i mousePos_jogo = sf::Mouse::getPosition(window);
                    //botao de voltar do jogo vai ficar em posição diferente
                    if (mousePos_jogo.x > 0 && mousePos_jogo.x < 284 && mousePos_jogo.y > 0 && mousePos_jogo.y < 65) { 
                        estadoAtual = "MenuPrincipal";
                        campoJogador1.VERIFICA = 0;
                        campoJogador2.VERIFICA = 0;

                    }
                }
                //é melhor fazer a implementação de cada tela nesses if
                if (estadoAtual == "Cadastro") {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        
                }
                if (estadoAtual == "ListaDeJogadores") {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        
                }
                if (estadoAtual == "ExcluirConta") {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        
                }
                if (estadoAtual == "Estatisticas") {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        
                }
            }

        }

        window.clear();

        if (estadoAtual == "MenuPrincipal") {
                desenharMenu(window, event);
                campoJogador1.desenhar(window);
                campoJogador2.desenhar(window);
            } else if (estadoAtual == "Cadastro") { //se o condicional da regiao do botao mudar o estadoAtual
                desenharCadastro(window,fonte);  //pra Cadastro entao chama a função desenharCadastro e assim por diante
            } else if (estadoAtual == "ListaDeJogadores") {
                desenharListaDeJogadores(window,fonte);
            } else if (estadoAtual == "ExcluirConta") {
                desenharExcluirConta(window,fonte);
            } else if (estadoAtual == "Estatisticas") {
                desenharEstatisticas(window,fonte);
            } else if (estadoAtual == "Jogo") {
                desenharJogo(window,fonte);
            }

        window.display();
    }

    return 0;
}

