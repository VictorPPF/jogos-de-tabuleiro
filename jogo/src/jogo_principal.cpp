#include <SFML/Graphics.hpp>
#include "../include/ExecutaPartida.hpp"
#include <iostream>

using namespace std;


int main()
{
    // Cria a janela com resolução de 800x600
    float res_x = 800.0f;
    float res_y = 600.0f;
    sf::RenderWindow window(sf::VideoMode(res_x, res_y), "Deluxe Edition");

    // Define uma variável de cor com valores RGB (vai de 0 a 255)
    sf::Color cor(255, 130, 190);

    // Cria um círculo com raio 50
    sf::CircleShape circulo(50.f);

    // Define a cor de preenchimento do círculo para azul
    circulo.setFillColor(sf::Color::Blue);

    // Define a posição inicial do círculo
    circulo.setPosition(0.0, 0.0);

    // Cria dois pontos com coordenadas diferentes
    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);

    // Cria um objeto Botao e configura suas propriedades
    Botao loginBox;
    loginBox.criarCampo(300, 50, "arial.ttf");
    
    // Cria um relógio para medir o tempo
    sf::Clock relogio;

    // Soma as coordenadas de dois pontos e armazena em um terceiro ponto
    PontoF pos3 = pos1 + pos2;

    // Cria outro botão com posição, tamanho e cor definidos
    Botao botao1(pos1, 5*10.0, 5*10.0, sf::Color::Red);

    // Cria um objeto Movimentacao para gerenciar o movimento
    Movimentacao movimentacao;

    // Roda o programa enquanto a janela estiver aberta
    while (window.isOpen())
    {
        // Checa todos os eventos que ocorreram desde a última iteração do loop
        sf::Event event;
        
        while (window.pollEvent(event)) //pollEvent é uma função que retorna true se houver eventos na fila
        {
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
    }

    return 0;
}