#include "../include/JogoLig4.hpp"
#include "../include/Wallpaper.hpp"

JogoLig4::JogoLig4(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento) : window(window), fonte(fonte), evento(evento),
        origemX(238.0), origemY(166.0), qtd_celulaX(7), qtd_celulaY(6), tamanho_celula(75.0), borda(3), icupado(0), jocupado(0),
        jogadorAtual(1),botaoVoltar(234.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI !", 25.f, false, sf::Color(43, 0, 108)),
        tabuleiroLIG4(origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula, borda, evento)
        
    {
        //circulo(tamanho_celula / 2 - borda, 0, origemX, origemY - tamanho_celula, sf::Color(150, 129, 250), true),
        botaoVoltar.criarBotoes();
        circulo.setRadius(tamanho_celula / 2 - borda);
        circulo.setPosition(origemX + tabuleiroLIG4.indice_i*tamanho_celula + borda, origemY - tamanho_celula);
        circulo.setFillColor(sf::Color(255, 100, 250));

    }

void JogoLig4::acao() {
    if (tabuleiroLIG4.deuClique) {
        // poe a posição inicial da peça na coluna clicada e no topo do tabuleiro
        circulo.setPosition(origemX + tabuleiroLIG4.indice_i * tamanho_celula + borda, origemY - tamanho_celula);
        // Executa a função poePeca pra encontrar a posição certa
        poePeca(tabuleiroLIG4.indice_i, tabuleiroLIG4.indice_j, jogadorAtual);
        std::cout << "Jogador " << jogadorAtual << " jogou na coluna " << tabuleiroLIG4.indice_i << std::endl;
        
        // Verifica a condição de vitória
        if (verificaCondicaoVitoria(jogadorAtual, tabuleiroLIG4.indice_i, jocupado - 1)) {
            std::cout << "Jogador " << jogadorAtual << " venceu!" << std::endl;
            // aqui fica a logica pra TELA DE FIM DE JOGO
            fimDeJogo = true;
        }

        // Troca de jogador
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;

        // Reseta o clique
        tabuleiroLIG4.deuClique = false;
    }

    // Chama a função anima para animar a peça caindo
    anima();
}

void JogoLig4::poePeca(int i, int j, int jogador) {
    jocupado = 0;

    for (int linha = 0; linha < 6; linha++) {
        if (tabuleiroLIG4.matriz[i][linha].getEstado() != 0) {
            jocupado = linha;
            break;
        }
        if (linha == 5 && tabuleiroLIG4.matriz[i][linha].getEstado() == 0) {
            jocupado = 6;
            std::cout << "Coluna vazia" << std::endl;
        }
    }
}

void JogoLig4::anima() {
    if (jocupado != 0) {
        sf::Color cor = (jogadorAtual == 1) ? sf::Color::Yellow : sf::Color::Red;

        circulo.setFillColor(cor);
        

        if (circulo.getPosition().y < (origemY + tamanho_celula * (jocupado - 1) )) {
            circulo.move(0, jocupado*4); // move para baixo, você pode ajustar a velocidade
            window.draw(circulo);
            
        } else {
            //alinha a peça certo com a ultima celula 
            circulo.setPosition(origemX + tabuleiroLIG4.indice_i * tamanho_celula + borda, origemY + tamanho_celula * (jocupado - 1));
            window.draw(circulo);
            //atualiza o estado da peça
            tabuleiroLIG4.matriz[tabuleiroLIG4.indice_i][jocupado - 1].setEstado(jogadorAtual);
            tabuleiroLIG4.slots[tabuleiroLIG4.indice_i][jocupado - 1].botao.setCor(cor);
        }
    }
}

bool JogoLig4::verificaCondicaoVitoria(int jogador, int linha, int coluna) {
    // Verificação horizontal
    int contador = 0;
    for (int i = 0; i < qtd_celulaX; ++i) {
        if (tabuleiroLIG4.matriz[i][coluna].getEstado() == jogador) {
            contador++;
            if (contador == 4) return true;
        } else {
            contador = 0;
        }
    }

    // Verificação vertical
    contador = 0;
    for (int j = 0; j < qtd_celulaY; ++j) {
        if (tabuleiroLIG4.matriz[linha][j].getEstado() == jogador) {
            contador++;
            if (contador == 4) return true;
        } else {
            contador = 0;
        }
    }

    // Verificação diagonal (esquerda para direita)
    contador = 0;
    int startX = std::max(0, linha - coluna);
    int startY = std::max(0, coluna - linha);
    while (startX < qtd_celulaX && startY < qtd_celulaY) {
        if (tabuleiroLIG4.matriz[startX][startY].getEstado() == jogador) {
            contador++;
            if (contador == 4) return true;
        } else {
            contador = 0;
        }
        startX++;
        startY++;
    }

    // Verificação diagonal (direita para esquerda)
    contador = 0;
    startX = std::min(qtd_celulaX - 1, linha + coluna);
    startY = std::max(0, coluna - (qtd_celulaX - 1 - linha));
    while (startX >= 0 && startY < qtd_celulaY) {
        if (tabuleiroLIG4.matriz[startX][startY].getEstado() == jogador) {
            contador++;
            if (contador == 4) return true;
        } else {
            contador = 0;
        }
        startX--;
        startY++;
    }

    return false;
}


void JogoLig4::desenharJogo() {
    Wallpaper wallpaper("wallpaper_lig4.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    JogoLig4::botaoVoltar.desenhar(window);
    JogoLig4::tabuleiroLIG4.desenhar(window);
    // window.draw(circulo);
    // circulo.move(0,15);
    acao();
}
