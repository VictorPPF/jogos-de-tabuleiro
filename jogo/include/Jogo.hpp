#ifndef JOGO_HPP
#define JOGO_HPP

#include <string>
#include "Jogador.hpp"

// Classe abstrata Jogo
class Jogo {
protected:
    Jogador* player1; // Ponteiro para o jogador1
    Jogador* player2; // Ponteiro para o jogador2
    int status;       // Status do jogo
    std::string jogador_atual;
    std::string jogo_atual;

public:
    // Construtor
    Jogo(Jogador* jogador1, Jogador* jogador2, std::string jogo_escolhido) : player1(jogador1), player2(jogador2), status(0), jogador_atual(player1->getApelido()), jogo_atual(jogo_escolhido) {}
    Jogo():player1(nullptr), player2(nullptr),status(-1), jogador_atual("-1"), jogo_atual("-1"){};

    // Destrutor virtual
    virtual ~Jogo() {}

    // Métodos abstratos que devem ser implementados pelas classes derivadas
    virtual bool condicao_vitoria() const = 0; // Verifica a condição de vitória
    virtual bool jogada_valida(int x, int y, int jogador) const = 0;    // Verifica se a jogada é válida

    // Métodos acessores
    std::string get_jogador_atual() const { return jogador_atual; }
    bool get_status() const { return status; }

    // Método para alterar o status
    void set_status(bool novo_status) { status = novo_status; }
};

#endif