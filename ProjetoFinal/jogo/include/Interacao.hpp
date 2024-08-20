/**
 * @file Interacao.hpp
 * @brief Definição das classes Ponto e Botao para representar pontos no plano cartesiano e botões na interface gráfica.
 */

#ifndef INTERACAO_HPP
#define INTERACAO_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
#include "../include/Wallpaper.hpp"

/**
 * @class Ponto
 * @brief Representa um ponto no plano cartesiano.
 * 
 * Esta classe template permite a criação de pontos com diferentes tipos numéricos (double, float, int, unsigned int).
 * Fornece operadores sobrecarregados para operações aritméticas e comparação entre pontos.
 * 
 * @tparam T Tipo numérico para coordenadas do ponto.
 */
template <typename T>
class Ponto {
public:
    T x, y; ///< Coordenada x, y do ponto.
    /**
     * @brief Construtor parametrizado.
     * 
     * @param x Coordenada x do ponto.
     * @param y Coordenada y do ponto.
     */
    Ponto(T x, T y) : x(x), y(y) {}
    /**
     * @brief Construtor padrão.
     * Cria um ponto na origem (0,0).
     */
    Ponto() : x(0), y(0) {}
    /**
     * @brief Operador de atribuição.
     * 
     * @param outro Outro ponto a ser copiado.
     */    
    void operator=(const Ponto& outro) {
        x = outro.x;
        y = outro.y;
    }
     /**
     * @brief Operador de adição composta.
     * 
     * @param outro Ponto a ser adicionado.
     */
    void operator+=(const Ponto& outro) {
        x += outro.x;
        y += outro.y;
    }
    /**
     * @brief Operador de subtração composta.
     * 
     * @param outro Ponto a ser subtraído.
     */
    void operator-=(const Ponto& outro) {
        x -= outro.x;
        y -= outro.y;
    }
    /**
     * @brief Operador de multiplicação composta por um escalar.
     * 
     * @param escalar Valor pelo qual as coordenadas são multiplicadas.
     */
    void operator*=(double escalar) {
        x = x * escalar;
        y = y * escalar;
    }
    /**
     * @brief Operador de divisão composta por um escalar.
     * 
     * @param escalar Valor pelo qual as coordenadas são divididas.
     * @throw std::runtime_error Se o escalar for zero.
     */
    void operator/=(double escalar) {
        if (escalar == 0) {
            throw std::runtime_error("ERRO: calma la amigao! divisao por zero.");
        }
        x /= escalar;
        y /= escalar;
    }
    /**
     * @brief Operador de adição.
     * 
     * @param outro Ponto a ser adicionado.
     * @return Novo ponto resultante da adição.
     */
    Ponto operator+(const Ponto& outro) const {
        return Ponto(x + outro.x, y + outro.y);
    }
    /**
     * @brief Operador de subtração.
     * 
     * @param outro Ponto a ser subtraído.
     * @return Novo ponto resultante da subtração.
     */
    Ponto operator-(const Ponto& outro) const {
        return Ponto(x - outro.x, y - outro.y);
    }
    /**
     * @brief Operador de multiplicação.
     * 
     * @param outro Ponto cujas coordenadas são multiplicadas.
     * @return Novo ponto resultante da multiplicação.
     */
    Ponto operator*(const Ponto& outro) const {
        return Ponto(x * outro.x, y * outro.y);
    }
    /**
     * @brief Operador de multiplicação por um escalar.
     * 
     * @param escalar Valor pelo qual as coordenadas são multiplicadas.
     * @return Novo ponto resultante da multiplicação.
     */
    Ponto operator*(double escalar) const {
        return Ponto(x * escalar, y * escalar);
    }
    /**
     * @brief Operador de divisão.
     * 
     * @param outro Ponto cujas coordenadas são divididas.
     * @return Novo ponto resultante da divisão.
     * @throw std::runtime_error Se qualquer coordenada do ponto for zero.
     */
    Ponto operator/(const Ponto& outro) const {
        if (outro.x == 0 || outro.y == 0) {
            throw std::runtime_error("ERRO: calma la amigao! divisao por zero.");
        }
        return Ponto(x / outro.x, y / outro.y);
    }
    /**
     * @brief Operador de divisão por um escalar.
     * 
     * @param escalar Valor pelo qual as coordenadas são divididas.
     * @return Novo ponto resultante da divisão.
     * @throw std::runtime_error Se o escalar for zero.
     */
    Ponto operator/(double escalar) const {
        if (escalar == 0) {
            throw std::runtime_error("ERRO: calma la amigao! divisao por zero.");
        }
        return Ponto(x / escalar, y / escalar);
    }
    /**
     * @brief Operador de igualdade.
     * 
     * @param outro Ponto a ser comparado.
     * @return True se os pontos forem iguais, false caso contrário.
     */
    bool operator==(const Ponto& outro) const {
        return x == outro.x && y == outro.y;
    }
    /**
     * @brief Operador de fluxo de saída.
     * 
     * @param os Fluxo de saída.
     * @param ponto Ponto a ser impresso.
     * @return Fluxo de saída com o ponto formatado.
     */
    friend std::ostream& operator<<(std::ostream& os, const Ponto& ponto) {
        os << "[" << ponto.x << ", " << ponto.y << "]"; //imprime o ponto no formato [x,y]
        return os;
    }
};

