#ifndef JOGO_HPP
#define JOGO_HPP

#include <string>
#include "Jogador.hpp"

// Classe abstrata Jogo
class Jogo {
public:

    // Métodos abstratos que devem ser implementados pelas classes derivadas
    virtual void acao() = 0;
    virtual void poePeca(int x, int y, int jogador) = 0;
    virtual void anima() = 0;
    virtual bool verificaCondicaoVitoria(int jogador, int linha, int coluna ) = 0; // Verifica a condição de vitória
    virtual void LimpaTabuleiro() = 0;
    virtual void desenharJogo() = 0;
    //virtual bool jogada_valida(int x, int y, int jogador) = 0;    // Verifica se a jogada é válida

    // Métodos acessores
    //std::string get_jogador_atual() { return jogador_atual; }
    //void set_jogo_atual( std::string& jogo) { jogo_atual = jogo; }
};


#endif
