// Wallpaper.hpp
#ifndef WALLPAPER_HPP
#define WALLPAPER_HPP

#include <SFML/Graphics.hpp>
#include <string>

// Classe que gerencia a textura e o sprite do wallpaper
class Wallpaper {

private:
    sf::Texture textura;  // Textura do wallpaper
    sf::Sprite sprite;    // Sprite que usa a textura

public:
    // Construtor que carrega a textura do arquivo e cria o sprite
    Wallpaper(const std::string& arquivo);
    
    // Método para desenhar o wallpaper na janela
    void desenhar(sf::RenderWindow& window);
    
    // Método para ajustar o tamanho do sprite do wallpaper de acordo com o tamanho da janela
    void redimensionar(sf::Vector2u tamanhoJanela);
};

#endif // WALLPAPER_HPP
