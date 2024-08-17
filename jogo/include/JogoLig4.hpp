#ifndef JOGOLIG4_HPP
#define JOGOLIG4_HPP
#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"

class JogoLig4 {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
    sf::Event& evento;
    float origemX;
    float origemY;
    int qtd_celulaX; //colunas
    int qtd_celulaY; //linhas
    float tamanho_celula;
    float borda;
    float icupado, jocupado; //indices da celula ocupada

public:
    Botao botaoVoltar;
    bool fimDeJogo = false;
    sf::CircleShape circulo;
    Tabuleiro tabuleiroLIG4;
    JogoLig4(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
    void desenharJogo();
    void acao ();
    void poePeca(int i, int j, int jogador);
    int jogadorAtual;
    void anima();
    bool verificaCondicaoVitoria(int jogador, int linha, int coluna);
    void LimpaTabuleiro();
};

#endif
