#include <iostream>

// Inicializa a matriz com as peças iniciais
void inicializarMatriz(int matriz[8][8]) {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            matriz[y][x] = 0;
        }
    }
    matriz[3][3] = 1;
    matriz[3][4] = 2;
    matriz[4][3] = 2;
    matriz[4][4] = 1;
}

// Imprime a matriz
void imprimirMatriz(const int matriz[8][8]) {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            std::cout << matriz[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

// Verifica peças em uma direção
bool VerificaDirecao(int matriz[8][8], int x, int y, int jogador, int dx, int dy) {
    int adversario = (jogador == 1) ? 2 : 1;
    bool encontrouAdversario = false;
    int i = x + dx;
    int j = y + dy;

    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        if (matriz[j][i] == adversario) {
            encontrouAdversario = true;
        } else if (matriz[j][i] == jogador) {
            if (encontrouAdversario) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
        i += dx;
        j += dy;
    }
    return false;
}

// Faz a jogada e atualiza o tabuleiro
bool FazJogada(int matriz[8][8], int x, int y, int jogador) {
    if (matriz[y][x] != 0) {
        return false;
    }

    bool jogadaEfetuada = false;
    int direcoes[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

    for (auto& direcao : direcoes) {
        if (VerificaDirecao(matriz, x, y, jogador, direcao[0], direcao[1])) {
            int i = x + direcao[0];
            int j = y + direcao[1];
            while (matriz[j][i] != jogador) {
                matriz[j][i] = jogador;
                i += direcao[0];
                j += direcao[1];
            }
            jogadaEfetuada = true;
        }
    }

    if (jogadaEfetuada) {
        matriz[y][x] = jogador;
    }

    return jogadaEfetuada;
}

// Verifica se há jogadas válidas
bool VerificaJogada(int matriz[8][8], int x, int y, int jogador) {
    int direcoes[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    for (auto& direcao : direcoes) {
        if (VerificaDirecao(matriz, x, y, jogador, direcao[0], direcao[1])) {
            return true;
        }
    }
    return false;
}

// Verifica condições de vitória
bool condicaoDeVitoria(int matriz[8][8], int jogador) {
    bool tabuleiroCheio = true;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (matriz[y][x] == 0) {
                tabuleiroCheio = false;
                break;
            }
        }
        if (!tabuleiroCheio) break;
    }

    bool semJogadasParaJogador = true;
    bool semJogadasParaAdversario = true;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (matriz[y][x] == 0) {
                if (VerificaJogada(matriz, x, y, jogador)) {
                    semJogadasParaJogador = false;
                }
                if (VerificaJogada(matriz, x, y, (jogador == 1) ? 2 : 1)) {
                    semJogadasParaAdversario = false;
                }
            }
        }
    }

    return tabuleiroCheio || (semJogadasParaJogador && semJogadasParaAdversario);
}

// Calcula o ganhador
int Ganhador(int matriz[8][8]) {
    int jogador1 = 0;
    int jogador2 = 0;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (matriz[y][x] == 1) {
                jogador1++;
            } else if (matriz[y][x] == 2) {
                jogador2++;
            }
        }
    }
    if (jogador1 > jogador2) return 1;
    if (jogador2 > jogador1) return 2;
    return 0;
}

// Função principal
int main() {
    int matriz[8][8];
    inicializarMatriz(matriz);
    int jogador = 1;  // Jogador 1 começa

    while (true) {
        imprimirMatriz(matriz);
        int x, y;
        std::cout << "Jogador " << jogador << ", insira as coordenadas (x y): ";
        std::cin >> x >> y;
        
        if (x == -1 && y == -1) break;  // Desistir do jogo

        if (FazJogada(matriz, x, y, jogador)) {
            jogador = (jogador == 1) ? 2 : 1;  // Alterna o jogador
        } else {
            std::cout << "Jogada inválida. Tente novamente." << std::endl;
        }

        if (condicaoDeVitoria(matriz, jogador)) {
            std::cout << "Jogador " << jogador << " venceu!" << std::endl;
            break;
        }
    }

    return 0;
}



