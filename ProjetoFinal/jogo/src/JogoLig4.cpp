#include "../include/JogoLig4.hpp"
#include "../include/Wallpaper.hpp"
#include "../include/Jogo.hpp"

JogoLig4::JogoLig4(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento)
    : window(window), fonte(fonte), evento(evento),  origemX(238.0), origemY(166.0), qtd_celulaX(7), qtd_celulaY(6), borda(3),
        tamanho_celula(75.0), fimDeJogo(false), botaoVoltar(150.f, 25.f, 32, 477, sf::Color(235, 64, 52), "DESISTIR!", 15.f, false, sf::Color(89, 7, 1)),
        tabuleiroLIG4 (origemX, origemY, qtd_celulaX, qtd_celulaY, tamanho_celula, borda, evento), jogadorAtual (1), icupado(0), jocupado(0), animando(false) {
    
    botaoVoltar.criarBotoes();
    circulo.setRadius(tamanho_celula / 2 - borda);
    circulo.setPosition(origemX + tabuleiroLIG4.indice_i * tamanho_celula + borda, origemY - tamanho_celula);
    circulo.setFillColor(sf::Color(255, 100, 250));
}

void JogoLig4::desenharJogo() {

    Wallpaper wallpaper("wallpaper_lig4.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    JogoLig4::botaoVoltar.desenhar(window);
    JogoLig4::tabuleiroLIG4.desenhar(window);
    if(verificaCondicaoVitoria(tabuleiroLIG4.indice_i, jocupado - 1)) {

        if(jogadorAtual==2){
            jogador1.vencedor(jogador2.getApelido(), "Lig4");
            nomeVencedor = jogador1.getApelido();
            std::cout << "Jogador " << jogador1.getApelido() << " venceu!" << std::endl;
        }else{
            jogador2.vencedor(jogador1.getApelido(), "Lig4");
            nomeVencedor = jogador2.getApelido();
            std::cout << "Jogador " << jogador2.getApelido() << " venceu!" << std::endl;
        }
        LimpaTabuleiro();
        fimDeJogo = true;
    }
    // window.draw(circulo);
    // circulo.move(0,15);
    acao();
}

void JogoLig4::acao() {
    
    if (tabuleiroLIG4.deuClique && !animando) {
        
        // poe a posição inicial da peça na coluna clicada e no topo do tabuleiro
        circulo.setPosition(origemX + tabuleiroLIG4.indice_i * tamanho_celula + borda, origemY - tamanho_celula);
        // Executa a função FazJogada pra encontrar a posição certa
        FazJogada(tabuleiroLIG4.indice_i, tabuleiroLIG4.indice_j);
        std::cout << "Jogador " << jogadorAtual << " jogou na coluna " << tabuleiroLIG4.indice_i << std::endl;
        
        
        // Troca de jogador
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;

        animando = true;

        // Reseta o clique
        tabuleiroLIG4.deuClique = false;
        std::cout << "Vez do Jogador " << jogadorAtual << std::endl;
    }

    // Chama a função anima para animar a peça caindo
    anima();
}

void JogoLig4::LimpaTabuleiro() {
    for(int i=0; i < qtd_celulaX; i++){
        for(int j=0; j < qtd_celulaY; j++){
            tabuleiroLIG4.matriz[i][j].setEstado(0);
            tabuleiroLIG4.slots[i][j].botao.setCor(sf::Color(121,122,147));
        }
    }
    circulo.setFillColor(sf::Color(121,122,147));
    // Reinicia a posição do círculo
    circulo.setPosition(origemX + tabuleiroLIG4.indice_i * tamanho_celula + borda, origemY - tamanho_celula);
    // Reinicia o estado do jogo
    jogadorAtual = 1;
    icupado = 0;
    jocupado = 0;
    fimDeJogo = false;
}

void JogoLig4::setJogadores(Jogador& player1, Jogador& player2){
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

bool JogoLig4::verificaCondicaoVitoria( int linha, int coluna) {
    // Verificação horizontal
    int contador = 0;
    for (int i = 0; i < qtd_celulaX; ++i) {
        if (tabuleiroLIG4.matriz[i][coluna].getEstado() == jogadorAtual) {
            contador++;
            if (contador == 4) return true;
        } else {
            contador = 0;
        }
    }

    // Verificação vertical
    contador = 0;
    for (int j = 0; j < qtd_celulaY; ++j) {
        if (tabuleiroLIG4.matriz[linha][j].getEstado() == jogadorAtual) {
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
        if (tabuleiroLIG4.matriz[startX][startY].getEstado() == jogadorAtual) {
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
        if (tabuleiroLIG4.matriz[startX][startY].getEstado() == jogadorAtual) {
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

bool JogoLig4::FazJogada(int i, int j) {
    jocupado = 0;

    for (int linha = 0; linha < 6; linha++) {
        if (tabuleiroLIG4.matriz[i][linha].getEstado() != 0) {
            jocupado = linha;
            return true;
        }
        if (linha == 5 && tabuleiroLIG4.matriz[i][linha].getEstado() == 0) {
            jocupado = 6;
            std::cout << "Coluna vazia" << std::endl;
        }
    }
    return false;
}

std::string JogoLig4::getNomeVencedor() const {
    return nomeVencedor;
}

void JogoLig4::anima() {
    if (jocupado != 0 && animando) {
        sf::Color cor = (jogadorAtual == 1) ? sf::Color::Yellow : sf::Color::Red;
        
        circulo.setFillColor(cor);
        

        if (circulo.getPosition().y < (origemY + tamanho_celula * (jocupado - 1) )) {
            
            circulo.move(0, jocupado*6); // move para baixo, você pode ajustar a velocidade
            window.draw(circulo);
            
        } else {
            
            circulo.setPosition(origemX + tabuleiroLIG4.indice_i * tamanho_celula + borda, origemY + tamanho_celula * (jocupado - 1));
            window.draw(circulo);
            //atualiza o estado da peça
            tabuleiroLIG4.matriz[tabuleiroLIG4.indice_i][jocupado - 1].setEstado(jogadorAtual);
            tabuleiroLIG4.slots[tabuleiroLIG4.indice_i][jocupado - 1].botao.setCor(cor);
            animando = false;
        }
    }
}
