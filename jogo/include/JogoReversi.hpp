#ifndef JOGOREVERSI_HPP
#define JOGOREVERSI_HPP

#include "Jogo.hpp" // Inclui o cabeçalho da classe Jogo
#include "Tabuleiro.hpp" // Inclui o cabeçalho da classe Tabuleiro
#include "Jogador.hpp" // Inclui o cabeçalho da classe Jogador

class JogoReversi : public Jogo {
private:

    // Atributos privados
    Jogador* jogador1;
    Jogador* jogador2;
    int jogadorAtual;

    sf::RenderWindow& window; 
    sf::Font& fonte;
    sf::Event& evento;
    float borda;

    float origemX;
    float origemY;
    int qtd_celulaX; //colunas
    int qtd_celulaY; //linhas
    float tamanho_celula;
    float icupado, jocupado; //indices da celula ocupada
    
public:
    Tabuleiro tabuleiroREVERSI;
    Botao botaoVoltar;
    bool fimDeJogo = false;
    sf::CircleShape circulo;
    
    JogoReversi(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento, std::string apelido_a, std::string apelido_b); // Construtor
    ~JogoReversi(); // Destrutor

    // Métodos públicos
    //void iniciarJogo();
    void desenharJogo();
    void anima();
    void LimpaTabuleiro();

    bool VerificaJogadaDirecao(int x, int y, int dx, int dy, int jogador);
    bool VerificaJogada( int x, int y, int jogador);
    bool FazJogada(int x, int y);
    
    bool condicaoDeVitoria();
    int Ganhador();
    bool FazJogada( int x, int y); 

    //void poePeca(int i, int j, int jogador);
    void acao ();

};

#endif // JOGOREVERSI_HPP