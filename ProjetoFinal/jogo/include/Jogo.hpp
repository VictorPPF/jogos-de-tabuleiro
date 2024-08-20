/**
 * @file Jogo.hpp
 * @brief Definição da classe abstrata Jogo que representa um jogo.
 * 
 */
#ifndef JOGO_HPP
#define JOGO_HPP
#include <string>
#include "Jogador.hpp"

// Classe abstrata Jogo
class Jogo {
public:

    /**
     * Método abstrato para desenhar o jogo na tela.
     */
    virtual void desenharJogo() = 0;

    /**
     * Método abstrato responsável por lidar com as ações dos jogadores.
     */
    virtual void acao() = 0;

    /**
     * Método abstrato para limpar o tabueleiro e resetar as configurações.
     */
    virtual void LimpaTabuleiro() = 0;

    /**
     * Método abstrato para indicar os jogadores que irão jogar o jogo.
     */
    virtual void setJogadores (Jogador& player1, Jogador& player2) = 0;

    /**
     * Método abstrato que lida com a jogada válida.
     */
    virtual bool FazJogada (int i, int j) = 0;

    /**
     * Método abstrato para retornar quem venceu nos jogos.
     */
    virtual std::string getNomeVencedor() const = 0;
    
};


#endif
