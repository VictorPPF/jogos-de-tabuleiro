#include <SFML/Graphics.hpp>
#include "ExecutaPartida.hpp"

// void moveCircle(sf::CircleShape &circle, const sf::Keyboard::Key &key) {
//     float moveDistance = 1.0f; // Distância que o círculo se moverá a cada vez

//     switch (key) {
//         case sf::Keyboard::Right:
//             circle.move(moveDistance, 0);
//             break;
//         case sf::Keyboard::Left:
//             circle.move(-moveDistance, 0);
//             break;
//         case sf::Keyboard::Up:
//             circle.move(0, -moveDistance);
//             break;
//         case sf::Keyboard::Down:
//             circle.move(0, moveDistance);
//             break;
//         default:
//             break;
//     }
// }



int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(0.0, 0.0);

    Movimentacao movimentacao;

    while (window.isOpen())
    {
        sf::Event event;
        //função move circulo right,left,up and down com switch case

        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Verifica se uma tecla foi pressionada
            if (event.type == sf::Event::KeyPressed) {
                movimentacao.mover(shape, event.key.code);
            }

            
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}