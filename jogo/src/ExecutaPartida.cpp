#include "../include/ExecutaPartida.hpp"
#include <iostream>

// Implementação da classe Movimentacao

// Construtor
Movimentacao::Movimentacao() {
    // Inicialização dos atributos, se necessário
}


// Implementação do método mover
void Movimentacao::mover(sf::CircleShape &circle, const sf::Keyboard::Key &key) {
    float moveDistance = 5.0f; // Distância que o círculo se moverá a cada vez

    switch (key) {
        case sf::Keyboard::Right:
            circle.move(moveDistance, 0);
            break;
        case sf::Keyboard::Left:
            circle.move(-moveDistance, 0);
            break;
        case sf::Keyboard::Up:
            circle.move(0, -moveDistance);
            break;
        case sf::Keyboard::Down:
            circle.move(0, moveDistance);
            break;
        default:
            break;
    }
}

