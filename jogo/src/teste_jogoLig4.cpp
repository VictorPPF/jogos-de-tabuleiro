#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "../include/JogoLig4.hpp"

TEST_CASE("Testando a inicialização de JogoLig4") {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");
    sf::Font fonte;
    fonte.loadFromFile("arial.ttf");

    JogoLig4 jogo(window, fonte);

    // Verifica se os botões foram criados corretamente
    CHECK(jogo.botaoApelido.getTexto() == "");
    CHECK(jogo.botaoVoltar.getTexto() == "DESISTI !");
}

TEST_CASE("Testando o método desenharJogo de JogoLig4") {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");
    sf::Font fonte;
    fonte.loadFromFile("arial.ttf");

    JogoLig4 jogo(window, fonte);

    // Simula o desenho do jogo na janela
    CHECK_NOTHROW(jogo.desenharJogo());
}
