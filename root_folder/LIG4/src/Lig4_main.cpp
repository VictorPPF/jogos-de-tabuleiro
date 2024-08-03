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
    float winWidth = 800.0f;
    float winHeight = 600.0f;
    sf::Color cor(255, 170, 203);
    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Deluxe Edition");
    sf::CircleShape shape(50.f);
    //cria uma variavel do tipo cor da cor azul
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(0.0, 0.0);

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