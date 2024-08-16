#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include <vector>

class Celula{
    private: 
        int estado; 
        float posicaoX, posicaoY;
        float _tamanho_celula;
    public: 
        Botao botao;
        Celula() : estado(0), posicaoX(0), posicaoY(0), _tamanho_celula(0), botao(0, 0, 0, 0, sf::Color(150, 129, 250), false) {}
        Celula(int estado, float posicaoX, float posicaoY, float _tamanho_celula);
        void setEstado(int estado);
        int getEstado();
}; 

class Tabuleiro{
private:
    int qtd_celulaX, qtd_celulaY;  // Tamanho do tabuleiro
    int tamanho_celula; //Tamanho de cada celula em pixels
    //int posicaoX, posicaoY;  // Posicao do tabuleiro
    std::vector<std::vector<Celula>> matriz; //Matriz responsavel pelo tabuleiro
    float origemX;
    float origemY;
public:
    // Construtor
    Tabuleiro(float origx, float origy, int qtd_celulaX, int qtd_celulaY, float tamanho_celula);
    Tabuleiro();
    //std::vector<std::vector<Botao>> * getMatriz();
    int get_celula_status(int linha, int coluna); 
    void set_celula_status(int linha, int coluna, int status);
    int get_qtd_celulaX();
    int get_qtd_celulaY(); 
    void desenhar(sf::RenderWindow& window);
};


#endif 
