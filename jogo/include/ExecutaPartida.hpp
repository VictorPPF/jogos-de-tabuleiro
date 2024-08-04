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

// namespace Math {

//     template <typename TL>
//     class Ponto {
//     public:
//         TL x;
//         TL y;

//     public:
//         Ponto(TL x, TL y);
//         Ponto();
//         ~Ponto() { }

//         void operator=(Ponto<TL> other);
//         void operator+=(Ponto<TL> other);
//         void operator-=(Ponto<TL> other);
//         void operator*=(double scalar);
//         void operator/=(double scalar);

//         Ponto<TL> operator+(Ponto<TL> other);
//         Ponto<TL> operator-(Ponto<TL> other);
//         Ponto<TL> operator*(Ponto<TL> other);
//         Ponto<TL> operator*(double scalar);
//         Ponto<TL> operator/(Ponto<TL> other);
//         Ponto<TL> operator/(double scalar);
//     };

//     typedef Ponto<double> PontoD;
//     typedef Ponto<float> PontoF;
//     typedef Ponto<int> PontoI;
//     typedef Ponto<unsigned int> PontoU;

//     // Instanciação explícita dos templates
//     template class Ponto<double>;
//     template class Ponto<float>;
//     template class Ponto<int>;
//     template class Ponto<unsigned int>;

//     template <typename TL>
//     Ponto<TL>::Ponto(TL x, TL y) :
//     x(x),
//     y(y) { }

//     template <typename TL>
//     Ponto<TL>::Ponto() {
//         this->x = 0;
//         this->y = 0;
//     }

//     template <typename TL>
//     void Ponto<TL>::operator=(Ponto<TL> other) {
//         this->x = other.x;
//         this->y = other.y;
//     }

//     template <typename TL>
//     void Ponto<TL>::operator+=(Ponto<TL> other) {
//         this->x += other.x;
//         this->y += other.y;
//     }

//     template <typename TL>
//     void Ponto<TL>::operator-=(Ponto<TL> other) {
//         this->x -= other.x;
//         this->y -= other.y;
//     }

//     template <typename TL>
//     void Ponto<TL>::operator*=(double scalar) {
//         this->x = this->x * scalar;
//         this->y = this->y * scalar;
//     }

//     template <typename TL>
//     void Ponto<TL>::operator/=(double scalar) {
//         if (scalar == 0.0f) {
//             std::cout << "ERROR: Cannot divide by zero." << std::endl;
//             exit(1);
//         }
//         this->x /= scalar;
//         this->y /= scalar;
//     }

//     template <typename TL>
//     Ponto<TL> Ponto<TL>::operator+(Ponto<TL> other) {
//         return Ponto<TL>(this->x + other.x, this->y + other.y);
//     }

//     template <typename TL>
//     Ponto<TL> Ponto<TL>::operator-(Ponto<TL> other) {
//         return Ponto<TL>(this->x - other.x, this->y - other.y);
//     }

//     template <typename TL>
//     Ponto<TL> Ponto<TL>::operator*(Ponto<TL> other) {
//         return Ponto<TL>(this->x * other.x, this->y * other.y);
//     }

//     template <typename TL>
//     Ponto<TL> Ponto<TL>::operator*(double scalar) {
//         return Ponto<TL>(this->x * scalar, this->y * scalar);
//     }

//     template <typename TL>
//     Ponto<TL> Ponto<TL>::operator/(Ponto<TL> other) {
//         if (other.x == 0.0f || other.y == 0.0f) {
//             std::cout << "ERROR: Cannot divide by zero." << std::endl;
//             exit(1);
//         }
//         return Ponto<TL>(this->x / other.x, this->y / other.y);
//     }

//     template <typename TL>
//     Ponto<TL> Ponto<TL>::operator/(double scalar) {
//         if (scalar == 0.0f) {
//             std::cout << "ERROR: Cannot divide by zero." << std::endl;
//             exit(1);
//         }

//         return Ponto<TL>(this->x / scalar, this->y / scalar);
//     }

// }

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

    //vai ser muito bom pra debugar
    template <typename T>
    std::ostream & operator << (std::ostream &os, const Math::Ponto<T>& outro) {
        return os << "[" << outro.x << "," << outro.y << "]"; //imprime o ponto no formato [x,y]
    }
    // template <typename T>
    // std::istream & operator >> (std::istream &is, Math::Ponto<T>& outro) {
    //     return is >> outro.x, is >> outro.y;
    // }


    typedef Ponto<double> PontoD;
    typedef Ponto<float> PontoF;
    typedef Ponto<int> PontoI;
    typedef Ponto<unsigned int> PontoU;

    // Instanciação explícita dos templates
    template class Ponto<double>;
    template class Ponto<float>;
    template class Ponto<int>;
    template class Ponto<unsigned int>;

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

}

#endif // EXECUTAPARTIDA_HPP