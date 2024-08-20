#include "../include/CampoTexto.hpp"

CampoTexto::CampoTexto(float largura, float altura, float posicaoX, float posicaoY)
    : retangulo(sf::Vector2f(largura, altura)), texto("", fonte, 25), ativo(false), deu_enter(0) {
    retangulo.setPosition(posicaoX, posicaoY);
    retangulo.setFillColor(sf::Color(223, 232, 106, 100)); // cor semitransparente
    retangulo.setOutlineThickness(2);
    retangulo.setOutlineColor(sf::Color::Black);

    texto.setPosition(posicaoX + 5, posicaoY + 10); // pequeno deslocamento pra dentro do retângulo
    texto.setFillColor(sf::Color::Black);
    
    try {
        if (!fonte.loadFromFile("font_arcade.ttf")) {
            throw std::runtime_error("Falha ao carregar a fonte.");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        // Lançar a exceção para indicar falha de inicialização
        throw;
    }
}

void CampoTexto::limparTexto() {
    texto.setString("");
}

void CampoTexto::desenhar(sf::RenderWindow& window) {
    window.draw(retangulo);
    window.draw(texto);
}

void CampoTexto::processarEventos(sf::Event& event, sf::RenderWindow& window) {
    deu_enter=false;
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (retangulo.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            ativar();
        } else {
            desativar();
        }
    }

    if (event.type == sf::Event::TextEntered) {
        if (ativo) {
            if (event.text.unicode == '\b') { // da backspace
                removerUltimoCaractere();
            } else if (event.text.unicode < 128) {
                adicionarCaractere(static_cast<char>(event.text.unicode));
            }
        }
    }
    
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) { // da enter
            if (ativo) {
                std::cout << "Texto inserido: " << obterTexto() << std::endl;
                deu_enter = true;
                desativar();
            }
        }
    }
}

std::string CampoTexto::obterTexto() const {
    return texto.getString();
}

void CampoTexto::ativar() {
    ativo = true;
    retangulo.setFillColor(sf::Color(223, 232, 106, 200));
    retangulo.setOutlineColor(sf::Color(150, 129, 250));
    
}

void CampoTexto::desativar() {
    ativo = false;
    retangulo.setFillColor(sf::Color(223, 232, 106, 100));
    retangulo.setOutlineColor(sf::Color::Black);
    
}

void CampoTexto::adicionarCaractere(char c) {
    texto.setString(texto.getString() + c);
}

void CampoTexto::removerUltimoCaractere() {
    sf::String str = texto.getString();
    if (str.getSize() > 0) {
        str.erase(str.getSize() - 1);
        texto.setString(str);
    }
}
