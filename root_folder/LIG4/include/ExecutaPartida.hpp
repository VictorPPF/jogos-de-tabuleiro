#ifndef EXECUTAPARTIDA_HPP
#define EXECUTAPARTIDA_HPP

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
public:
    float tamX, tamY;
    //std::unique_ptr<PontoF> posicao;
    PontoF *posicao;
    sf::Color cor;
    sf::RectangleShape retangulo;
    sf::Text texto;
    sf::Font fonte;
    bool isFocado;
    
    Botao(PontoF &ponto, float tamX, float tamY, sf::Color cor_);
    Botao();
    ~Botao();

    void criarCampo(float tamX, float tamY, const std::string& fonteCaminho);
    void setFocado(bool foco);
    void receberInput(sf::Event event);
    sf::Text & getTexto();

    PontoF getPosicao() const;
    sf::Color getCor();
    PontoF getCentro() const;
    void setCor(sf::Color cor);
    sf::RectangleShape & getForma();
    
};


#endif // EXECUTAPARTIDA_HPP