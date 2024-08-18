#include "../include/JogoReversi.hpp"
#include <iostream>

// construtor da classe JogoReversi, inicializa os componentes do jogo
JogoReversi::JogoReversi(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento)
: window(window), fonte(fonte), evento(evento),
origemX(260.0), origemY(155.0), qtd_celulaX(8), qtd_celulaY(8), tamanho_celula(60.0), borda(3),
jogadorAtual(1), botaoVoltar(234.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI !", 25.f, false, sf::Color(43, 0, 108)),
tabuleiroREVERSI(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula, borda, evento) 
{
    // cria o botão "Desisti" na tela
    botaoVoltar.criarBotoes();

    // define a posição inicial das peças no centro do tabuleiro
    int posicao_meio = qtd_celulaX / 2; 
    tabuleiroREVERSI.set_celula_status(posicao_meio, posicao_meio, 1); 
    tabuleiroREVERSI.set_celula_status(posicao_meio-1, posicao_meio-1, 1);
    tabuleiroREVERSI.set_celula_status(posicao_meio, posicao_meio-1, 2);
    tabuleiroREVERSI.set_celula_status(posicao_meio-1, posicao_meio, 2);

    // define as cores das peças iniciais no tabuleiro
    tabuleiroREVERSI.slots[posicao_meio][posicao_meio].botao.setCor(sf::Color::Red);
    tabuleiroREVERSI.slots[posicao_meio-1][posicao_meio-1].botao.setCor(sf::Color::Red);
    tabuleiroREVERSI.slots[posicao_meio][posicao_meio-1].botao.setCor(sf::Color::Yellow);
    tabuleiroREVERSI.slots[posicao_meio-1][posicao_meio].botao.setCor(sf::Color::Yellow);

    // imprime de quem é a vez no início do jogo
    std::cout << "Vez do Jogador " << jogadorAtual << " - Cor: Vermelho" << std::endl;
}

// verifica se uma jogada é válida em uma direção específica
bool JogoReversi::VerificaJogadaDirecao(int x, int y, int dx, int dy, int jogador) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return false; // // verifica se os índices estão dentro dos limites do tabuleiro
    int adversario = (jogador == 1) ? 2 : 1; // define o jogador adversário
    bool encontrouAdversario = false;
    int i = x + dx;
    int j = y + dy;

    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        if (tabuleiroREVERSI.get_celula_status(i, j) == adversario) {
            encontrouAdversario = true;
        } else if (tabuleiroREVERSI.get_celula_status(i, j) == jogador && encontrouAdversario) {
            return true; // retorna true somente se encontrou uma peça do adversário antes
        } else {
            return false; // se encontrar uma célula vazia ou uma peça do mesmo jogador sem ter encontrado uma peça do adversário, retorna false
        }
        i += dx;
        j += dy;
    }
    return false; // retorna false se não encontrar uma jogada válida na direção
}

// verifica se a jogada em uma célula específica é válida
bool JogoReversi::jogada_valida(int x, int y, int jogador) {
    int direcoes[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    for (auto& direcao : direcoes) {
        if (tabuleiroREVERSI.get_celula_status(x, y) != 0) continue; /// se a célula já estiver ocupada, pula para a próxima direção
        if (VerificaJogadaDirecao(x, y, direcao[0], direcao[1], jogador)) {
            return true;
        }
    }
    return false;
}

// realiza a jogada e altera as peças do tabuleiro, se for válida
bool JogoReversi::FazJogada(int x, int y) {
    if (!jogada_valida(x, y, jogadorAtual)) return false; // verifica se a jogada é válida

    int direcoes[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    for (auto& direcao : direcoes) {
        if (VerificaJogadaDirecao(x, y, direcao[0], direcao[1], jogadorAtual)) {
            int i = x + direcao[0];
            int j = y + direcao[1];
            // altera as peças do adversário até encontrar uma peça do próprio jogador
            while (tabuleiroREVERSI.get_celula_status(i, j) != jogadorAtual) {
                tabuleiroREVERSI.set_celula_status(i, j, jogadorAtual);
                tabuleiroREVERSI.slots[i][j].botao.setCor(jogadorAtual == 1 ? sf::Color::Red : sf::Color::Yellow);
                i += direcao[0];
                j += direcao[1];
            }
        }
    }
    // coloca a peça do jogador na célula onde ele fez a jogada
    tabuleiroREVERSI.set_celula_status(x, y, jogadorAtual);
    tabuleiroREVERSI.slots[x][y].botao.setCor(jogadorAtual == 1 ? sf::Color::Red : sf::Color::Yellow);
    // Imprime a vez do jogador após a jogada
    std::cout << "Vez do Jogador " << ((jogadorAtual == 1) ? 2 : 1) << " - Cor: "
              << ((jogadorAtual == 1) ? "Amarelo" : "Vermelho") << std::endl;
    return true;
}

// executa a ação do jogo quando o jogador clica em uma célula
void JogoReversi::acao() {
    if (tabuleiroREVERSI.deuClique) {
        if (FazJogada(tabuleiroREVERSI.indice_i, tabuleiroREVERSI.indice_j)) {
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1; // troca o turno entre os jogadores
        } else {
            std::cout << "Jogada inválida. Tente novamente." << std::endl;
        }
        tabuleiroREVERSI.deuClique = false; // reseta o clique para não executar múltiplas jogadas
    }
}

bool JogoReversi::condicao_vitoria() {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (tabuleiroREVERSI.get_celula_status(x, y) == 0 &&
                (jogada_valida(x, y, 1) || jogada_valida(x, y, 2))) {
                return false;
            }
        }
    }
    return true; // se não houver jogadas válidas, o jogo termina
}

