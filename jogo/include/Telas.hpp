#ifndef TELA_HPP
#define TELA_HPP
#include <SFML/Graphics.hpp>
#include <string>

#include <SFML/Graphics.hpp>
#include "../include/CampoTexto.hpp"
#include "../include/Wallpaper.hpp"
#include "../include/Interacao.hpp"

class TelaMenu {
    private:
        sf::RenderWindow& window; 
        sf::Font& fonte;
        sf::Event& evento; 
        
    public:
        Botao botaoJogador1;
        Botao botaoJogador2;
        Botao botaoListaJogadores;
        Botao botaoCadastro;
        Botao botaoExcluirConta;
        Botao botaoEstatistica;
        Botao play1;
        Botao play2;
        CampoTexto campoJogador1;
        CampoTexto campoJogador2;

        TelaMenu(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
        void desenharMenu();
};

class TelaCadastro {
    private:
        sf::RenderWindow& window; 
        sf::Font& fonte;

    public:
        Botao botaoNome;
        Botao botaoApelido;
        Botao botaoConfirma;
        Botao botaoVoltar;
        CampoTexto campoNome;
        CampoTexto campoApelido;

        TelaCadastro(sf::RenderWindow& window, sf::Font& fonte);
        void desenharJogo();
};

class TelaLista {
    private:
        sf::RenderWindow& window; 
        sf::Font& fonte;

    public:
        Botao botaoVoltar;

        TelaLista(sf::RenderWindow& window, sf::Font& fonte);
        void desenharLista();
};

class TelaExcluirConta {
    private:
        sf::RenderWindow& window; 
        sf::Font& fonte;

    public:
        Botao botaoApelido;
        Botao botaoExcluir;
        Botao botaoVoltar;
        CampoTexto campoApelido;

        TelaExcluirConta(sf::RenderWindow& window, sf::Font& fonte);
        void desenharExcluirConta();
};

class TelaEstatisticas {
    private:
        sf::RenderWindow& window; 
        sf::Font& fonte;

    public:
        Botao botaoApelido;
        Botao botaoVoltar;
        Botao botaoPesquisa;
        CampoTexto campoPesquisa;

        TelaEstatisticas(sf::RenderWindow& window, sf::Font& fonte);
        void desenharEstatisticas();
};

class FimDeJogoLig4 {
    private:
        sf::RenderWindow& window; 
        sf::Font& fonte;

    public:
        Botao botaoMenu;
        Botao botaoRestart;
        FimDeJogoLig4(sf::RenderWindow& window, sf::Font& fonte);
        void desenharTelaFinal();
};

//FimDeJogoRevesi
class FimDeJogoRevesi {
    private:
        sf::RenderWindow& window; 
        sf::Font& fonte;

    public:
        Botao botaoMenu;
        Botao botaoRestart;
        FimDeJogoRevesi(sf::RenderWindow& window, sf::Font& fonte);
        void desenharTelaFinal();
};

#endif // TELA_MENU_HPP
