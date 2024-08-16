#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include <vector>
class Celula{
    private: 
        int estado; 
        int posicaoX, posicaoY;
        int _tamanho_celula;
    public: 
        Botao botao;
        Celula(int estado, int posicaoX, int posicaoY, int _tamanho_celula);
        void setEstado(int estado);
        int getEstado();
}; 

class Tabuleiro{
private:
    int qtd_celulaX, qtd_celulaY;  // Tamanho do tabuleiro
    int tamanho_celula; //Tamanho de cada celula em pixels
    int posicaoX, posicaoY;  // Posicao do tabuleiro
    std::vector<std::vector<Celula>> matriz; //Matriz responsavel pelo tabuleiro
    float origemX = 238.0;
    float origemY = 166.0;
public:
    // Construtor
    Tabuleiro(float origx, float origy, int qtd_celulaX, int qtd_celulaY, float tamanho_celula);
    
    //std::vector<std::vector<Botao>> * getMatriz();
    int get_celula_status(int linha, int coluna); 
    void set_celula_status(int linha, int coluna, int status);
    int get_qtd_celulaX();
    int get_qtd_celulaY(); 
    void desenhar(sf::RenderWindow& window);
};


#endif 