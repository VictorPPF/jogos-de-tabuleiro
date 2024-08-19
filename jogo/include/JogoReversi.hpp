#ifndef JOGOREVERSI_HPP
#define JOGOREVERSI_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"

class JogoReversi {
private:
    Jogador jogador1, jogador2;
    int jogadorAtual; // indica qual jogador está na vez de jogar

    sf::RenderWindow& window; // referência para a janela onde o jogo será desenhado
    sf::Font& fonte;    // referência para a fonte usada no jogo
    sf::Event& evento; // referência para os eventos de entrada do jogador
    float borda; // margem para posicionar as peças dentro das células

    float origemX; // posição X de origem do tabuleiro
    float origemY; // posição Y de origem do tabuleiro
    int qtd_celulaX; // número de células na horizontal (colunas)
    int qtd_celulaY; // número de células na vertical (linhas)
    float tamanho_celula; // tamanho de cada célula no tabuleiro

public:
    
    void setJogadores(Jogador& _jogador1, Jogador& _jogador2);

    Tabuleiro tabuleiroREVERSI; // objeto que representa o tabuleiro do jogo
    Botao botaoVoltar; // botão para desistir e voltar ao menu principal
    bool fimDeJogo = false; // indica se o jogo terminou

    // construtor que inicializa os elementos do jogo
    JogoReversi(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
    // método para desenhar o estado atual do jogo na tela
    void desenharJogo();
    // método para limpar o tabuleiro e preparar para um novo jogo
    void LimpaTabuleiro();
    // verifica se uma jogada é válida em uma determinada direção
    bool VerificaJogadaDirecao(int x, int y, int dx, int dy, int jogador);
    // verifica se uma jogada em uma célula específica é válida
    bool jogada_valida(int x, int y, int jogador);
    // verifica se o jogo terminou
    bool condicao_vitoria();
    // calcula e retorna o jogador que venceu o jogo (ou empate)
    int Ganhador();
    // realiza a jogada e altera as peças do tabuleiro, se for válida
    bool FazJogada(int x, int y);
    // executa as ações relacionadas ao clique do jogador
    void acao();
};

#endif // JOGOREVERSI_HPP
