#include "../include/JogoLig4.hpp"
JogoLig4::JogoLig4(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
        
        botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(223, 232, 106, 100), "", 15.f, false),
        botaoVoltar(234.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI !", 25.f, false, sf::Color(43, 0, 108))
    {
        
        botaoApelido.criarBotoes();
        botaoVoltar.criarBotoes();
    }
void JogoLig4::desenharJogo() {
    Wallpaper wallpaper("wallpaper_lig4.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    JogoLig4::botaoApelido.desenhar(window);
    JogoLig4::botaoVoltar.desenhar(window);
}