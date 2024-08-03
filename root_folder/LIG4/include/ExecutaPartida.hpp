#ifndef EXECUTAPARTIDA_HPP
#define EXECUTAPARTIDA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Classe Movimentacao
class Movimentacao {
public:
    // Construtor
    Movimentacao();

    // Método público para movimentação
    void mover(sf::CircleShape &circle, const sf::Keyboard::Key &key);

private:
    // Atributos privados podem ser adicionados aqui
};

// Outras classes podem ser declaradas aqui

namespace Math {

    template <typename T>
    class Ponto {
    public:
        T x;
        T y;

    public:
        Ponto(T x, T y);
        Ponto();
        ~Ponto() { }
        
        void operator = (Ponto<T> outro);
        void operator += (Ponto<T> outro);
        void operator -= (Ponto<T> outro);
        void operator *= (double escalar);
        void operator /= (double escalar);
        
        Ponto<T> operator + (Ponto<T> outro);
        Ponto<T> operator - (Ponto<T> outro);
        Ponto<T> operator * (Ponto<T> outro);
        Ponto<T> operator * (double escalar);
        Ponto<T> operator / (Ponto<T> outro);
        Ponto<T> operator / (double escalar);
        bool operator == (Ponto<T> outro);
    };

    // typedef Ponto<double> PontoD;
    // typedef Ponto<float> PontoF;
    // typedef Ponto<int> PontoI;
    // typedef Ponto<unsigned int> PontoU;

    // template <typename T>
    // Ponto<T>::Ponto(T x, T y) : x(x), y(y) { }

    // template <typename T> //construtor padrao faz ponto na origem (0,0)
    // Ponto<T>::Ponto() {
    //     this->x = 0;
    //     this->y = 0;
    // }

    // template <typename T>
    // void Ponto<T>::operator = (Ponto<T> outro) {
    //     this->x = outro.x;
    //     this->y = outro.y;
    // }

    // template <typename T>
    // void Ponto<T>::operator += (Ponto<T> outro) {
    //     this->x += outro.x;
    //     this->y += outro.y;
    // }

    // template <typename T>
    // void Ponto<T>::operator -= (Ponto<T> outro) {
    //     this->x -= outro.x;
    //     this->y -= outro.y;
    // }

    // template <typename T>
    // void Ponto<T>::operator *= (double escalar) {
    //     this->x = this->x * escalar;
    //     this->y = this->y * escalar;
    // }

    // template <typename T>
    // void Ponto<T>::operator /= (double escalar) {
    //     if (escalar == 0.0f) {
    //         std::cout << "ERRO: calma la amigao! divisao por zero." << std::endl;
    //         exit(1);
    //     }
    //     this->x /= escalar;
    //     this->y /= escalar;
    // }

    // template <typename T>
    // Ponto<T> Ponto<T>::operator + (Ponto<T> outro) {
    //     return Ponto<T>(this->x + outro.x, this->y + outro.y);
    // }

    // template <typename T>
    // Ponto<T> Ponto<T>::operator - (Ponto<T> outro) {
    //     return Ponto<T>(this->x - outro.x, this->y - outro.y);
    // }

    // template <typename T>
    // Ponto<T> Ponto<T>::operator * (Ponto<T> outro) {
    //     return Ponto<T>(this->x * outro.x, this->y * outro.y);
    // }

    // template <typename T>
    // Ponto<T> Ponto<T>::operator * (double escalar) {
    //     return Ponto<T>(this->x * escalar, this->y * escalar);
    // }

    // template <typename T>
    // Ponto<T> Ponto<T>::operator / (Ponto<T> outro) {
    //     if (outro.x == 0.0f || outro.y == 0.0f) {
    //         std::cout << "ERRO: calma la amigao! divisao por zero." << std::endl;
    //         exit(1);
    //     }
    //     return Ponto<T>(this->x / outro.x, this->y / outro.y);
    // }

    // template <typename T>
    // Ponto<T> Ponto<T>::operator / (double escalar) {
    //     if (escalar == 0.0f) {
    //         std::cout << "ERRO: calma la amigao! divisao por zero." << std::endl;
    //         exit(1);
    //     }

    //     return Ponto<T>(this->x / escalar, this->y / escalar);
    // }

}

#endif // EXECUTAPARTIDA_HPP