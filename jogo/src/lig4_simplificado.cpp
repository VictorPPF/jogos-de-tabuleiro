#include <iostream>

const int LINHAS = 6;
const int COLUNAS = 7;

//Construção
void inicializarMatriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = 0;
        }
    }
}

//Desenho 
void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


bool verificaJogada(int matriz[LINHAS][COLUNAS], int x) {
    // Função para verificar se a jogada é válida
    // Verifica se a coluna esta no limite da matriz 
    if (x < 0 || x >= COLUNAS) {
        return false;
    }
    // Verifica se a coluna está cheia
    if (matriz[0][x] != 0) {
        return false;
    }
    return true;
}

bool fazJogada(int matriz[LINHAS][COLUNAS], int x, int jogador) {
    // Função para fazer a jogada
    if (!verificaJogada(matriz, x)) {
        return false;
    }

    // Preenche a primeira posição vazia na coluna
    for (int i = LINHAS - 1; i >= 0; i--) {
        if (matriz[i][x] == 0) {
            matriz[i][x] = jogador;
            return true;
        }
    }
    return false;
}

bool condicaoVitoria(int matriz[LINHAS][COLUNAS], int jogador) {
    // Verifica linhas
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j <= COLUNAS - 3; j++) {
            if (matriz[i][j] == jogador && matriz[i][j + 1] == jogador && matriz[i][j + 2] == jogador && matriz[i][j + 3] == jogador) {
                return true;
            }
        }
    }
    // Verifica colunas
    for (int j = 0; j < COLUNAS; j++) {
        for (int i = 0; i <= LINHAS - 3; i++) {
            if (matriz[i][j] == jogador && matriz[i + 1][j] == jogador && matriz[i + 2][j] == jogador && matriz[i + 3][j] == jogador) {
                return true;
            }
        }
    }
    // Verifica diagonal principal
    for (int i = 0; i <= LINHAS - 3; i++) {
        for (int j = 0; j <= COLUNAS - 3; j++) {
            if (matriz[i][j] == jogador && matriz[i + 1][j + 1] == jogador &&
             matriz[i + 2][j + 2] == jogador && matriz[i + 3][j + 3] == jogador) {
                return true;
            }
        }
    }
    // Verifica diagonal secundária
    for (int i = 0; i <= LINHAS - 3; i++) {
        for (int j = 2; j < COLUNAS; j++) {
            if (matriz[i][j] == jogador && matriz[i + 1][j - 1] == jogador &&
             matriz[i + 2][j - 2] == jogador && matriz[i + 3][j - 3] == jogador) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int matriz[LINHAS][COLUNAS];
    inicializarMatriz(matriz);
    imprimirMatriz(matriz);
    int jogadorAtual = 1;  // Jogador 1 começa

    while (true) {
        int x;
        std::cout << "Jogador " << jogadorAtual << ", insira a coluna (x): ";
        std::cin >> x;

        if (x == -1) break;  // Sair do jogo

        if (fazJogada(matriz, x, jogadorAtual)) {
            imprimirMatriz(matriz);
            if (condicaoVitoria(matriz, jogadorAtual)) {
                std::cout << "Jogador " << jogadorAtual << " venceu!" << std::endl;
                break;
            }
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;  // Alterna o jogador
        } else {
            std::cout << "Jogada inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
