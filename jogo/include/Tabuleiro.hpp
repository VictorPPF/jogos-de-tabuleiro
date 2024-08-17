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
        bool isCirculo;
        sf::Color cor;
        //Botao circulo;
        
    public: 
        Botao botao;//sf::Color(150, 129, 250)
        Celula() : estado(0), posicaoX(0), posicaoY(0), _tamanho_celula(0),cor(sf::Color(0,0,0)), isCirculo(false), 
        botao(0, 0, 0, 0, sf::Color(150, 129, 250), false) {}
        Celula(int estado, float posicaoX, float posicaoY, float _tamanho_celula,sf::Color cor, bool isCirculo);
        void setEstado(int estado);
        int getEstado();
}; 

class Tabuleiro{
private:
    int qtd_celulaX, qtd_celulaY;  // Tamanho do tabuleiro
    int tamanho_celula; //Tamanho de cada celula em pixels
    //int posicaoX, posicaoY;  // Posicao do tabuleiro
    
    float origemX;
    float origemY;
    float borda; //distancia entre a celula e o circulo
    
public:
    // Construtor
    Tabuleiro(float origx, float origy, int qtd_celulaX, int qtd_celulaY, float tamanho_celula, float borda, sf::Event& evento);
    Tabuleiro();
    std::vector<std::vector<Celula>> matriz; //Matriz responsavel pelo tabuleiro
    std::vector<std::vector<Celula>> slots; //Matriz das bolinhas que mostram pro usuario onde ficarão as peças
    //std::vector<std::vector<Botao>> * getMatriz();
    bool deuClique = false;
    float indice_i = 0;
    float indice_j = 0;
    int jogadorAtual = 0;
    float jocupado = 0;
    
    int get_celula_status(int linha, int coluna); 
    void set_celula_status(int linha, int coluna, int status);
    int get_qtd_celulaX();
    int get_qtd_celulaY(); 
    void poePeca(int i, int j, int jogador);
    void acao();
    void anima();
    sf::Event& evento;
    void desenhar(sf::RenderWindow& window);
};


#endif 
