#include <SFML/Graphics.hpp>
#include <windows.h>

#include "../include/Wallpaper.hpp"
#include "../include/ExecutaPartida.hpp"
#include <iostream>

using namespace std;

// Função para desenhar o menu
void desenharMenu(sf::RenderWindow& window, std::string& jogador1, std::string& jogador2){
    Wallpaper wallpaper("menuInicial.png");
    wallpaper.redimensionar(window.getSize());

    // Criação do botao: Largura, altura, posicao x, posicao y, cor (rgb - último número é transparência), conteudo, tamanho da fonte, se for circulo é false, cor fonte
    Botao botaoJogador1(306.f, 49.f, 174.f, 206.f, sf::Color(223, 232, 106, 0), jogador1, 15.f, false);
    botaoJogador1.criarBotoes();

    Botao botaoJogador2(306.f, 49.f, 174.f, 206.f, sf::Color(223, 232, 106, 0), jogador2, 15.f, false);
    botaoJogador2.criarBotoes();

    Botao botaoCadastro(220.f, 65.f, 140.f, 368.f, sf::Color(150, 129, 250), "Cadastro", 25.f, false, sf::Color(43, 0, 108));
    botaoCadastro.criarBotoes();

    Botao botaoListaJogadores(500.f, 65.f, 390.f, 368.f, sf::Color(150, 129, 250), "Lista de Jogadores", 25.f, false, sf::Color(43, 0, 108));
    botaoListaJogadores.criarBotoes();

    Botao botaoExcluirConta(350.f, 65.f, 140.f, 458.f, sf::Color(150, 129, 250), "Excluir Conta", 25.f, false, sf::Color(43, 0, 108));
    botaoExcluirConta.criarBotoes();

    Botao botaoEstatistica(350.f, 65.f, 540.f, 458.f, sf::Color(150, 129, 250), "Estatisticas", 25.f, false, sf::Color(43, 0, 108));
    botaoEstatistica.criarBotoes();

    window.clear();
    wallpaper.desenhar(window);
    botaoJogador1.desenhar(window);
    botaoJogador2.desenhar(window);
    botaoCadastro.desenhar(window);
    botaoListaJogadores.desenhar(window);
    botaoExcluirConta.desenhar(window);
    botaoEstatistica.desenhar(window);
    window.display();

}

int main()
{
<<<<<<< HEAD
    // Cria a janela com resolução de 800x600
    float res_x = 800.0f;
    float res_y = 600.0f;
    sf::RenderWindow window(sf::VideoMode(res_x, res_y), "Deluxe Edition");

    // Define uma variável de cor com valores RGB (vai de 0 a 255)
    sf::Color cor(255, 130, 190);

    // Cria um círculo com raio 50
    sf::CircleShape circulo(50.f);

    // Define a cor de preenchimento do círculo para azul
=======
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
    int windowPosY = 0; // Inicia no topo da tela

    // Criação da janela com a posição ajustada
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Deluxe Collection");
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));  // Define a posição da janela

    //---------------------------------------------------------------------------------------------//

    // Configurações iniciais de cor e forma
    sf::Color cor(255, 130, 190); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::CircleShape circulo(50.f);
>>>>>>> origin/campos
    circulo.setFillColor(sf::Color::Blue);

    // Define a posição inicial do círculo
    circulo.setPosition(0.0, 0.0);

    // Cria dois pontos com coordenadas diferentes
    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);
<<<<<<< HEAD

    // Cria um objeto Botao e configura suas propriedades
    Botao loginBox;
    loginBox.criarCampo(300, 50, "arial.ttf");
=======
>>>>>>> origin/campos
    
    // Cria um relógio para medir o tempo
    sf::Clock relogio;
<<<<<<< HEAD

    // Soma as coordenadas de dois pontos e armazena em um terceiro ponto
    PontoF pos3 = pos1 + pos2;

    // Cria outro botão com posição, tamanho e cor definidos
    Botao botao1(pos1, 5*10.0, 5*10.0, sf::Color::Red);
=======
    
    PontoF pos3 = pos1 + pos2;

    //cout << pos3 << endl;
>>>>>>> origin/campos

    // Cria um objeto Movimentacao para gerenciar o movimento
    Movimentacao movimentacao;

<<<<<<< HEAD
=======
    // Flag para controle dos menus
    bool menuInicial = true;
    // Flag para alternar entre os jogadores
    bool isEnteringPlayer1 = true;
    std::string jogador1;
    std::string jogador2;

>>>>>>> origin/campos
    // Roda o programa enquanto a janela estiver aberta
    while (window.isOpen())
    {
        // Checa todos os eventos que ocorreram desde a última iteração do loop
        sf::Event event;
        
        while (window.pollEvent(event)) //pollEvent é uma função que retorna true se houver eventos na fila
        {
<<<<<<< HEAD
            // Se o evento for de fechamento da janela, fecha a janela
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Verifica se o botão do mouse foi pressionado
            if (event.type == sf::Event::MouseButtonPressed) {

                // Simples verificação de clique no botão
                if (loginBox.getForma().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    loginBox.setFocado(true); // Foca no loginBox se clicado
                } else {
                    loginBox.setFocado(false); // Desfoca se clicado fora
                }
            }

            // Se loginBox está focado, recebe entrada de texto
            if (loginBox.isFocado) {
                loginBox.receberInput(event);
            }

            // Verifica se uma tecla foi pressionada
            if (event.type == sf::Event::KeyPressed) {
                movimentacao.mover(circulo, event.key.code);
            }
            if (event.type == sf::Event::KeyPressed) {
                movimentacao.mover(botao1.getForma(), event.key.code);
            }
            //Verifica se 0.5 segundo se passou
            if (relogio.getElapsedTime().asSeconds() >= 0.5f) {
                cout << "Centro: " << botao1.getCentro() << endl;
                cout << "Posicao: " << botao1.getPosicao()<< endl;
                cout << "Tamanho: " << botao1.tamX << " " << botao1.tamY << endl;
                relogio.restart(); // Reinicia o clock
            }

        }
        
        // Limpa a janela com a cor definida
        window.clear(cor);
        // Desenha os elementos na janela
        window.draw(loginBox.getForma());
        window.draw(loginBox.getTexto());
        window.draw(botao1.getForma());
        window.draw(circulo);

        // Atualiza a tela com o que foi desenhado
        window.display();
=======
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        // Se está no menuInicial
        if (menuInicial) {
        // Desenha o menu se a flag estiver ativa
        desenharMenu(window, jogador1, jogador2);
        } else {
            // Desenha o conteúdo do jogo
            window.clear();
            window.display();
            menuInicial = false;
            //window.draw(loginBox.getForma());
            //window.draw(loginBox.getTexto());
            //window.draw(botao1.getForma());
            //window.draw(circulo);
        }
>>>>>>> origin/campos
    }
    return 0;
}