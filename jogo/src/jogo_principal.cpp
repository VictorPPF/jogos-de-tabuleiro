#include <SFML/Graphics.hpp>
#include "../include/ExecutaPartida.hpp"
#include <iostream>

using namespace std;

// Fonte global
sf::Font font;

int main()
{
    // Configuração inicial da janela do jogo
    float res_x = 1000.0f;
    float res_y = 650.0f;
    sf::RenderWindow window(sf::VideoMode(res_x, res_y), "Deluxe Edition");

    // Carregamento da fonte apenas uma vez
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erro ao carregar a fonte 'arial.ttf'" << std::endl;
        return -1;
    }

    // Configurações iniciais de cor e forma
    sf::Color cor(255, 130, 190); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::CircleShape circulo(50.f);
    circulo.setFillColor(sf::Color::Blue);
    circulo.setPosition(0.0, 0.0);

    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);
    
    sf::Clock relogio;
    
    PontoF pos3 = pos1 + pos2;

    //cout << pos3 << endl;

    Movimentacao movimentacao;
    // Roda o programa enquanto a janela estiver aberta
    while (window.isOpen())
    {
        // checa todos os eventos que ocorreram desde a última iteração do loop
        sf::Event event;
        
        while (window.pollEvent(event)) //pollEvent é uma função que retorna true se houver eventos na fila
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Obtenha a posição do mouse relativa à janela
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        }
        
        window.clear(cor);
        //window.draw(loginBox.getForma());
        //window.draw(loginBox.getTexto());
        //window.draw(botao1.getForma());
        window.draw(circulo);
        window.display();
    }

    return 0;
}