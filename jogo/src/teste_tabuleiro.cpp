#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Tabuleiro.hpp"

TEST_CASE("Testando a inicialização de Tabuleiro") {
    float origemX = 0.0f;
    float origemY = 0.0f;
    int qtd_celulaX = 7;
    int qtd_celulaY = 6;
    float tamanho_celula = 100.0f;

    Tabuleiro tabuleiro(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula);

    auto matriz = tabuleiro.getMatriz();

    // Verifica se a matriz foi inicializada corretamente
    CHECK(matriz->size() == qtd_celulaX);
    CHECK(matriz->at(0).size() == qtd_celulaY);
}

TEST_CASE("Testando o método desenhar de Tabuleiro") {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");

    float origemX = 0.0f;
    float origemY = 0.0f;
    int qtd_celulaX = 7;
    int qtd_celulaY = 6;
    float tamanho_celula = 100.0f;

    Tabuleiro tabuleiro(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula);

    // Simula o desenho do tabuleiro na janela
    CHECK_NOTHROW(tabuleiro.desenhar(window));
}
