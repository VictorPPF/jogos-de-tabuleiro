#include "../include/JogoReversi.hpp"
#include <iostream>

JogoReversi::JogoReversi(sf::RenderWindow& window, sf::Font& fonte,int tamanhoTabuleiro, std::string apelido_a, std::string apelido_b) 
: window(window), fonte(fonte),
botaoApelido(502.0f, 49.0f, 327.0f, 217.0f, sf::Color(223, 232, 106, 100), "", 15.0f, false),
botaoVoltar(284.0f, 65.0f, 0.0f, 0.0f, sf::Color(150, 129, 250), "Voltar", 25.0f, false, sf::Color(43, 0, 108)){  
    botaoApelido.criarBotoes();
    botaoVoltar.criarBotoes();
    // Inicializar o tabuleiro com as 4 peças iniciais
    tabuleiro = Tabuleiro(498, 449, tamanhoTabuleiro, tamanhoTabuleiro, 50);
    int posicao_meio = tamanhoTabuleiro / 2;
    tabuleiro.set_celula_status(posicao_meio, posicao_meio, 1);
    tabuleiro.set_celula_status(posicao_meio-1, posicao_meio-1, 1);
    tabuleiro.set_celula_status(posicao_meio, posicao_meio-1, 2);
    tabuleiro.set_celula_status(posicao_meio-1, posicao_meio, 2);

    // Criar os jogadores
    jogador1 = new Jogador(apelido_a);
    jogador2 = new Jogador(apelido_b);
    sf::Color cor_jogador1 = sf::Color(102, 0, 102);
    sf::Color cor_jogador2 = sf::Color(0, 51, 102);  

    jogadorAtual = jogador1;
}

JogoReversi::~JogoReversi() {
    delete jogador1;
    delete jogador2;
}

bool JogoReversi::verificarJogadaValida(int linha, int coluna) {
    bool jogadaValida = false;
    if (linha < 0 || linha >= tabuleiro.get_qtd_celulaX() || coluna < 0 || coluna >= tabuleiro.get_qtd_celulaY()) {
        return jogadaValida;
    }
    if (tabuleiro.get_celula_status(linha, coluna) != 0) {
        return jogadaValida;
    }

    //Logica de 
    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    //Cima, baixo, direita, esquerda, diagonal superior esquerda, diagonal inferior direita, diagonal superior direita, diagonal inferior esquerda

    //Vendo se é o jogador 1 ou 2 que está jogando agora 
    int jogador = jogadorAtual == jogador1 ? 1 : 2;
    int adversario = jogador == 1 ? 2 : 1;

    for (auto& dir : direcoes) {
        int dx = dir[0], dy = dir[1];
        int x = linha + dx, y = coluna + dy;
        bool encontrouAdversario = false;
        while (x >= 0 && x < tabuleiro.get_qtd_celulaX() && y >= 0 && y < tabuleiro.get_qtd_celulaY()) {
            int status = tabuleiro.get_celula_status(x, y);
            if (status == adversario) {
                encontrouAdversario = true;
            } else if (status == jogador && encontrouAdversario) {
                jogadaValida = true;
                break;
            } else {
                break;
            }
            x += dx;
            y += dy;
        }
        if (jogadaValida) break;
    }
    return jogadaValida;
}


void JogoReversi::realizarJogada(int linha, int coluna) {
    if (!verificarJogadaValida(linha, coluna)) return;

    int jogador = jogadorAtual == jogador1 ? 1 : 2;
    int adversario = jogador == 1 ? 2 : 1;
    tabuleiro.set_celula_status(linha, coluna, jogador);

    int direcoes[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    //Cima, baixo, direita, esquerda, diagonal superior esquerda, diagonal inferior direita, diagonal superior direita, diagonal inferior esquerda
    for (auto& dir : direcoes) {
        int dx = dir[0], dy = dir[1];
        int x = linha + dx, y = coluna + dy;
        bool encontrouAdversario = false;
        std::vector<std::pair<int, int>> paraVirar;

        while (x >= 0 && x < tabuleiro.get_qtd_celulaX() && y >= 0 && y < tabuleiro.get_qtd_celulaY()) {
            int status = tabuleiro.get_celula_status(x, y);
            if (status == adversario) {
                paraVirar.push_back({x, y});
                encontrouAdversario = true;
            } else if (status == jogador && encontrouAdversario) {
                for (auto& p : paraVirar) {
                    tabuleiro.set_celula_status(p.first, p.second, jogador);
                }
                break;
            } else {
                break;
            }
            x += dx;
            y += dy;
        }
    }

    jogadorAtual = jogadorAtual == jogador1 ? jogador2 : jogador1;
}

bool JogoReversi::condicao_vitoria() {
    int pontos_jogador1 = 0;
    int pontos_jogador2 = 0;

    for (int i = 0; i < tabuleiro.get_qtd_celulaX(); ++i) {
        for (int j = 0; j < tabuleiro.get_qtd_celulaY(); ++j) {
            int status = tabuleiro.get_celula_status(i, j);
            if (status == 1) pontos_jogador1++;
            if (status == 2) pontos_jogador2++;
        }
    }

    // Verificar se não há mais jogadas válidas
    for (int i = 0; i < tabuleiro.get_qtd_celulaX(); ++i) {
        for (int j = 0; j < tabuleiro.get_qtd_celulaY(); ++j) {
            if (verificarJogadaValida(i, j)) {
                return false; // Ainda há jogadas possíveis
            }
        }
    }

    // Determinar vencedor e imprimir resultado
    if (pontos_jogador1 > pontos_jogador2) {
        std::cout << "Jogador 1 vence com " << pontos_jogador1 << " pontos!" << std::endl;
    } else if (pontos_jogador2 > pontos_jogador1) {
        std::cout << "Jogador 2 vence com " << pontos_jogador2 << " pontos!" << std::endl;
    } else {
        std::cout << "Empate!" << std::endl;
    }
    return true;
}




void desenharJogo() {
        Wallpaper wallpaper("wallpaperflare.jpg");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
        botaoApelido.desenhar(window);
        botaoVoltar.desenhar(window);
        tabuleiro.desenhar(window);
}

void handleEvent(sf::Event& event) {
        //Eu não sei se isso era para estar aqui ou em tabuleiro mas é para me passar a linha e coluna referente ao boltao clicado se houver um
        //Clique 
}
