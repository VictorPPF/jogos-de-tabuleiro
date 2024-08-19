/**
 * @file JogoReversi.hpp
 * @brief Definição da classe Reversi que representa o jogo Reversi
 */
#ifndef JOGOREVERSI_HPP
#define JOGOREVERSI_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"
#include "../include/Jogo.hpp"

/**
 * @class JogoReversi
 * @brief Essa classe herda da classe abstrata Jogo e implementa a lógica e funcionalidade de um jogo Reversi. 
 * Ela toma contados jogadores, do tabuleiro e de parte da interface gráfica. 
 */

class JogoReversi : public Jogo {
private:
    /** 
     * @param jogador1: objeto que representa o jogador 1
     * @param jogador2: objeto que representa o jogador 2
    */
    Jogador jogador1, jogador2; 
    /**
     * @param jogadorAtual: indica qual jogador está na vez de jogar
     */
    int jogadorAtual; 
    /**
     * @param window: referência para a janela onde o jogo será desenhado
     */
    sf::RenderWindow& window; 
    /**
     * @param fonte: referência para a fonte usada no jogo
     */
    sf::Font& fonte;    
    /**
     * @param evento: referência para os eventos de entrada do jogador
     */
    sf::Event& evento; 
    /**
     * @param borda: margem para posicionar as peças dentro das células
     */
    float borda; 
    /**
     * @param origemX: posição X de origem do tabuleiro
     */
    float origemX; 
    /**
     * @param origemY: posição Y de origem do tabuleiro
     */
    float origemY;
    /**
     * @param qtd_celulaX: número de células na horizontal (colunas)
     */
    int qtd_celulaX; 
    /**
     * @param qtd_celulaY: número de células na vertical (linhas)
     */
    int qtd_celulaY; 
    /**
     * @param tamanho_celula: tamanho de cada célula no tabuleiro
     */
    float tamanho_celula; 

public:
    /**
     * @param tabuleiroREVERSI: objeto que representa o tabuleiro do jogo.
     *
     */
    Tabuleiro tabuleiroREVERSI; 
    /**
     * @param botaoVoltar: botão para desistir e voltar ao menu principal
     */
    Botao botaoVoltar; 
    /**
     * @param fimDeJogo: indica se o jogo terminou
     */
    bool fimDeJogo = false; 
    /**
     * @param nomeVencedor: nome do jogador vencedor
     */
    std::string nomeVencedor;
    /**
     * @param jogadorDesistiu: indica se um jogador desistiu
     */
    bool jogadorDesistiu;
    /**
     * @param num_pecas_jogador1: número de peças do jogador 1
     */
    int num_pecas_jogador1;
    /**
     * @param num_pecas_jogador2: número de peças do jogador 2
     */
    int num_pecas_jogador2;
    
    //Métodos herdados
    // construtor que inicializa os elementos do jogo
    /**
     * @brief Construtor da classe JogoReversi, recebe a janela, a fonte e os eventos do jogo e cria um jogo reversi.
     *
     */
    JogoReversi(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
    /**
     * @brief  Método contaPeca responsável por contar as peças de cada jogador
     * 
     */
    void contaPeca();
    /**
     * @brief  Método desenhaPeca responsável por desenhar as peças de cada jogador
     * @return void
     */
    void desenharJogo() override; 
    /**
     * @brief Método acao responsável por executar as ações relacionadas ao clique do jogador
     * @return void 
     */
    void acao() override;
    /**
     * @brief Método TemJogadasValidas responsável por verificar se um jogador tem jogadas válidas
     * @return bool 
     */
    bool TemJogadasValidas(int jogador);
    /**
     * @brief LimpaTabuleiro responsável por limpar o tabuleiro e preparar para um novo jogo.
     * @return void
     */
    void LimpaTabuleiro() override;
    /**
     * @brief setJogadores responsável por definir os jogadores do jogo.
     * @return void
     */
    void setJogadores(Jogador& _jogador1, Jogador& _jogador2) override;
    /**
     * @brief FazJogada responsável por realizar uma jogada no tabuleiro alterando as peças. 
     * @return bool
     */
    bool FazJogada(int x, int y) override;
    /**
     * @brief getNomeVencedor responsável por retornar o nome do jogador vencedor.
     * @return std::string
     */
    std::string getNomeVencedor() const override;
    /**
     * @brief verificaCondicaoVitoria responsável por verificar se o jogo terminou.
     * @return bool
     */
    bool verificaCondicaoVitoria();
    /**
     * @brief jogada_valida responsável por verificar se uma jogada é válida.
     * @return bool
     */
    bool jogada_valida(int x, int y, int jogador);
    /**
     * @brief VerificaJogadaDirecao responsável por verificar se uma jogada é válida em uma determinada direção.
     * @return bool
     */
    bool VerificaJogadaDirecao(int x, int y, int dx, int dy, int jogador);
    /**
     * @brief Ganhador responsável por calcular e retornar o jogador que venceu o jogo (ou empate).
     * @return int
     */
    int Ganhador();
    
};

#endif // JOGOREVERSI_HPP