// Instanciação explícita dos templates
template class Ponto<double>; 
template class Ponto<float>;
template class Ponto<int>;
template class Ponto<unsigned int>;

// Definição dos typedefs
typedef Ponto<double> PontoD; ///< Tipo para ponto com coordenadas double.
typedef Ponto<float> PontoF; ///< Tipo para ponto com coordenadas float.
typedef Ponto<int> PontoI; ///< Tipo para ponto com coordenadas int.
typedef Ponto<unsigned int> PontoU; ///< Tipo para ponto com coordenadas int.

/**
 * @class Botao
 * @brief Representa um botão na interface gráfica.
 * 
 * Esta classe fornece métodos para criar e manipular botões, incluindo definição de tamanho, posição, cor e forma.
 */
class Botao {
protected:
    // Atributos para definir as dimensões e posição do botão
    float largura;           ///< Largura do botão.
    float altura;            ///< Altura do botão.
    sf::Vector2f posicao;    ///< Posição do botão na janela (x, y).
    
    // Atributos para definir as cores do botão
    sf::Color cor;           ///< Cor original do botão.
    sf::Color corHover;      ///< Cor do botão quando o mouse está sobre ele.
    
    // Atributos para definir a forma do botão
    sf::RectangleShape retangulo; ///< Forma retangular do botão.
    sf::CircleShape circulo;       ///< Forma circular do botão.
    bool isCirculo;                ///< Indica se o botão é circular.
    
    // Atributos para o texto do botão
    std::string texto;     ///< Texto exibido no botão.
    sf::Font fonte;        ///< Fonte do texto.
    sf::Text text;         ///< Texto SFML para desenhar o texto no botão.
    sf::Color corFonte;    ///< Cor da fonte.
    float tamanhoFonte;    ///< Tamanho da fonte do texto do botão.
    int windowLargura = 1000; ///< Largura da janela.
    int windowAltura = 690; ///< Altura da janela.

public:
    /**
     * @brief Construtor da classe Botao.
     * 
     * @param largura Largura do botão.
     * @param altura Altura do botão.
     * @param x Posição x do botão na janela.
     * @param y Posição y do botão na janela.
     * @param cor Cor original do botão.
     * @param texto Texto exibido no botão.
     * @param tamanhoFonte Tamanho da fonte do texto.
     * @param isCirculo Indica se o botão deve ser circular.
     * @param corFonte Cor da fonte do texto.
     */

    // Construtor da classe Botao
    Botao(float largura, float altura, float x, float y, sf::Color cor, const std::string& texto, float tamanhoFonte = 24.f,
        bool isCirculo = false, sf::Color corFonte = sf::Color::White);
    /**
     * @brief Construtor padrão da classe Botao.
     */

    Botao() = default;

    /**
     * @brief Construtor da classe Botao para células do tabuleiro.
     * 
     * @param largura Largura do botão.
     * @param altura Altura do botão.
     * @param x Posição x do botão na janela.
     * @param y Posição y do botão na janela.
     * @param cor Cor original do botão.
     * @param isCirculo Indica se o botão deve ser circular.
     */

    Botao(float largura, float altura, float x, float y, sf::Color cor, bool isCirculo = false);

    /**
     * @brief Cria a forma do botão (retângulo ou círculo).
     */
    void criarBotoes();

    /**
     * @brief Obtém a cor original do botão.
     * 
     * @return Cor original do botão.
     */
    sf::Color getCor() const;

    /**
     * @brief Obtém a forma retangular do botão.
     * 
     * @return Forma retangular do botão.
     */
    sf::RectangleShape getRetangulo() const;

    /**
     * @brief Obtém a forma circular do botão.
     * 
     * @return Forma circular do botão.
     */
    sf::CircleShape getCirculo() const;

    /**
     * @brief Define a cor do botão quando o mouse está sobre ele.
     * 
     * @param cor Cor a ser definida.
     */
    void setCorHover(sf::Color cor);

    /**
     * @brief Define a cor original do botão.
     * 
     * @param cor Cor a ser definida.
     */
    void setCor(sf::Color cor);

    /**
     * @brief Muda a cor do botão com base na posição do mouse.
     * 
     * @param window Janela onde o botão está sendo desenhado.
     */
    void mudarCor(sf::RenderWindow& window);

    /**
     * @brief Verifica se o mouse passou sobre o botão.
     * 
     * @param window Janela onde o botão está sendo desenhado.
     * @return True se o mouse passou sobre o botão, false caso contrário.
     */
    bool passouMouse(sf::RenderWindow& window);

    /**
     * @brief Desenha o botão na janela.
     * 
     * @param window Janela onde o botão deve ser desenhado.
     */
    void desenhar(sf::RenderWindow& window);

    /**
     * @brief Define o tamanho da fonte do texto do botão.
     * 
     * @param tamanho Novo tamanho da fonte.
     */
    void setTamanhoFonte(float tamanho);

    /**
     * @brief Verifica se o botão foi clicado.
     * 
     * @param window Janela onde o botão está sendo desenhado.
     * @return True se o botão foi clicado, false caso contrário.
     */
    bool foiClicado(sf::RenderWindow& window);

    
};


#endif // EXECUTAPARTIDA_HPP
