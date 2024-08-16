#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include <vector>

// class Tabuleiro : public Botao {
// private:
//     int qtd_celulaX, qtd_celulaY;  // Tamanho do tabuleiro
//     int tamanho_celula; //Tamanho de cada celula em pixels
//     int posicaoX, posicaoY;  // Posicao do tabuleiro
//     std::vector<std::vector<int>> matriz; //Matriz responsavel pelo tabuleiro
// public:
//     // Construtor
//     Tabuleiro();

//     // Método para desenhar o tabuleiro
//     void desenhar(sf::RenderWindow& window);

//     // Método para desenhar as peças no tabuleiro
//     void desenhar_pecas();

// };

class Tabuleiro : public Botao {
private:
    int qtd_celulaX, qtd_celulaY;  // Tamanho do tabuleiro
    int tamanho_celula; //Tamanho de cada celula em pixels
    int posicaoX, posicaoY;  // Posicao do tabuleiro
    std::vector<std::vector<Botao>> matriz; //Matriz responsavel pelo tabuleiro
public:
    // Construtor
    Tabuleiro();

    // Método para desenhar o tabuleiro
    void desenhar(sf::RenderWindow& window);

    // Método para desenhar as peças no tabuleiro
    void desenhar_pecas();

};

#endif 