// calcula e retorna o ganhador com base na quantidade de peças de cada jogador
int JogoReversi::Ganhador() {
    int pts_jogador1 = 0;
    int pts_jogador2 = 0;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (tabuleiroREVERSI.get_celula_status(x, y) == 1) {
                pts_jogador1++;
            } else if (tabuleiroREVERSI.get_celula_status(x, y) == 2) {
                pts_jogador2++;
            }
        }
    }
    // retorna o jogador com mais peças
    return (pts_jogador1 > pts_jogador2) ? 1 : (pts_jogador2 > pts_jogador1) ? 2 : 0;
}

// limpa o tabuleiro e reseta o jogo
void JogoReversi::LimpaTabuleiro() {
    // percorre todas as células do tabuleiro
    for (int i = 0; i < qtd_celulaX; ++i) {
        for (int j = 0; j < qtd_celulaY; ++j) {
            // define o estado de cada célula como vazio (0)
            tabuleiroREVERSI.set_celula_status(i, j, 0);
            // redefine a cor do botão associado à célula para a cor padrão (cinza)
            tabuleiroREVERSI.slots[i][j].botao.setCor(sf::Color(121, 122, 147));
        }
    }
    // reseta a vez para o jogador 1
    jogadorAtual = 1;
    // indica que o jogo não está mais no estado de fim de jogo
    fimDeJogo = false;
}

// desenha o estado atual do jogo na tela
void JogoReversi::desenharJogo() {
    // desenha o papel de parede do jogo
    Wallpaper wallpaper("wallpaper_reversi.png");
    wallpaper.redimensionar(window.getSize());
    wallpaper.desenhar(window);

    // desenha o botão de "Desistir"
    botaoVoltar.desenhar(window);
    tabuleiroREVERSI.desenhar(window);

    // loop para destacar as jogadas válidas para o jogador atual
    for (int i = 0; i < qtd_celulaX; ++i) {
        for (int j = 0; j < qtd_celulaY; ++j) {
            if (jogada_valida(i, j, jogadorAtual)) {
                // se a jogada for válida, pinta a célula com uma cor diferente para indicar que é possível jogar ali
                tabuleiroREVERSI.slots[i][j].botao.setCor(sf::Color(217, 233, 151,100));

            } else if (tabuleiroREVERSI.get_celula_status(i, j) == 0) {
                // se a célula estiver vazia e não for uma jogada válida, pinta com a cor padrão (cinza)
                tabuleiroREVERSI.slots[i][j].botao.setCor(sf::Color(121, 122, 147)); // cor padrão
            }
        }
    }
    // verifica se o jogo terminou
    if (condicao_vitoria()) {
        // limpa o tabuleiro para um novo jogo
        LimpaTabuleiro();
        // determina e imprime o ganhador ou se houve empate
        int ganhador = Ganhador();
        fimDeJogo = true;
        // Imprime o ganhador (ou empate) no terminal
        if (ganhador == 1) {
            std::cout << "Jogador 1 (Vermelho) venceu!" << std::endl;
        } else if (ganhador == 2) {
            std::cout << "Jogador 2 (Amarelo) venceu!" << std::endl;
        } else {
            std::cout << "Empate!" << std::endl;
        }
    }

    // executa as ações relacionadas ao clique do jogador
    acao();
}