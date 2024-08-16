#ifndef INTERACAO_HPP
#define INTERACAO_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>


// Classe Movimentacao
class Movimentacao {
public:
    // Construtor
    Movimentacao();

    // Método público para movimentação
    void mover(sf::CircleShape &circulo, const sf::Keyboard::Key &key);
    void mover(sf::RectangleShape &retangulo, const sf::Keyboard::Key &key);

private:
    // Atributos privados podem ser adicionados aqui
};


//classe que representa um ponto no plano cartesiano ##########################
template <typename T>
class Ponto {
public:
    T x, y;

    Ponto(T x, T y) : x(x), y(y) {}
    Ponto() : x(0), y(0) {} //construtor padrao cria um ponto na origem (0,0)

    void operator=(const Ponto& outro) {
        x = outro.x;
        y = outro.y;
    }

    void operator+=(const Ponto& outro) {
        x += outro.x;
        y += outro.y;
    }

    void operator-=(const Ponto& outro) {
        x -= outro.x;
        y -= outro.y;
    }

    void operator*=(double escalar) {
        x = x * escalar;
        y = y * escalar;
    }

    void operator/=(double escalar) {
        if (escalar == 0) {
            throw std::runtime_error("ERRO: calma la amigao! divisao por zero.");
        }
        x /= escalar;
        y /= escalar;
    }

    Ponto operator+(const Ponto& outro) const {
        return Ponto(x + outro.x, y + outro.y);
    }

    Ponto operator-(const Ponto& outro) const {
        return Ponto(x - outro.x, y - outro.y);
    }

    Ponto operator*(const Ponto& outro) const {
        return Ponto(x * outro.x, y * outro.y);
    }

    Ponto operator*(double escalar) const {
        return Ponto(x * escalar, y * escalar);
    }

    Ponto operator/(const Ponto& outro) const {
        if (outro.x == 0 || outro.y == 0) {
            throw std::runtime_error("ERRO: calma la amigao! divisao por zero.");
        }
        return Ponto(x / outro.x, y / outro.y);
    }

    Ponto operator/(double escalar) const {
        if (escalar == 0) {
            throw std::runtime_error("ERRO: calma la amigao! divisao por zero.");
        }
        return Ponto(x / escalar, y / escalar);
    }

    bool operator==(const Ponto& outro) const {
        return x == outro.x && y == outro.y;
    }

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
typedef Ponto<double> PontoD;
typedef Ponto<float> PontoF;
typedef Ponto<int> PontoI;
typedef Ponto<unsigned int> PontoU;

//classe Botao
class Botao {
protected:
    // Atributos para definir as dimensões e posição do botão
    float largura;           // Largura do botão
    float altura;            // Altura do botão
    sf::Vector2f posicao;    // Posição do botão na janela (x, y)
    
    // Atributos para definir as cores do botão
    sf::Color cor;           // Cor original do botão
    sf::Color corHover;      // Cor do botão quando o mouse está sobre ele
    
    // Atributos para definir a forma do botão
    sf::RectangleShape retangulo; // Forma retangular do botão
    sf::CircleShape circulo;       // Forma circular do botão
    bool isCirculo;                // Indica se o botão é circular
    
    // Atributos para o texto do botão
    std::string texto;     // Texto exibido no botão
    sf::Font fonte;        // Fonte do texto
    sf::Text text;         // Texto SFML para desenhar o texto no botão
    sf::Color corFonte;    // Cor da fonte
    float tamanhoFonte;    // Tamanho da fonte do texto do botão
    int windowLargura = 1000;
    int windowAltura = 690;

public:
    // Construtor da classe Botao
    Botao(float largura, float altura, float x, float y, sf::Color cor, const std::string& texto, float tamanhoFonte = 24.f,
        bool isCirculo = false, sf::Color corFonte = sf::Color::White);
    Botao() = default;
    //construtor das celulas do tabuleiro
    Botao(float largura, float altura, float x, float y, sf::Color cor, bool isCirculo = false);
    // Método para criar a forma do botão (retângulo ou círculo)
    void criarBotoes();

    // Método para obter a cor do botão
    sf::Color getCor() const;

    sf::RectangleShape getRetangulo() const;

    void setCorHover(sf::Color cor);

    void setCor(sf::Color cor);

    // Método para mudar a cor do botão com base na posição do mouse
    void mudarCor(sf::RenderWindow& window);

    bool passouMouse(sf::RenderWindow& window);

    // Método para desenhar o botão na janela
    void desenhar(sf::RenderWindow& window);

    // Método para definir o tamanho da fonte
    void setTamanhoFonte(float tamanho);

    // Método para verificar se o botão foi clicado
    bool foiClicado(sf::RenderWindow& window);
};

#endif // EXECUTAPARTIDA_HPP