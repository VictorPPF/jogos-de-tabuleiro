#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include <vector>


class Tabuleiro : public Botao {
private:
    int qtd_celulaX, qtd_celulaY;  // Tamanho do tabuleiro
    int tamanho_celula; //Tamanho de cada celula em pixels
    int origemX;
    int origemY; 
    std::vector<std::vector<Botao>> matriz; //Matriz responsavel pelo tabuleiro
public:
    // Construtor
    Tabuleiro(float origx, float origy, int qtd_celulaX, int qtd_celulaY, float tamanho_celula);
    float origemX = 238.0;
    float origemY = 166.0;
    std::vector<std::vector<Botao>> * getMatriz();
    // Método para desenhar o tabuleiro
    void desenhar(sf::RenderWindow& window);


};


#endif 