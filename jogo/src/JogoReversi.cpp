#include "../include/JogoReversi.hpp"
#include "../include/Jogo.hpp"
#include <iostream>

// construtor da classe JogoReversi, inicializa os componentes do jogo
JogoReversi::JogoReversi(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento)
: window(window), fonte(fonte), evento(evento), 
origemX(260.0), origemY(155.0), qtd_celulaX(8), qtd_celulaY(8), tamanho_celula(60.0), borda(3),
jogadorAtual(1), botaoVoltar(150.f, 25.f, 32, 477, sf::Color(235, 64, 52), "DESISTIR!", 15.f, false, sf::Color(89, 7, 1)),
tabuleiroREVERSI(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula, borda, evento), num_pecas_jogador1(2), num_pecas_jogador2(2),
jogadorDesistiu(false)
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

    // int num_pecas_jogador1 = 2;
    // int num_pecas_jogador2 = 2;
    // imprime de quem é a vez no início do jogo
    //std::cout << "Vez do Jogador " << jogadorAtual << " - Cor: Vermelho" << std::endl;
}  
    
void JogoReversi::contaPeca() {
    num_pecas_jogador1 = 0;
    num_pecas_jogador2 = 0;
    for (int i = 0; i < qtd_celulaX; ++i) {
        for (int j = 0; j < qtd_celulaY; ++j) {
            if (tabuleiroREVERSI.get_celula_status(i,j) == 1) {
                num_pecas_jogador1++;
            }
            if (tabuleiroREVERSI.get_celula_status(i,j) == 2) {
                num_pecas_jogador2++;
            }
        }
    }
    std::cout << "Jogador 1: " << num_pecas_jogador1 << " pecas" << std::endl;
    std::cout << "Jogador 2: " << num_pecas_jogador2 << " pecas" << std::endl;
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
    // executa as ações relacionadas ao clique do jogador
    acao();

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
    if (verificaCondicaoVitoria()) { //uma das duas tem que ser verdadeira
        if(jogadorAtual==2){
            jogador1.vencedor(jogador2.getApelido(), "Lig4");
            nomeVencedor = jogador1.getApelido();
            std::cout << "Jogador " << jogador1.getApelido() << " venceu!" << std::endl;
        }else{
            jogador2.vencedor(jogador1.getApelido(), "Lig4");
            nomeVencedor = jogador2.getApelido();
            std::cout << "Jogador " << jogador2.getApelido() << " venceu!" << std::endl;
        }
        // determina e imprime o ganhador ou se houve empate
        int ganhador = Ganhador();
        // limpa o tabuleiro para um novo jogo
        LimpaTabuleiro();
        
        // Imprime o ganhador (ou empate) no terminal
        if (ganhador == 1) {
            std::cout << "Jogador 1 - Vermelho ("<< jogador1.getApelido() <<") venceu!" <<  std::endl;
            jogador1.vencedor(jogador2.getApelido(), "Reversi");
        } else if (ganhador == 2) {
            std::cout << "Jogador 2 - Amarelo ("<< jogador2.getApelido() <<") venceu!" << std::endl;
            jogador2.vencedor(jogador1.getApelido(), "Reversi");
        } else {
            std::cout << "Empate!" << std::endl;
            jogador1.empate("Lig4",jogador2.getApelido());
        }

        fimDeJogo = true;
    }
}

