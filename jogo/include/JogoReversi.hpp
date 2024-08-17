#ifndef JOGOREVERSI_HPP
#define JOGOREVERSI_HPP

#include "Jogo.hpp" // Inclui o cabeçalho da classe Jogo
#include "Tabuleiro.hpp" // Inclui o cabeçalho da classe Tabuleiro
#include "Jogador.hpp" // Inclui o cabeçalho da classe Jogador

class JogoReversi : public Jogo {
public:
    JogoReversi(sf::RenderWindow& window, sf::Font& fonte,int tamanhoTabuleiro, std::string apelido_a, std::string apelido_b); // Construtor
    ~JogoReversi(); // Destrutor

    // Métodos públicos
    void iniciarJogo();
    void realizarJogada(int linha, int coluna);
    bool verificarJogadaValida(int linha, int coluna);
    bool condicao_vitoria(); 
    void desenharJogo();

private:
    // Atributos privados
    Tabuleiro tabuleiro;
    Jogador* jogador1;
    Jogador* jogador2;
    Jogador* jogadorAtual;
    sf::RenderWindow& window; 
    sf::Font& fonte;
    Botao botaoApelido;
    Botao botaoVoltar;
};

#endif // JOGOREVERSI_HPP