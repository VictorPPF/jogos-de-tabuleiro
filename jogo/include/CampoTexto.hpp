#ifndef CAMPOTEXTO_HPP
#define CAMPOTEXTO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class CampoTexto {

    protected:
        void ativar();
        void desativar();
        void adicionarCaractere(char c);
        void removerUltimoCaractere();

        sf::RectangleShape retangulo;
        sf::Text texto;
        sf::Font fonte;
        bool ativo;

    public:
        int deu_enter;
        CampoTexto(float largura, float altura, float posicaoX, float posicaoY);
        
        void limparTexto();
        void desenhar(sf::RenderWindow& window);
        void processarEventos(sf::Event& event, sf::RenderWindow& window);
        std::string obterTexto() const;

};

#endif // CAMPO_TEXTO_HPP
