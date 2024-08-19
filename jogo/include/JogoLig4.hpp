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
    float origemX; //posição X de origem do tabuleiro
    float origemY;  //posição Y de origem do tabuleiro
    int qtd_celulaX; //colunas
    int qtd_celulaY; //linhas
    float tamanho_celula; //tamanho de cada célula no tabuleiro
    float borda; //margem para posicionar as peças dentro das células
    float icupado, jocupado; //indices da celula ocupada
    bool animando; //indica se a peça está em movimento

    Jogador jogador1, jogador2;

public:
    Botao botaoVoltar; //botão para desistir e voltar ao menu principal
    bool fimDeJogo = false; //indica se o jogo terminou
    sf::CircleShape circulo; //peça temporária que se move
    Tabuleiro tabuleiroLIG4;   //objeto que representa o tabuleiro do jogo
    int jogadorAtual;   //indica qual jogador está na vez de jogar
    std::string nomeVencedor;   //nome do jogador vencedor

    //Métodos herdados
    JogoLig4(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
    void desenharJogo() override;
    void acao () override;
    void LimpaTabuleiro() override;
    void setJogadores(Jogador& _jogador1, Jogador& _jogador2) override;
    bool FazJogada(int i, int j) override;
    std::string getNomeVencedor() const override;

    bool verificaCondicaoVitoria(int linha, int coluna);
    void anima();
};


#endif
