/**
 * @file Wallpaper.hpp
 * @brief Definição da classe Wallpaper que gerencia a textura e o sprite do wallpaper
 */
#ifndef WALLPAPER_HPP
#define WALLPAPER_HPP

#include <SFML/Graphics.hpp>
#include <string>
class Wallpaper {

private:
    /**
     * @param textura: textura do wallpaper
     */
    sf::Texture textura;  
    /**
     * @param sprite: sprite que usa a textura
     */
    sf::Sprite sprite;    

public:
    /**
     * @brief Construtor que carrega a textura do arquivo e cria o sprite
     */
    Wallpaper(const std::string& arquivo);
    /**
     * @brief desenhar é o método para desenhar o wallpaper na janela
     * @param window: janela onde o wallpaper será desenhado
     * @return void 
     */
    void desenhar(sf::RenderWindow& window);
    /**
     * @brief Método para redimensionar o wallpaper
     * @param tamanhoJanela: tamanho da janela onde o wallpaper será desenhado
     * @return void
     */
    void redimensionar(sf::Vector2u tamanhoJanela);
};

#endif // WALLPAPER_HPP
