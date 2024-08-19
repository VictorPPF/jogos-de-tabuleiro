#ifndef JOGOLIG4_HPP
#define JOGOLIG4_HPP
#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"
#include "../include/Jogador.hpp"
#include "../include/Jogo.hpp"

class JogoLig4 : public Jogo {
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

    Jogador jogador1, jogador2;

public:
    void setJogadores(Jogador& _jogador1, Jogador& _jogador2);
    Botao botaoVoltar;
    bool fimDeJogo = false;
    sf::CircleShape circulo;
    Tabuleiro tabuleiroLIG4;
    int jogadorAtual;

    JogoLig4(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
    void desenharJogo() override;
    void acao () override;
    void poePeca(int i, int j, int jogador) override;
    void anima() override;
    bool verificaCondicaoVitoria(int jogador, int linha, int coluna) override;
    void LimpaTabuleiro() override;
};

#endif
