/**
 * @class Tabuleiro
 * @brief Classe que representa o tabuleiro do jogo
 * 
 * @details A classe Tabuleiro é responsável por criar e gerenciar o tabuleiro do jogo.
 * 
 */
#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <SFML/Graphics.hpp>
#include "../include/Interacao.hpp"
#include <vector>

class Celula{
    private: 
        /**
         * @param estado: estado da célula (0 = vazio, 1 = peça do jogador 1, 2 = peça do jogador 2)
         */
        int estado; 
        /**
         * @param posicaoX: posição X da célula
         * @param posicaoY: posição Y da célula
         */
        float posicaoX, posicaoY;
        /**
         * @param _tamanho_celula: tamanho da célula
         */
        float _tamanho_celula;
        /**
         * @param isCirculo: indica se a célula é um círculo
         */
        bool isCirculo;
        /**
         * @param cor: cor da célula
         */
        sf::Color cor;
        //Botao circulo;
        
    public: 
        /**
         * @param botao: implementa a forma das celulas do tabuleiro
         * @brief Construtor padrão da classe Celula
         */
        Botao botao;//sf::Color(150, 129, 250)
        Celula() : estado(0), posicaoX(0), posicaoY(0), _tamanho_celula(0),cor(sf::Color(0,0,0)), isCirculo(false), 
        botao(0, 0, 0, 0, sf::Color(150, 129, 250), false) {}
        /**
         * @brief Construtor da classe Celula
         */
        /**
         * @brief construtor da classe Celula que recebe parametros pra construir o botao
         */
        Celula(int estado, float posicaoX, float posicaoY, float _tamanho_celula,sf::Color cor, bool isCirculo);
        /**
         * @brief Método que define o estado da célula
         */
        void setEstado(int estado);
        /**
         * @brief Método que retorna o estado da célula
         */
        int getEstado();
}; 

/**
 * @class Tabuleiro
 * @brief Representa o tabuleiro do jogo, incluindo a matriz de células e as ações associadas.
 */
class Tabuleiro{
private:
    int qtd_celulaX, qtd_celulaY;  // Tamanho do tabuleiro
    int tamanho_celula; //Tamanho de cada celula em pixels
    float origemX;
    float origemY;
    float borda; //distancia entre a celula e o circulo
    
public:
    /**
     * @brief Construtor da classe Tabuleiro.
     * @param origx Coordenada X da origem do tabuleiro.
     * @param origy Coordenada Y da origem do tabuleiro.
     * @param qtd_celulaX Número de células na horizontal.
     * @param qtd_celulaY Número de células na vertical.
     * @param tamanho_celula Tamanho de cada célula em pixels.
     * @param borda Distância entre a célula e o círculo.
     * @param evento Referência ao evento SFML.
     */
    Tabuleiro(float origx, float origy, int qtd_celulaX, int qtd_celulaY, float tamanho_celula, float borda, sf::Event& evento);
    /**
     * @brief Construtor padrão da classe Tabuleiro.
     */
    Tabuleiro();

    /**
     * @brief Matriz responsável pelo tabuleiro.
     * Cada célula da matriz representa uma posição no tabuleiro.
     */
    std::vector<std::vector<Celula>> matriz;

    /**
     * @brief Matriz das bolinhas que mostram ao usuário onde ficarão as peças.
     * Esta matriz é usada para indicar visualmente as posições válidas para colocar peças.
     */
    std::vector<std::vector<Celula>> slots;
    /**
     * @param deuClique: indica se o jogador deu um clique
     */
    bool deuClique = false;
    /**
     * @param indice_i: índice da linha clicada
     */
    float indice_i = 0;
    /**
     * @param indice_j: índice da coluna clicada
     */
    float indice_j = 0;
    /**
     * @param jogadorAtual: jogador atual
     */
    int jogadorAtual = 0;
    /**
     * @param jocupado: índice da linha da primeira célula ocupada
     */
    float jocupado = 0;
    
    /**
     * @brief Método que retorna o estado de uma célula.    
     */
    int get_celula_status(int linha, int coluna);
    /**
     * @brief Método que define o estado de uma célula.
     */
    void set_celula_status(int linha, int coluna, int status);
    /**
     * @brief Método que retorna o número de células na horizontal.
     */
    int get_qtd_celulaX();
    /**
     * @brief Método que retorna o número de células na vertical.
     */
    int get_qtd_celulaY(); 
    /**
     * @brief Método que define qual celula tem que ocupada
     */
    void poePeca(int i, int j, int jogador);
    /**
     * @brief Método que coordena as ações do tabuleiro e como jogadas são feitas.
     */
    void acao();
    /**
     * @brief Método que coordena quando e como a animação da peça caindo é feita
     */
    void anima();
    /**
     *  @brief Método que desenha o tabuleiro na janela.
     */
    sf::Event& evento;
    void desenhar(sf::RenderWindow& window);
};


#endif 
