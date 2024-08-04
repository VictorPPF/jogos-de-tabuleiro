#include "../include/ExecutaPartida.hpp"
#include <iostream>


// Implementação da classe Movimentacao

// Construtor
Movimentacao::Movimentacao() {
    // Inicialização dos atributos, se necessário
}


// Implementação do método mover
void Movimentacao::mover(sf::CircleShape &circulo, const sf::Keyboard::Key &TECLA) {
    float velocidade = 5.0f; // Distância que o círculo se moverá a cada vez

    switch (TECLA) {
        case sf::Keyboard::Right:
            circulo.move(velocidade, 0);
            break;
        case sf::Keyboard::Left:
            circulo.move(-velocidade, 0);
            break;
        case sf::Keyboard::Up:
            circulo.move(0, -velocidade);
            break;
        case sf::Keyboard::Down:
            circulo.move(0, velocidade);
            break;
        default:
            break;
    }
}
void Movimentacao::mover(sf::RectangleShape &retangulo, const sf::Keyboard::Key &TECLA) {
    float velocidade = 1.0f; // Distância que o círculo se moverá a cada vez

    switch (TECLA) {
        case sf::Keyboard::Key::D:
            retangulo.move(velocidade, 0);
            break;
        case sf::Keyboard::Key::A:
            retangulo.move(-velocidade, 0);
            break;
        case sf::Keyboard::Key::W:
            retangulo.move(0, -velocidade);
            break;
        case sf::Keyboard::Key::S:
            retangulo.move(0, velocidade);
            break;
        default:
            break;
    }
}


// Implementação da classe Botao


Botao::Botao(PontoF &ponto, float tamX, float tamY, sf::Color cor_) {
    this->tamX = tamX;
    this->tamY = tamY;
    this->cor = cor_;
    this->isFocado = false;
    texto.setCharacterSize(24);

    this->retangulo = sf::RectangleShape(sf::Vector2f(tamX, tamY));
    this->retangulo.setPosition(ponto.x, ponto.y);
    retangulo.setFillColor(this->cor);

    if (!fonte.loadFromFile("arial.ttf")) {
        std::cerr << "opa, nao achou o arquivo da fonte\n";
    }

    texto.setFont(fonte);
    
}
Botao::Botao() {
    this->tamX = 0.0;
    this->tamY = 0.0;
    this->posicao = new PontoF(0.0, 0.0);
    this->isFocado = false;
    texto.setCharacterSize(24);
    //retangulo.setFillColor(sf::Color::White);
    // Cria um retângulo de tamX x tamY pixels
    this->retangulo = sf::RectangleShape(sf::Vector2f(tamX, tamY));
    //Define a posição do retângulo (x, y)
    this->retangulo.setPosition(this->posicao->x, this->posicao->y);
    if (!fonte.loadFromFile("arial.ttf")) {
        std::cerr << "opa, nao achou o arquivo da fonte\n";
    }
    texto.setFont(fonte);
    
}

Botao::~Botao() {
    delete this->posicao;
}

void Botao::criarCampo(float tamX, float tamY, const std::string& fonteCaminho) {
    this->tamX = tamX;
    this->tamY = tamY;
    retangulo.setSize(sf::Vector2f(tamX, tamY));
    if (!fonte.loadFromFile(fonteCaminho)) {
        std::cerr << "opa, nao achou o arquivo da fonte\n";
    }
    texto.setFont(fonte);
    texto.setPosition(posicao->x + 5, posicao->y + 5);
}

void Botao::setFocado(bool foco) {
    isFocado = foco;
    if (foco) {
        retangulo.setFillColor(sf::Color::Cyan); // Cor ao focar
    } else {
        retangulo.setFillColor(sf::Color::White); // Cor padrão ao desfocar
    }
}

void Botao::receberInput(sf::Event event) {
    if (isFocado) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) { // ASCII check
                if (event.text.unicode == 8) { // tecla do backspace
                    std::string str = texto.getString();
                    if (!str.empty()) {
                        str.pop_back();  // Remove o último caractere
                    }
                    texto.setString(str);
                } else if (event.text.unicode == 13) { // tecla enter
                    std::cout << "Texto inserido: " << texto.getString().toAnsiString() << std::endl;
                    retangulo.setFillColor(sf::Color::Green); // Muda a cor do retângulo para verde
                } else {
                    texto.setString(texto.getString() + static_cast<char>(event.text.unicode));
                }
            }
        }
    }
}

sf::Text & Botao::getTexto() {
    return texto;
}

sf::Color Botao::getCor() {
    return this->cor;
}

PontoF Botao::getPosicao() const {
    sf::Vector2f pos = retangulo.getPosition();
    return PontoF(pos.x, pos.y);
}
PontoF Botao::getCentro() const{
    
    return PontoF(retangulo.getPosition().x + this->tamX/2 , retangulo.getPosition().y + this->tamY/2 );
}

void Botao::setCor(sf::Color cor) {
    this->cor = cor;
}

sf::RectangleShape & Botao::getForma() {
    return retangulo;
}






