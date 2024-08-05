#include <SFML/Graphics.hpp>
#include <windows.h>

#include "../include/Wallpaper.hpp"
#include "../include/ExecutaPartida.hpp"
#include <iostream>

using namespace std;



// Função para desenhar o menu
void desenharMenu(sf::RenderWindow& window){
    Wallpaper wallpaper("menuInicial.png");
    wallpaper.redimensionar(window.getSize());

    // Criação do botao: Largura, altura, posicao x, posicao y, cor (rgb - último número é transparência), conteudo, tamanho da fonte, se for circulo é false, cor fonte
    Botao botaoJogador1(306.0, 49.f, 174.0, 206.f, sf::Color(223, 232, 106, 0), "Nick do Jogador 1", 15.f, false);
    botaoJogador1.criarBotoes();

    Botao botaoJogador2(306.0, 49.f, 177.0 + (306.0*1.5), 206.f, sf::Color(223, 232, 106, 0), "Nick do Jogador 2", 15.f, false);
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

int main()
{
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

    // Configurações iniciais de cor e forma
    sf::Color cor(255, 130, 190); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::CircleShape circulo(50.f);
    circulo.setFillColor(sf::Color::Blue);

    // Define a posição inicial do círculo
    circulo.setPosition(0.0, 0.0);

    // Cria dois pontos com coordenadas diferentes
    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);
    
    // Cria um relógio para medir o tempo
    sf::Clock relogio;
    
    PontoF pos3 = pos1 + pos2;

    //cout << pos3 << endl;

    // Cria um objeto Movimentacao para gerenciar o movimento
    Movimentacao movimentacao;

    // Flag para controle dos menus
    bool menuInicial = true;
    // Flag para alternar entre os jogadores
    bool isEnteringPlayer1 = true;
    // std::string jogador1 = "Nick do Jogador1";
    // std::string jogador2 = "Nick do Jogador 2";

    // Roda o programa enquanto a janela estiver aberta
    while (window.isOpen())
    {
        // Checa todos os eventos que ocorreram desde a última iteração do loop
        sf::Event event;
        
        while (window.pollEvent(event)) //pollEvent é uma função que retorna true se houver eventos na fila
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        // Se está no menuInicial
        if (menuInicial) {
        // Desenha o menu se a flag estiver ativa
        desenharMenu(window);
        } else {
            // Desenha o conteúdo do jogo
            window.clear();
            window.display();
            menuInicial = false;
            //window.draw(loginBox.getForma());
            //window.draw(loginBox.getTexto());
            //window.draw(botao1.getForma());
            //window.draw(circulo);
        }
    }
    return 0;
}