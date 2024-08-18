#include "../include/JogoReversi.hpp"
#include <iostream>

JogoReversi::JogoReversi(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento) 
: window(window), fonte(fonte), evento(evento),
origemX(260.0), origemY(155.0), qtd_celulaX(8), qtd_celulaY(8), tamanho_celula(60.0), borda(3),
jogadorAtual(1),botaoVoltar(234.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI !", 25.f, false, sf::Color(43, 0, 108)),
tabuleiroREVERSI(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula, borda, evento)

{  
   
    botaoVoltar.criarBotoes();
    circulo.setRadius(tamanho_celula / 2 - borda);
    circulo.setPosition(origemX + tabuleiroREVERSI.indice_i*tamanho_celula + borda, origemY - tamanho_celula);
    circulo.setFillColor(sf::Color(255, 100, 250));

    // Inicializar o tabuleiro com as 4 peças iniciais
    int posicao_meio = qtd_celulaX / 2;
    tabuleiroREVERSI.set_celula_status(posicao_meio, posicao_meio, 1);
    tabuleiroREVERSI.set_celula_status(posicao_meio-1, posicao_meio-1, 1);
    tabuleiroREVERSI.set_celula_status(posicao_meio, posicao_meio-1, 2);
    tabuleiroREVERSI.set_celula_status(posicao_meio-1, posicao_meio, 2);
    
 
    // Criar os jogadores
    //jogador1 = new Jogador(apelido_a);
    //jogador2 = new Jogador(apelido_b);
    //sf::Color cor_jogador1 = sf::Color(102, 0, 102);
    //sf::Color cor_jogador2 = sf::Color(0, 51, 102);  
    jogadorAtual = 1;
}
/*JogoReversi::~JogoReversi() {
    //delete jogador1;
    //delete jogador2;
}*/


bool JogoReversi:: VerificaJogadaDirecao(int x, int y, int dx, int dy, int jogador){
    int adversario = (jogador == 1) ? 2 : 1;
    bool encontrouAdversario = false;
    int i = x + dx;
    int j = y + dy;

    while (i >= 0 && i < 8 && j >= 0 && j < 8) {
        if (tabuleiroREVERSI.get_celula_status(x, y) == adversario) {
            encontrouAdversario = true;
        } else if (tabuleiroREVERSI.get_celula_status(x, y) == jogador) {
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
bool JogoReversi::jogada_valida(int x, int y, int jogador) {
    int direcoes[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    for (auto& direcao : direcoes) {
        if (VerificaJogadaDirecao( x, y, direcao[0], direcao[1], jogador)) {
            return true;
        }
    }
    return false;
}
bool JogoReversi::FazJogada(int x, int y) {
    if (tabuleiroREVERSI.get_celula_status(x, y) != 0) {
        return false;
    }
    bool jogadaEfetuada = false;
    int direcoes[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    for (auto& direcao : direcoes) {
        if (VerificaJogadaDirecao( x, y, direcao[0], direcao[1], jogadorAtual)) {
            int i = x + direcao[0];
            int j = y + direcao[1];
            while (tabuleiroREVERSI.get_celula_status(j, i) != jogadorAtual) {
                tabuleiroREVERSI.set_celula_status(j, i, jogadorAtual);
                i += direcao[0];
                j += direcao[1];
            }
            jogadaEfetuada = true;
        }
    }
    if (jogadaEfetuada) {
       tabuleiroREVERSI.set_celula_status(x, y, jogadorAtual); 
    }
    return jogadaEfetuada;
}

bool JogoReversi:: condicao_vitoria()  {
    bool tabuleiroCheio = true;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (tabuleiroREVERSI.get_celula_status(x, y) == 0) {
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
            if (tabuleiroREVERSI.get_celula_status(x, y) == 0) {
                if (jogada_valida(x, y, jogadorAtual)) {
                    semJogadasParaJogador = false;
                }
                if (jogada_valida(x, y, (jogadorAtual == 1) ? 2 : 1)) {
                    semJogadasParaAdversario = false;
                }
            }
        }
    }
    return tabuleiroCheio || (semJogadasParaJogador && semJogadasParaAdversario);
}
int JogoReversi::Ganhador() {
    int pts_jogador1 = 0;
    int pts_jogador2 = 0;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if ( tabuleiroREVERSI.get_celula_status(x,y)== 1) {
                jogador1++;
            } else if (tabuleiroREVERSI.get_celula_status(x,y) == 2) {
                jogador2++;
            }
        }
    }
    if (jogador1 > jogador2) return 1;
    if (jogador2 > jogador1) return 2;
    return 0;
}

void JogoReversi::acao() {
    if (tabuleiroREVERSI.deuClique) {
        // poe a posição inicial da peça na coluna clicada e no topo do tabuleiro
        circulo.setPosition(origemX + tabuleiroREVERSI.indice_i * tamanho_celula + borda, origemY - tamanho_celula);
        // Executa a função poePeca pra encontrar a posição certa
        if (FazJogada(tabuleiroREVERSI.indice_i, tabuleiroREVERSI.indice_j)) {
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;  // Alterna o jogador
        } else {
            std::cout << "Jogada inválida. Tente novamente." << std::endl;
        }
        //std::cout << "Jogador " << jogadorAtual << " jogou na coluna " << tabuleiroREVERSI.indice_i << std::endl;
        // Troca de jogador
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
        // Reseta o clique
        tabuleiroREVERSI.deuClique = false;
    }
} 


void JogoReversi::LimpaTabuleiro() {
    for(int i=0; i < qtd_celulaX; i++){
        for(int j=0; j < qtd_celulaY; j++){
            tabuleiroREVERSI.matriz[i][j].setEstado(0);
            tabuleiroREVERSI.slots[i][j].botao.setCor(sf::Color(121,122,147));
        }
    }
    circulo.setFillColor(sf::Color(121,122,147));
    // Reinicia a posição do círculo
    circulo.setPosition(origemX + tabuleiroREVERSI.indice_i * tamanho_celula + borda, origemY - tamanho_celula);
    // Reinicia o estado do jogo
    jogadorAtual = 1;
    icupado = 0;
    jocupado = 0;
    fimDeJogo = false;
}

/*void JogoReversi::desenharJogo() {
    Wallpaper wallpaper("wallpaper_reversi.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    JogoReversi::botaoVoltar.desenhar(window);
    JogoReversi::tabuleiroREVERSI.desenhar(window);
    if(condicao_vitoria()) {
        LimpaTabuleiro();
        int ganhador =Ganhador(); 
        fimDeJogo = true;
    }

    acao(); 
}*/
void JogoReversi::desenharJogo() {
    Wallpaper wallpaper("wallpaper_reversi.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    botaoVoltar.desenhar(window);
    tabuleiroREVERSI.desenhar(window);

    // Loop para verificar o status de cada célula e desenhar as bolinhas com a cor correspondente
    for (int i = 0; i < qtd_celulaX; ++i) {
        for (int j = 0; j < qtd_celulaY; ++j) {
            int status = tabuleiroREVERSI.get_celula_status(i, j);

            // Define a cor da bolinha com base no status da célula
            if (status == 0) {
                circulo.setFillColor(sf::Color(121,122,147)); // Cinza
            } else if (status == 1) {
                circulo.setFillColor(sf::Color::Red); // Vermelha
            } else if (status == 2) {
                circulo.setFillColor(sf::Color::Yellow); // Amarela
            }

            // Define a posição da bolinha e a desenha na tela
            circulo.setPosition(origemX + i * tamanho_celula + borda, origemY + j * tamanho_celula + borda);
            window.draw(circulo);
        }
    }

    if (condicao_vitoria()) {
        LimpaTabuleiro();
        int ganhador = Ganhador(); 
        fimDeJogo = true;
    }

    acao(); 
}
