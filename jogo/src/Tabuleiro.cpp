#include "../include/Tabuleiro.hpp"
//#include "../include/Interacao.hpp"

Celula::Celula(int estado, float posicaoX, float posicaoY, float _tamanho_celula,sf::Color cor, bool isCirculo) : 
    estado(estado), posicaoX(posicaoX), posicaoY(posicaoY), _tamanho_celula(_tamanho_celula),cor(cor), isCirculo(isCirculo),
    botao(_tamanho_celula, _tamanho_celula, posicaoX, posicaoY, sf::Color(150, 129, 250), isCirculo) {}

void Celula::setEstado(int novoEstado) {
    estado = novoEstado;
}
int Celula::getEstado() {
    return estado;
}


Tabuleiro::Tabuleiro(float origx, float origy, int qtd_celulaX, int qtd_celulaY, float tamanho_celula, float borda): 
origemX(origx), origemY(origy), qtd_celulaX(qtd_celulaX), qtd_celulaY(qtd_celulaY), tamanho_celula(tamanho_celula), borda(borda) {
    //Inicializa a matriz de retangulos com qtd_celula de colunas e vetores (linhas) de tamanho qtd_celulaY

    //matriz.resize(qtd_celulaX, std::vector<Celula>(qtd_celulaY, Celula(0, 0, 0, tamanho_celula)));
    matriz.resize(qtd_celulaX, std::vector<Celula>(qtd_celulaY));
    for (int i = 0; i < qtd_celulaX; ++i) {
        for (int j = 0; j < qtd_celulaY; ++j) {
            matriz[i][j] = Celula(0, origemX + i * tamanho_celula, origemY + j * tamanho_celula, tamanho_celula,sf::Color(150, 129, 250),false);
            //Celula(int estado, float posicaoX, float posicaoY, float raio);
            slots[i][j] = Celula(0, origemX + (i + 1/2) * tamanho_celula, origemY + (j + 1/2) * tamanho_celula, tamanho_celula/2 - borda,sf::Color(121,122,147),true);
        }
    }
}
Tabuleiro::Tabuleiro() : qtd_celulaX(0), qtd_celulaY(0), tamanho_celula(0), matriz(0, std::vector<Celula>(0)), 
origemX(0), origemY(0), borda(0){};
/*std::vector<std::vector<Botao>> * Tabuleiro::getMatriz() {
    return &matriz;
}*/
// Obter o estado de uma célula específica
int Tabuleiro::get_celula_status(int linha, int coluna) {
    return matriz[linha][coluna].getEstado();
}
// Alterar o estado de uma célula específica
void Tabuleiro::set_celula_status(int linha, int coluna, int status) {
    matriz[linha][coluna].setEstado(status);
}

int Tabuleiro::get_qtd_celulaX() {
    return qtd_celulaX;
}

int Tabuleiro::get_qtd_celulaY() {
    return qtd_celulaY;
}   

void Tabuleiro::desenhar(sf::RenderWindow& window){
    for(int i=0; i < qtd_celulaX; i++){
        for(int j=0; j < qtd_celulaY; j++){
            matriz[i][j].botao.desenhar(window);
        }
    }    
    // Verifica se 0.5 segundo se passou
    // static sf::Clock relogio;
    // if (relogio.getElapsedTime().asSeconds() >= 0.5f) {
    //     sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    //     //std::cout << "Mouse Position: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl;
    //     relogio.restart(); // Reinicia o relógio
    // }

}
