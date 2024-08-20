/**
 * @file CampoTexto.hpp
 * @brief Definição da classe CampoTexto que representa um campo de texto na interface gráfica.
 */

#ifndef CAMPOTEXTO_HPP
#define CAMPOTEXTO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

/**
 * @class CampoTexto
 * @brief Classe que representa um campo de texto interativo, permitindo entrada e exibição de texto.
 * 
 * Esta classe gerencia a entrada de texto, a renderização e o estado do campo de texto na tela.
 */

class CampoTexto {

    protected:
        /**
         * @brief Ativa o campo de texto, permitindo a entrada de texto.
         */
        void ativar();
        /**
         * @brief Desativa o campo de texto, desabilitando a entrada de texto.
         */
        void desativar();
        /**
         * @brief Adiciona um caractere ao texto atual.
         * @param c O caractere a ser adicionado.
         */
        void adicionarCaractere(char c);
        /**
         * @brief Remove o último caractere do texto atual.
         */
        void removerUltimoCaractere();

        sf::RectangleShape retangulo; ///< Forma retangular que representa o campo de texto.
        sf::Text texto; ///< Objeto de texto para exibir o texto no campo.
        sf::Font fonte; ///< Fonte usada para renderizar o texto.
        bool ativo; ///< Indica se o campo de texto está ativo ou não.

    public:
        int deu_enter; ///< Indica se a tecla Enter foi pressionada.
        /**
         * @brief Construtor da classe CampoTexto.
         * @param largura Largura do campo de texto.
         * @param altura Altura do campo de texto.
         * @param posicaoX Posição X do campo de texto.
         * @param posicaoY Posição Y do campo de texto.
         */
        CampoTexto(float largura, float altura, float posicaoX, float posicaoY);

        /**
         * @brief Limpa o texto no campo de texto.
         */
        
        void limparTexto();
        /**
         * @brief Desenha o campo de texto na janela.
         * @param window A janela na qual o campo de texto será desenhado.
         */
        void desenhar(sf::RenderWindow& window);
        /**
         * @brief Processa eventos relacionados ao campo de texto, como entrada de teclado.
         * @param event O evento a ser processado.
         * @param window A janela onde o evento ocorre.
         */
        void processarEventos(sf::Event& event, sf::RenderWindow& window);
        /**
         * @brief Obtém o texto atual do campo de texto.
         * @return O texto no campo de texto.
         */
        std::string obterTexto() const;
};

#endif // CAMPO_TEXTO_HPP