// executa a ação do jogo quando o jogador clica em uma célula
void JogoReversi::acao() {
    if (tabuleiroREVERSI.deuClique) {
        if (FazJogada(tabuleiroREVERSI.indice_i, tabuleiroREVERSI.indice_j)) {
            // CONTA PEÇASSSSSS
                
            contaPeca();
            // Verifica jogadas válidas para o próximo jogador
            if (!TemJogadasValidas((jogadorAtual == 1) ? 2 : 1)) {
                std::cout << "Vez do Jogador " << jogadorAtual << std::endl;
                std::cout << "Jogador " << ((jogadorAtual == 1) ? 2 : 1) << " não tem jogadas válidas. Verificando para outro jogador..." << std::endl;
                if (!TemJogadasValidas(jogadorAtual)) {
                    std::cout << "Nenhum jogador tem jogadas válidas. Jogo deve terminar ou estado especial deve ser tratado aqui." << std::endl;
                } else {
                    std::cout << "Mantendo a vez do Jogador " << jogadorAtual << std::endl;
                    // Não troca o jogador se o próximo não tem jogadas
                }
            } else {
                // Troca o jogador apenas se o próximo tem jogadas válidas
                jogadorAtual = (jogadorAtual == 1) ? 2 : 1;

                std::cout << "Vez do Jogador " << jogadorAtual << std::endl;
            }
        } else {
            std::cout << "Jogada inválida. Tente novamente." << std::endl;
        }
        tabuleiroREVERSI.deuClique = false; // reseta o clique para não executar múltiplas jogadas
    }
}

// Verifica se o jogador tem jogadas válidas no tabuleiro
bool JogoReversi::TemJogadasValidas(int jogador) {
    for (int i = 0; i < qtd_celulaX; ++i) {
        for (int j = 0; j < qtd_celulaY; ++j) {
            if (jogada_valida(i, j, jogador)) {
                return true;
            }
        }
    }
    return false;
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
    //Reseta o tabuleiro paras condicoes iniciais
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

    num_pecas_jogador1 = 2;
    num_pecas_jogador2 = 2;

    // reseta a vez para o jogador 1
    jogadorAtual = 1;
    // indica que o jogo não está mais no estado de fim de jogo
    //fimDeJogo = false;
    // Reseta a flag de desistência ao reiniciar o jogo
    jogadorDesistiu = false;
}

void JogoReversi::setJogadores(Jogador& player1, Jogador& player2){
    if(player1.existeConta()){
        jogador1=player1;
    }else{
        std::cout << "Erro: Jogador nao existente" << std::endl;
    }
    if(player2.existeConta()){
        jogador2=player2;
    }else{
        std::cout << "Erro: Jogador nao existente" << std::endl;
    }
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


    // Verifica se o jogador tem jogadas válidas
    bool temJogadaValida = false;
    for (int i = 0; i < qtd_celulaX && !temJogadaValida; ++i) {
        for (int j = 0; j < qtd_celulaY && !temJogadaValida; ++j) {
            if (jogada_valida(i, j, jogadorAtual)) {
                temJogadaValida = true;
            }
        }
    }
    
    // Imprime a vez do jogador após a jogada
    std::cout << "Vez do Jogador " << ((jogadorAtual == 1) ? 2 : 1) << " - Cor: "
              << ((jogadorAtual == 1) ? "Amarelo" : "Vermelho") << std::endl;

    // Se o jogador não tiver jogadas válidas, passa a vez 
    if (!temJogadaValida) {
        std::cout << "Jogador " << jogadorAtual << " nao tem jogadas validas. Passando a vez." << std::endl;
        //jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
        return true;
    }
    return true;
}

std::string JogoReversi::getNomeVencedor() const {
    return nomeVencedor;
}

bool JogoReversi::verificaCondicaoVitoria() {
    bool temEspacoVazio = false; // Variável para verificar se há espaços vazios no tabuleiro

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (tabuleiroREVERSI.get_celula_status(x, y) == 0) {
                temEspacoVazio = true; // Se encontrar um espaço vazio, define a variável como true
                if (jogada_valida(x, y, 1) || jogada_valida(x, y, 2)) {
                    return false; // Se houver jogada possível, retorna false (jogo não acabou)
                }
            }
        }
    }

    // Se não encontrou nenhum espaço vazio, o tabuleiro está cheio e o jogo acabou
    if (!temEspacoVazio) {
        return true;
    }

    // Se chegou aqui e jogadorDesistiu é true, o jogo acabou por desistência
    if (jogadorDesistiu) {
        return true;
    }

    // Se chegou aqui, significa que há espaços vazios, mas nenhum jogador pode fazer uma jogada
    return true; // Jogo acabou 
}

// verifica se a jogada em uma célula específica é válidamamke
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

