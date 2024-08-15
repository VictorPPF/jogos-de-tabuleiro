#include "../include/Tabuleiro.hpp"
//#include "../include/ExecutaPartida.hpp"

// Tabuleiro::Tabuleiro(){
//     qtd_celulaX=3;
//     qtd_celulaY=5;
//     tamanho_celula=60;
//     //Inicializa uma matriz 3x3 com zeros em todas as células
//     matriz.resize(qtd_celulaX, std::vector<int>(qtd_celulaY, 0)); 
// }

// void Tabuleiro::desenhar(sf::RenderWindow& window){
//     sf::RectangleShape quadrado(sf::Vector2f(tamanho_celula, tamanho_celula));
//     quadrado.setFillColor(sf::Color::White);
//     quadrado.setOutlineColor(sf::Color::Black);
//     quadrado.setOutlineThickness(2);
    
//     for(int i=0; i<qtd_celulaX; i++){
//         for(int j=0; j<qtd_celulaY; j++){
//             if(matriz[i][j]==0){
//                 quadrado.setPosition(i*tamanho_celula, j*tamanho_celula);
//                 window.draw(quadrado);
//             }
//         }
//     }
// }

Tabuleiro::Tabuleiro() {
    qtd_celulaX=7; //colunas
    qtd_celulaY=6; //linhas
    tamanho_celula= 75;
    int origemX = windowLargura - tamanho_celula*7.0;
    int origemY = windowAltura/4.0;
    //Inicializa a matriz de retangulos com qtd_celula de colunas e vetores (linhas) de tamanho qtd_celulaY
    matriz.resize(qtd_celulaX, std::vector<Botao>(qtd_celulaY));

    for(int i=0; i<qtd_celulaX; i++){
        for(int j=0; j<qtd_celulaY; j++){
            matriz[i][j] = Botao(tamanho_celula, tamanho_celula, origemX + i*tamanho_celula , origemY + j*tamanho_celula, sf::Color(150, 129, 250),false);
        }
    }
}

void Tabuleiro::desenhar(sf::RenderWindow& window){
    for(int i=0; i < qtd_celulaX; i++){
        for(int j=0; j < qtd_celulaY; j++){
            matriz[i][j].desenhar(window);
        }
    }
}