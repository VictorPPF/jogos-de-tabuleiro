#ifndef JOGOREVERSI_HPP
#define JOGOREVERSI_HPP
#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"

class JogoReversi {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
public:
    Botao botaoApelido; // Eu sei que isso vai criar o botão de apelido, mas não sei o que ele faz, manti para combinar com o Lig4
    Botao botaoVoltar;
    JogoReversi(sf::RenderWindow& window, sf::Font& fonte, Tabuleiro & tabuleiro );
    
    void desenharJogo();
};

#endif