#include <SFML/Graphics.hpp>
#include <windows.h>

#include "../include/Wallpaper.hpp"
#include "../include/ExecutaPartida.hpp"

#include <iostream>
using namespace std;

// Função para desenhar o menu
void desenharMenu(sf::RenderWindow& window, std::string& jogador1, std::string& jogador2){
    Wallpaper wallpaper("menuInicial.png");
    wallpaper.redimensionar(window.getSize());

    // Criação do botao: Largura, altura, posicao x, posicao y, cor (rgb - último número é transparência), conteudo, tamanho da fonte, se for circulo é false, cor fonte
    Botao botaoJogador1(306.f, 49.f, 174.f, 206.f, sf::Color(223, 232, 106, 0), jogador1, 15.f, false);
    botaoJogador1.criarBotoes();

    Botao botaoJogador2(306.f, 49.f, 174.f, 206.f, sf::Color(223, 232, 106, 0), jogador2, 15.f, false);
    botaoJogador2.criarBotoes();

    Botao botaoCadastro(220.f, 65.f, 140.f, 368.f, sf::Color(150, 129, 250), "Cadastro", 25.f, false, sf::Color(43, 0, 108));
    botaoCadastro.criarBotoes();

    Botao botaoListaJogadores(500.f, 65.f, 390.f, 368.f, sf::Color(150, 129, 250), "Lista de Jogadores", 25.f, false, sf::Color(43, 0, 108));
    botaoListaJogadores.criarBotoes();

    Botao botaoExcluirConta(350.f, 65.f, 140.f, 458.f, sf::Color(150, 129, 250), "Excluir Conta", 25.f, false, sf::Color(43, 0, 108));
    botaoExcluirConta.criarBotoes();

    Botao botaoEstatistica(350.f, 65.f, 540.f, 458.f, sf::Color(150, 129, 250), "Estatisticas", 25.f, false, sf::Color(43, 0, 108));
    botaoEstatistica.criarBotoes();

    window.clear();
    wallpaper.desenhar(window);
    botaoJogador1.desenhar(window);
    botaoJogador2.desenhar(window);
    botaoCadastro.desenhar(window);
    botaoListaJogadores.desenhar(window);
    botaoExcluirConta.desenhar(window);
    botaoEstatistica.desenhar(window);
    window.display();

}

int main() {
    //--------------- MÓDULO PARA INICIAR A TELA DO JOGO NAS DIMENSÕES DA TELA DA PESSOA-----------------//
    // Obtém as dimensões da tela
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);
    int screenWidth = screenRect.right - screenRect.left;

    // Define as dimensões da janela
    int windowWidth = 1000;
    int windowHeight = 690;

    // Calcula a posição horizontal centralizada e define a posição vertical no topo da tela
    int windowPosX = (screenWidth - windowWidth) / 2;
    int windowPosY = 0; // Inicia no topo da tela

    // Criação da janela com a posição ajustada
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Deluxe Collection");
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));  // Define a posição da janela

    //---------------------------------------------------------------------------------------------//

    // Flag para controle dos menus
    bool menuInicial = true;
    // Flag para alternar entre os jogadores
    bool isEnteringPlayer1 = true;
    std::string jogador1;
    std::string jogador2;

    // Loop principal do jogo
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            // Fechar a janela
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        // Se está no menuInicial
        if (menuInicial) {
            // Desenha o menu se a flag estiver ativa
            desenharMenu(window, jogador1, jogador2);
        } else {
            // Desenha o conteúdo do jogo
            window.clear();
            window.display();
            menuInicial = false;
        }
    }
    return 0;
}

