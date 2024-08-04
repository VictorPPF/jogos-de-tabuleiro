#include <SFML/Graphics.hpp>
#include "../include/ExecutaPartida.hpp"
#include <iostream>

using namespace std;


int main()
{
    float res_x = 800.0f;
    float res_y = 600.0f;
    sf::RenderWindow window(sf::VideoMode(res_x, res_y), "Deluxe Edition");
    sf::Color cor(255, 130, 190); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::CircleShape circulo(50.f);
    //cria uma variavel do tipo cor da cor azul
    float teste = 99.0;
    circulo.setFillColor(sf::Color::Blue);
    circulo.setPosition(0.0, 0.0);

    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);

    Botao loginBox;
    loginBox.criarCampo(300, 50, "arial.ttf");
    
    sf::Clock relogio;

    
    PontoF pos3 = pos1 + pos2;

    //cout << pos3 << endl;
    Botao botao1(pos1, 5*10.0, 5*10.0, sf::Color::Red);
    
    Movimentacao movimentacao;
    //roda o programa enquanto a janela estiver aberta
    while (window.isOpen())
    {
        // checa todos os eventos que ocorreram desde a última iteração do loop
        sf::Event event;
        
        while (window.pollEvent(event)) //pollEvent é uma função que retorna true se houver eventos na fila
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Obtenha a posição do mouse relativa à janela
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            // Verifique se o mouse está dentro do retângulo
            if (loginBox.getForma().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                //muda cor do retangulo
                loginBox.setCor(sf::Color::Cyan);
            }else {
                loginBox.setCor(sf::Color::White);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                // Simples verificação de clique no botão
                if (loginBox.getForma().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    loginBox.setFocado(true);
                } else {
                    loginBox.setFocado(false);
                }
            }
            

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
                relogio.restart(); // Reinicia o relogio
            }

        }
        
        window.clear(cor);
        window.draw(loginBox.getForma());
        window.draw(loginBox.getTexto());
        window.draw(botao1.getForma());
        window.draw(circulo);
        window.display();
    }

    return 0;
}