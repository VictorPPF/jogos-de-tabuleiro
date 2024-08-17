#include "../include/JogoLig4.hpp"
#include "../include/Wallpaper.hpp"

JogoLig4::JogoLig4(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
        origemX(238.0), origemY(166.0), qtd_celulaX(7), qtd_celulaY(6), tamanho_celula(75.0), borda(3),
        botaoVoltar(234.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI !", 25.f, false, sf::Color(43, 0, 108)),
        tabuleiroLIG4(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula, borda)
    {

        botaoVoltar.criarBotoes();
    }
void JogoLig4::desenharJogo() {
    Wallpaper wallpaper("wallpaper_lig4.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    JogoLig4::botaoVoltar.desenhar(window);
    JogoLig4::tabuleiroLIG4.desenhar(window);
}
