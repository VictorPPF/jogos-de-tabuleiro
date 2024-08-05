#ifndef EXECUTAPARTIDA_HPP
#define EXECUTAPARTIDA_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Botao {
private:
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

public:
    // Construtor da classe Botao
    Botao(float largura, float altura, float x, float y, sf::Color cor, const std::string& texto, float tamanhoFonte = 24.f, bool isCirculo = false, sf::Color corFonte = sf::Color::White);

    // Método para criar a forma do botão (retângulo ou círculo)
    void criarBotoes();

    // Método para obter a cor do botão
    sf::Color getCor() const;

    // Método para mudar a cor do botão com base na posição do mouse
    void mudarCor(sf::RenderWindow& window);

    // Método para desenhar o botão na janela
    void desenhar(sf::RenderWindow& window);

    // Método para definir o tamanho da fonte
    void setTamanhoFonte(float tamanho);
};

#endif // EXECUTAPARTIDA_HPP
