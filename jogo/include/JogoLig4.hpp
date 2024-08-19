/**
 * @file JogoLig4.hpp
 * @brief Classe que representa o jogo Lig4
 */

#ifndef JOGOLIG4_HPP
#define JOGOLIG4_HPP
#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include "../include/Tabuleiro.hpp"
#include "../include/Jogador.hpp"
#include "../include/Jogo.hpp"

/**
 * @class JogoLig4
 * @brief classe herda da classe abstrata Jogo e implementa a lógica e funcionalidade de um jogo Lig4. 
 * 
 * Ela toma contados jogadores, do tabuleiro e de parte da interface gráfica. 
 */
class JogoLig4 : public Jogo {
private:
    /**
     * @param window referência para a janela onde o jogo será desenhado
     */
    sf::RenderWindow& window; 
    /**
     * @param fonte referência para a fonte usada no jogo
     */
    sf::Font& fonte;
    /**
     * @param evento referência para os eventos de entrada do jogador
     */
    sf::Event& evento;
    /**
     * @param origemX posição X de origem do tabuleiro
     */
    float origemX;
    /**
     * @param origemY posição Y de origem do tabuleiro
     */
    float origemY;
    /**
     * @param qtd_celulaX número de células na horizontal (colunas)
     */
    int qtd_celulaX; 
    /**
     * @param qtd_celulaY número de células na vertical (linhas)
     */
    int qtd_celulaY; 
    /**
     * @param tamanho_celula tamanho de cada célula no tabuleiro
     */
    float tamanho_celula;
    /**
     * @param borda margem para posicionar as peças dentro das células
     */
    float borda;
    /**
     * @param icupado índice da célula ocupada
     * @param jocupado índice da célula ocupada
     */
    float icupado, jocupado; 
    /**
     * @param animando indica se o jogo está animando
     */
    bool animando;
    /**
     * @param jogador1 objeto que representa o jogador 1
     * @param jogador2 objeto que representa o jogador 2
     */
    Jogador jogador1, jogador2;

public:
    /**
     * @param botaoVoltar botão para voltar ao menu
     */
    Botao botaoVoltar;
    /**
     * @param fimDeJogo indica se o jogo acabou
     */
    bool fimDeJogo = false;
    /**
     * @param circulo círculo que representa a peça do jogador atual
     */
    sf::CircleShape circulo;
    /**
     * @param tabuleiroLIG4 objeto que representa o tabuleiro do jogo
     */
    Tabuleiro tabuleiroLIG4;
    /**
     * @param jogadorAtual indica qual jogador está na vez de jogar
     */
    int jogadorAtual;
    /**
     * @param nomeVencedor nome do jogador vencedor
     */
    std::string nomeVencedor;

    //Métodos herdados
    /**
     * @brief Construtor que inicializa os elementos do jogo recebe a janela, a fonte e o evento como paraâmetros
     */
    JogoLig4(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
    /**
     * @brief desenharJogo desenha o jogo na janela
     * @return void
     */
    void desenharJogo() override;
    /**
     * @brief acao executa a ação do jogo
     * @return void 
     */
    void acao () override;
    /**
     * @brief LimpaTabuleiro limpa o tabuleiro
     * @return void
     */
    void LimpaTabuleiro() override;
    /**
     * @brief setJogadores responsável por definir os jogadores do jogo
     * @param _jogador1 objeto que representa o jogador 1
     * @param _jogador2 objeto que representa o jogador 2
     * @return void
     */
    void setJogadores(Jogador& _jogador1, Jogador& _jogador2) override;
    /**
     * @brief FazJogada responsável por fazer a jogada
     * @param i linha
     * @param j coluna
     * @return bool
     */
    bool FazJogada(int i, int j) override;
    /**
     * @brief getNomeVencedor retorna o nome do vencedor
     * @return std::string
     */
    std::string getNomeVencedor() const override;
    /**
     * @brief verificaCondicaoVitoria verifica se a condição de vitória foi atingida
     * @param linha linha
     * @param coluna coluna
     * @return bool
     */
    bool verificaCondicaoVitoria(int linha, int coluna);
    /**
     * @brief anima é responsável por animar a peça
     * @return void
     */
    void anima();
};


#endif
