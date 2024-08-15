#include "../include/Tabuleiro.hpp"

Tabuleiro::Tabuleiro(){
    qtd_celulaX=3;
    qtd_celulaY=5;
    tamanho_celula=60;
    //Inicializa uma matriz 3x3 com zeros em todas as células
    matriz.resize(qtd_celulaX, std::vector<int>(qtd_celulaY, 0)); 
}

void Tabuleiro::desenhar(sf::RenderWindow& window){
    sf::RectangleShape quadrado(sf::Vector2f(tamanho_celula, tamanho_celula));
    quadrado.setFillColor(sf::Color::White);
    quadrado.setOutlineColor(sf::Color::Black);
    quadrado.setOutlineThickness(2);
    
    for(int i=0; i<qtd_celulaX; i++){
        for(int j=0; j<qtd_celulaY; j++){
            if(matriz[i][j]==0){
                quadrado.setPosition(i*tamanho_celula, j*tamanho_celula);
                window.draw(quadrado);
            }
        }
    }
}