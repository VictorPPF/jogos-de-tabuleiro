#ifndef JOGOREVERSI_HPP
#define JOGOREVERSI_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"
#include "../include/Jogo.hpp"

class JogoReversi : public Jogo {
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
    Tabuleiro tabuleiroREVERSI; // objeto que representa o tabuleiro do jogo
    Botao botaoVoltar; // botão para desistir e voltar ao menu principal
    bool fimDeJogo = false; // indica se o jogo terminou
    std::string nomeVencedor;
    
    //Métodos herdados
    // construtor que inicializa os elementos do jogo
    JogoReversi(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
    // método para desenhar o estado atual do jogo na tela
    void desenharJogo() override;
    // executa as ações relacionadas ao clique do jogador
    void acao() override;
    // método para limpar o tabuleiro e preparar para um novo jogo
    void LimpaTabuleiro() override;
    void setJogadores(Jogador& _jogador1, Jogador& _jogador2) override;
    // realiza a jogada e altera as peças do tabuleiro, se for válida
    bool FazJogada(int x, int y) override;
    std::string getNomeVencedor() const override;
    // verifica se o jogo terminou
    bool verificaCondicaoVitoria();
    

    // verifica se uma jogada em uma célula específica é válida
    bool jogada_valida(int x, int y, int jogador);
    // verifica se uma jogada é válida em uma determinada direção
    bool VerificaJogadaDirecao(int x, int y, int dx, int dy, int jogador);
    // calcula e retorna o jogador que venceu o jogo (ou empate)
    int Ganhador();
 
    
};

#endif // JOGOREVERSI_HPP
