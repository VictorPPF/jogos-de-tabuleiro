#include "../include/Tabuleiro.hpp"
//#include "../include/ExecutaPartida.hpp"


Tabuleiro::Tabuleiro(float origx, float origy, int qtd_celulaX, int qtd_celulaY, float tamanho_celula) : 
origemX(origx), origemY(origy), qtd_celulaX(qtd_celulaX), qtd_celulaY(qtd_celulaY), tamanho_celula(tamanho_celula) {
    
    //Inicializa a matriz de retangulos com qtd_celula de colunas e vetores (linhas) de tamanho qtd_celulaY
    matriz.resize(qtd_celulaX, std::vector<Botao>(qtd_celulaY));

    for(int i=0; i<qtd_celulaX; i++){
        for(int j=0; j<qtd_celulaY; j++){
            matriz[i][j] = Botao(tamanho_celula, tamanho_celula, origemX + i*tamanho_celula , origemY + j*tamanho_celula, sf::Color(150, 129, 250),false);
        }
    }
}
std::vector<std::vector<Botao>> * Tabuleiro::getMatriz() {
    return &matriz;
}

void Tabuleiro::desenhar(sf::RenderWindow& window){
    for(int i=0; i < qtd_celulaX; i++){
        for(int j=0; j < qtd_celulaY; j++){
            matriz[i][j].desenhar(window);
            
        }
    }    
    // Verifica se 0.5 segundo se passou
    static sf::Clock relogio;
    if (relogio.getElapsedTime().asSeconds() >= 0.5f) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        std::cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl;
        relogio.restart(); // Reinicia o relógio
    }

}