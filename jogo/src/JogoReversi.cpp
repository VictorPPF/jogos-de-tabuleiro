#include "../include/JogoReversi.hpp"
JogoReversi::JogoReversi(sf::RenderWindow& window, sf::Font& fonte, Tabuleiro & tabuleiro) : window(window), fonte(fonte),
        botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(223, 232, 106, 100), "", 15.f, false),
        botaoVoltar(234.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI !", 25.f, false, sf::Color(43, 0, 108))
    {
        //Estou assumindo que o tabuleiro já foi criado da forma correta no main (quadrado)
        //Aqui eu coloco as peças iniciais obrigatórias do jogo 
        botaoApelido.criarBotoes();
        botaoVoltar.criarBotoes();
        int posicao_meio = tabuleiro.get_qtd_celulaX()/2;
        tabuleiro.set_celula_status(posicao_meio, posicao_meio, 1);
        tabuleiro.set_celula_status(posicao_meio-1, posicao_meio-1, 1);
        tabuleiro.set_celula_status(posicao_meio, posicao_meio-1, 2);
        tabuleiro.set_celula_status(posicao_meio-1, posicao_meio, 2);
        }
void JogoReversi::desenharJogo() { 
    Wallpaper wallpaper("wallpaper_lig4.png");
    wallpaper.redimensionar(window.getSize());
    wallpaper.desenhar(window);
    JogoReversi::botaoApelido.desenhar(window);
    JogoReversi::botaoVoltar.desenhar(window);
}