#include "../include/Interacao.hpp"
#include <iostream>


// Implementação da classe Botao
// Construtor da classe Botao
Botao::Botao(float largura, float altura, float x, float y, sf::Color cor, const std::string& texto, float tamanhoFonte, bool isCirculo, sf::Color corFonte)
    : largura(largura), altura(altura), posicao(x, y), cor(cor), texto(texto), tamanhoFonte(tamanhoFonte), isCirculo(isCirculo), corFonte(corFonte) {
    corHover = sf::Color(cor.r + 50, cor.g + 50, cor.b + 50);

    // Carregar a fonte
    try {
        if (!fonte.loadFromFile("font_arcade.ttf")) {
            throw std::runtime_error("Falha ao carregar a fonte.");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        // Lançar a exceção para indicar falha de inicialização
        throw;
    }

    text.setFont(fonte);                                            // Define a fonte
    text.setString(texto);                                          // Define o texto
    text.setCharacterSize(static_cast<unsigned int>(tamanhoFonte)); // Define o tamanho da fonte
    text.setFillColor(corFonte);                                    // Define a cor da letra
}
//construtor das celulas do tabuleiro
Botao::Botao(float largura, float altura, float x, float y, sf::Color cor, bool isCirculo)
    : largura(largura), altura(altura), posicao(x, y), cor(cor), isCirculo(isCirculo) {
    corHover = sf::Color(cor.r + 50, cor.g + 50, cor.b + 50);
    if (isCirculo) {
        circulo.setRadius(largura); // Define o raio do círculo
        circulo.setPosition(posicao);   // Define a posição do círculo
        circulo.setFillColor(cor);      // Define a cor do círculo
    } else {
        retangulo.setSize(sf::Vector2f(largura, altura)); // Define o tamanho do retângulo
        retangulo.setPosition(posicao);                   // Define a posição do retângulo
        retangulo.setFillColor(cor);                    // Define a cor do retângulo
        retangulo.setOutlineColor(sf::Color::Black);
        retangulo.setOutlineThickness(2);
    }
}

// Configura a forma e o texto do botão
void Botao::criarBotoes() {
    try {
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
    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar botões: " << e.what() << std::endl;
        // Opcional: definir um estado inválido ou tratar o erro conforme necessário
    }
}

// Método para obter a cor atual do botão
sf::Color Botao::getCor() const {
    return cor;
}


sf::RectangleShape Botao::getRetangulo() const{
    return retangulo;
}

sf::CircleShape Botao::getCirculo() const{
    return circulo;
}

void Botao::setCorHover(sf::Color cor){
    corHover = cor;
}

void Botao::setCor(sf::Color cor) {
    this->cor = cor;
    corHover = sf::Color(cor.r + 50, cor.g + 50, cor.b + 50);
    if (isCirculo) {
        circulo.setFillColor(cor);
    } else {
        retangulo.setFillColor(cor);
    }
}

// Atualiza a cor do botão com base na posição do mouse
void Botao::mudarCor(sf::RenderWindow& window) {
    
    sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Obtém a posição do mouse na janela
    sf::FloatRect bounds;

        if (isCirculo) {
            bounds = circulo.getGlobalBounds();
        } else {
            bounds = retangulo.getGlobalBounds();
        }

        // Reduz a área de detecção para evitar a seleção de múltiplas células
        bounds.left += retangulo.getOutlineThickness();
        bounds.top += retangulo.getOutlineThickness();
        bounds.width -= 2 * retangulo.getOutlineThickness();
        bounds.height -= 2 * retangulo.getOutlineThickness();

        if (bounds.contains(static_cast<sf::Vector2f>(mousePos))) {
            if (isCirculo) {
                circulo.setFillColor(corHover); // Muda a cor para a corHover
            } else {
                retangulo.setFillColor(corHover); // Muda a cor para a corHover
            }
        } else {
            if (isCirculo) {
                circulo.setFillColor(cor); // Muda de volta para a cor original
            } else {
                retangulo.setFillColor(cor); // Muda de volta para a cor original
            }
    }
}

bool Botao::passouMouse(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Obtém a posição do mouse na janela
    if (isCirculo) {
        // Verifica se o mouse está sobre o círculo
        if (circulo.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        } else {
            return false;
        }
    } else {
        // Verifica se o mouse está sobre o retângulo
        if (retangulo.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        } else {
            return false;
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

// Método para verificar se o botão foi clicado
bool Botao::foiClicado(sf::RenderWindow& window) {
    try {
        static bool foiPressionado = false; // Mantém o estado do botão do mouse
        sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Obtém a posição do mouse na janela
        sf::FloatRect bounds = retangulo.getGlobalBounds();

        // Reduz a área de detecção para evitar a seleção de múltiplas células
        bounds.left += retangulo.getOutlineThickness();
        bounds.top += retangulo.getOutlineThickness();
        bounds.width -= 2 * retangulo.getOutlineThickness();
        bounds.height -= 2 * retangulo.getOutlineThickness();

        // Verifica se o mouse está sobre o botão
        if (bounds.contains(static_cast<sf::Vector2f>(mousePos))) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (!foiPressionado) {
                    foiPressionado = true; // Registra que o botão foi pressionado
                    return true;
                }
            } else {
                foiPressionado = false; // Reseta o estado quando o botão é liberado
            }
        }

        return false;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao verificar clique: " << e.what() << std::endl;
        return false;
    }
}