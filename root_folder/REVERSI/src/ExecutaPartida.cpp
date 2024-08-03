#include "ExecutaPartida.hpp"
#include <iostream>

// Implementação da classe Movimentacao

// Construtor
Movimentacao::Movimentacao() {
    // Inicialização dos atributos, se necessário
}


// Implementação do método mover
void Movimentacao::mover(sf::CircleShape &circle, const sf::Keyboard::Key &key) {
    float moveDistance = 5.0f; // Distância que o círculo se moverá a cada vez

    switch (key) {
        case sf::Keyboard::Right:
            circle.move(moveDistance, 0);
            break;
        case sf::Keyboard::Left:
            circle.move(-moveDistance, 0);
            break;
        case sf::Keyboard::Up:
            circle.move(0, -moveDistance);
            break;
        case sf::Keyboard::Down:
            circle.move(0, moveDistance);
            break;
        default:
            break;
    }
}



//implementação de operadores da classe Ponto

namespace Math {
    typedef Ponto<double> PontoD;
    typedef Ponto<float> PontoF;
    typedef Ponto<int> PontoI;
    typedef Ponto<unsigned int> PontoU;

    template <typename T>
    Ponto<T>::Ponto(T x, T y) : x(x), y(y) { }

    template <typename T> //construtor padrao faz ponto na origem (0,0)
    Ponto<T>::Ponto() {
        this->x = 0;
        this->y = 0;
    }

    template <typename T>
    void Ponto<T>::operator = (Ponto<T> outro) {
        this->x = outro.x;
        this->y = outro.y;
    }

    template <typename T>
    void Ponto<T>::operator += (Ponto<T> outro) {
        this->x += outro.x;
        this->y += outro.y;
    }

    template <typename T>
    void Ponto<T>::operator -= (Ponto<T> outro) {
        this->x -= outro.x;
        this->y -= outro.y;
    }

    template <typename T>
    void Ponto<T>::operator *= (double escalar) {
        this->x = this->x * escalar;
        this->y = this->y * escalar;
    }

    template <typename T>
    void Ponto<T>::operator /= (double escalar) {
        if (escalar == 0.0f) {
            std::cout << "ERRO: calma la amigao! divisao por zero." << std::endl;
            exit(1);
        }
        this->x /= escalar;
        this->y /= escalar;
    }

    template <typename T>
    Ponto<T> Ponto<T>::operator + (Ponto<T> outro) {
        return Ponto<T>(this->x + outro.x, this->y + outro.y);
    }

    template <typename T>
    Ponto<T> Ponto<T>::operator - (Ponto<T> outro) {
        return Ponto<T>(this->x - outro.x, this->y - outro.y);
    }

    template <typename T>
    Ponto<T> Ponto<T>::operator * (Ponto<T> outro) {
        return Ponto<T>(this->x * outro.x, this->y * outro.y);
    }

    template <typename T>
    Ponto<T> Ponto<T>::operator * (double escalar) {
        return Ponto<T>(this->x * escalar, this->y * escalar);
    }

    template <typename T>
    Ponto<T> Ponto<T>::operator / (Ponto<T> outro) {
        if (outro.x == 0.0f || outro.y == 0.0f) {
            std::cout << "ERRO: calma la amigao! divisao por zero." << std::endl;
            exit(1);
        }
        return Ponto<T>(this->x / outro.x, this->y / outro.y);
    }

    template <typename T>
    Ponto<T> Ponto<T>::operator / (double escalar) {
        if (escalar == 0.0f) {
            std::cout << "ERRO: calma la amigao! divisao por zero." << std::endl;
            exit(1);
        }

        return Ponto<T>(this->x / escalar, this->y / escalar);
    }
    template <typename T>
    bool Ponto<T>::operator == (Ponto<T> outro)   {
    if (this->x == outro.x && this->y == outro.y) {
        return true;
    } else {
        return false;
    }
    }
} // namespace Math