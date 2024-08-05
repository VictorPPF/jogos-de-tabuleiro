#include "../include/ExecutaPartida.hpp"
#include <iostream>


// Implementação da classe Movimentacao

// Construtor
Movimentacao::Movimentacao() {
    // Inicialização dos atributos, se necessário
}


// Implementação do método mover
void Movimentacao::mover(sf::CircleShape &circulo, const sf::Keyboard::Key &TECLA) {
    float velocidade = 5.0f; // Distância que o círculo se moverá a cada vez

    switch (TECLA) {
        case sf::Keyboard::Right:
            circulo.move(velocidade, 0);
            break;
        case sf::Keyboard::Left:
            circulo.move(-velocidade, 0);
            break;
        case sf::Keyboard::Up:
            circulo.move(0, -velocidade);
            break;
        case sf::Keyboard::Down:
            circulo.move(0, velocidade);
            break;
        default:
            break;
    }
}
void Movimentacao::mover(sf::RectangleShape &retangulo, const sf::Keyboard::Key &TECLA) {
    float velocidade = 1.0f; // Distância que o círculo se moverá a cada vez

    switch (TECLA) {
        case sf::Keyboard::Key::D:
            retangulo.move(velocidade, 0);
            break;
        case sf::Keyboard::Key::A:
            retangulo.move(-velocidade, 0);
            break;
        case sf::Keyboard::Key::W:
            retangulo.move(0, -velocidade);
            break;
        case sf::Keyboard::Key::S:
            retangulo.move(0, velocidade);
            break;
        default:
            break;
    }
}


// Implementação da classe Botao






