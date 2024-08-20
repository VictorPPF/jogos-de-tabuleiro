#include "Wallpaper.hpp"
#include <iostream>

// Construtor que carrega a textura a partir de um arquivo e configura o sprite
Wallpaper::Wallpaper(const std::string& arquivo) {
    if (!textura.loadFromFile(arquivo)) {
        throw std::runtime_error("Erro ao carregar o wallpaper a partir do arquivo: " + arquivo);
    }
    sprite.setTexture(textura);  // Associa a textura ao sprite
}

// Método para desenhar o wallpaper na janela
void Wallpaper::desenhar(sf::RenderWindow& window) {
    window.draw(sprite);  // Desenha o sprite na janela
}

// Método para redimensionar o sprite do wallpaper para cobrir toda a janela
void Wallpaper::redimensionar(sf::Vector2u tamanhoJanela) {
    sprite.setScale(
        static_cast<float>(tamanhoJanela.x) / textura.getSize().x,  // Escala horizontal
        static_cast<float>(tamanhoJanela.y) / textura.getSize().y   // Escala vertical
    );
}
