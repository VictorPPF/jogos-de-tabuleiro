#ifndef EXECUTAPARTIDA_HPP
#define EXECUTAPARTIDA_HPP

#include <SFML/Graphics.hpp>
#include <vector>

// Classe Movimentacao
class Movimentacao {
public:
    // Construtor
    Movimentacao();

    // Método público para movimentação
    void mover(sf::CircleShape &circle, const sf::Keyboard::Key &key);

private:
    // Atributos privados podem ser adicionados aqui
};

// Outras classes podem ser declaradas aqui

#endif // EXECUTAPARTIDA_HPP