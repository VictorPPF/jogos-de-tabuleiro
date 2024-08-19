#ifndef JOGOLIG4_HPP
#define JOGOLIG4_HPP
#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"
#include "../include/Jogador.hpp"
#include "../include/Jogo.hpp"
/**
 * @class JogoLig4
 * @brief Classe que representa o jogo Lig4
 * 
 * Essa classe herda da classe abstrata Jogo e implementa a lógica e funcionalidade de um jogo Lig4. 
 * Ela toma contados jogadores, do tabuleiro e de parte da interface gráfica. 
 */
class JogoLig4 : public Jogo {
private:
    /**
     * @
     */
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
    bool animando;

    Jogador jogador1, jogador2;

public:
    Botao botaoVoltar;
    bool fimDeJogo = false;
    sf::CircleShape circulo;
    Tabuleiro tabuleiroLIG4;
    int jogadorAtual;
    std::string nomeVencedor;

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
