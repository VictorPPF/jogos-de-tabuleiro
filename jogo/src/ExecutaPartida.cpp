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
// Construtor da classe Botao
Botao::Botao(float largura, float altura, float x, float y, sf::Color cor, const std::string& texto, float tamanhoFonte, bool isCirculo, sf::Color corFonte)
    : largura(largura), altura(altura), posicao(x, y), cor(cor), texto(texto), tamanhoFonte(tamanhoFonte), isCirculo(isCirculo), corFonte(corFonte) {
    corHover = sf::Color(cor.r + 50, cor.g + 50, cor.b + 50);

    // Carregar a fonte
    if (!fonte.loadFromFile("font_arcade.ttf")) {
        std::cout << "Erro ao carregar a fonte" << std::endl;
    }
    
    bool clicou; //verifica se o botao foi clicado
    text.setFont(fonte);                                            // Define a fonte
    text.setString(texto);                                          // Define o texto
    text.setCharacterSize(static_cast<unsigned int>(tamanhoFonte)); // Define o tamanho da fonte
    text.setFillColor(corFonte);                                    // Define a cor da letra
}

// Configura a forma e o texto do botão
void Botao::criarBotoes() {
    if (isCirculo) {
        circulo.setRadius(largura / 2); // Define o raio do círculo
        circulo.setPosition(posicao);   // Define a posição do círculo
        circulo.setFillColor(cor);      // Define a cor do círculo
    } else {
        retangulo.setSize(sf::Vector2f(largura, altura)); // Define o tamanho do retângulo
        retangulo.setPosition(posicao);                   // Define a posição do retângulo
        retangulo.setFillColor(cor);                      // Define a cor do retângulo
    }
    // Ajusta o ponto de origem do texto para o centro
    sf::FloatRect textBounds = text.getLocalBounds(); // Obtém os limites locais do texto, o que inclui a largura e a altura do texto.
    text.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f + textBounds.top); //O ponto de origem é ajustado para o centro do texto horizontalmente e verticalmente

    // Ajusta a posição do texto para que fique centralizado no botão
    text.setPosition(posicao.x + largura / 2, posicao.y + altura / 2);
}

// Método para obter a cor atual do botão
sf::Color Botao::getCor() const {
    return cor;
}

// Atualiza a cor do botão com base na posição do mouse
void Botao::mudarCor(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Obtém a posição do mouse na janela
    if (isCirculo) {
        // Verifica se o mouse está sobre o círculo
        if (circulo.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            circulo.setFillColor(corHover); // Muda a cor para a corHover
        } else {
            circulo.setFillColor(cor); // Muda de volta para a cor original
        }
    } else {
        // Verifica se o mouse está sobre o retângulo
        if (retangulo.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            retangulo.setFillColor(corHover); // Muda a cor para a corHover
        } else {
            retangulo.setFillColor(cor); // Muda de volta para a cor original
        }
    }
}

// Desenha o botão (forma e texto) na janela
void Botao::desenhar(sf::RenderWindow& window) {
    mudarCor(window); // Atualiza a cor do botão com base na posição do mouse
    if (isCirculo) {
        window.draw(circulo); // Desenha o círculo na janela
    } else {
        window.draw(retangulo); // Desenha o retângulo na janela
    }
    window.draw(text); // Desenha o texto do botão na janela
}

// Definir o tamanho da fonte
void Botao::setTamanhoFonte(float tamanho) {
    tamanhoFonte = tamanho;
    text.setCharacterSize(static_cast<unsigned int>(tamanhoFonte));
}





