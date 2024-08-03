#include <SFML/Graphics.hpp>
#include "../include/ExecutaPartida.hpp"
#include <iostream>

using namespace Math;
using namespace std;


int main()
{
    float res_x = 800.0f;
    float res_y = 600.0f;
    sf::Color cor(255, 170, 203); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::RenderWindow window(sf::VideoMode(res_x, res_y), "Deluxe Edition");
    sf::CircleShape shape(50.f);
    //cria uma variavel do tipo cor da cor azul
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(0.0, 0.0);

    PontoF pos1(2.0,3.0);
    PontoF pos2(3.0,4.0);
    PontoF pos3 = pos1 + pos2;

    cout << pos3 << endl;


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

            // Verifica se uma tecla foi pressionada
            if (event.type == sf::Event::KeyPressed) {
                movimentacao.mover(shape, event.key.code);
            }

            
        }

        window.clear(cor);
        window.draw(shape);
        window.display();
    }

    return 0;
}