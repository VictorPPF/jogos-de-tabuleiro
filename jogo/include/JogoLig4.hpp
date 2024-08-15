#ifndef JOGOLIG4_HPP
#define JOGOLIG4_HPP
#include <SFML/Graphics.hpp>
#include "../include/ExecutaPartida.hpp"
class JogoLig4 {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
public:
    Botao botaoApelido;
    Botao botaoVoltar;
    JogoLig4(sf::RenderWindow& window, sf::Font& fonte);
    void desenharJogo();
};

#endif