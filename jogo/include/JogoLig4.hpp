#ifndef JOGOLIG4_HPP
#define JOGOLIG4_HPP
#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"

class JogoLig4 {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
    float origemX;
    float origemY;
    int qtd_celulaX; //colunas
    int qtd_celulaY; //linhas
    float tamanho_celula;

public:
    Botao botaoApelido;
    Botao botaoVoltar;
    Tabuleiro tabuleiroLIG4;
    
    JogoLig4(sf::RenderWindow& window, sf::Font& fonte);
    void desenharJogo();
};

#endif