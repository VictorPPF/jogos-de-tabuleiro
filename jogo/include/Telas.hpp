/**
 * @file Telas.hpp
 * @brief Classe que representa a tela de menu do jogo
 */

#ifndef TELA_HPP
#define TELA_HPP
#include <string>

#include <SFML/Graphics.hpp>
#include "../include/CampoTexto.hpp"
#include "../include/Wallpaper.hpp"
#include "../include/Interacao.hpp"
#include "../include/Historico.hpp"
#include "../include/Jogador.hpp"
/**
 * @class TelaMenu
 */
class TelaMenu {
    private:
        /**
         * @param window referência para a janela onde o jogo será desenhado
         */
        sf::RenderWindow& window; 
        /**
         * @param fonte referência para a fonte usada no jogo
         */
        sf::Font& fonte;
        /**
         * @param evento referência para os eventos de entrada do jogador
         */
        sf::Event& evento; 
        
    public:
        /**
         * @param botaoJogador1 botão para inserir o nome do jogador 1
         */
        Botao botaoJogador1;
        /**
         * @param botaoJogador2 botão para inserir o nome do jogador 2
         */
        Botao botaoJogador2;
        /**
         * @param botaoListaJogadores botão para acessar a lista de jogadores
         */
        Botao botaoListaJogadores;
        /**
         * @param botaoCadastro botão para acessar a tela de cadastro
         */
        Botao botaoCadastro;
        /**
         * @param botaoExcluirConta botão para acessar a tela de exclusão de conta
         */
        Botao botaoExcluirConta;
        /**
         * @param botaoEstatistica botão para acessar a tela de estatísticas
         */
        Botao botaoEstatistica;
        /**
         * @param play1 botão para sair do jogo
         */
        Botao play1;
        /**
         * @param play2 botão para iniciar o jogo
         */
        Botao play2;
        /**
         * @param campoJogador1 campo de texto para inserir o nome do jogador 1
         */
        CampoTexto campoJogador1;
        /**
         * @param campoJogador2 campo de texto para inserir o nome do jogador 2
         */
        CampoTexto campoJogador2;
        /**
         * @brief Tela Menu é o construtor da classe
         */
        TelaMenu(sf::RenderWindow& window, sf::Font& fonte, sf::Event& evento);
        void desenharMenu();
};

class TelaCadastro {
    private:
        /** 
         * @param window referência para a janela onde o jogo será desenhado
        */
        sf::RenderWindow& window; 
        /**
         * @param fonte referência para a fonte usada no jogo
         */
        sf::Font& fonte;

    public:
        /**
        * @param botaoNome botão para inserir o nome do jogador
        */
        Botao botaoNome;
        /**
         * @param botaoApelido botão para inserir o apelido do jogador
         */
        Botao botaoApelido;
        /**
         * @param botaoConfirma botão para confirmar o cadastro
         */
        Botao botaoConfirma;
        /**
         * @param botaoVoltar botão para voltar ao menu
         */
        Botao botaoVoltar;
        /**
         * @param campoNome campo de texto para inserir o nome do jogador
         */
        CampoTexto campoNome;
        /**
         * @param campoApelido campo de texto para inserir o apelido do jogador
         */
        CampoTexto campoApelido;
        /**
         * @brief TelaCadastro é o construtor da classe
         */
        TelaCadastro(sf::RenderWindow& window, sf::Font& fonte);
        /**
         * @brief desenharJogo é o método para desenhar a tela de cadastro
         * @return void
         */
        void desenharJogo();
};

class TelaLista {
    private:
        /** 
         * @param window referência para a janela onde o jogo será desenhado
         */
        sf::RenderWindow& window; 
        /**
         * @param fonte referência para a fonte usada no jogo
         */
        sf::Font& fonte;

    public:
        /** 
         * @param botaoVoltar botão para voltar ao menu
         */
        Botao botaoVoltar;
        /**
         * @param historico objeto que representa o histórico do jogo
         */
        Historico historico;
        /**
         * @param jogadores vertor de strings que contém os jogadores cadastrados
         */
        std::vector<std::string> jogadores;
        /**
         * @brief TelaLista é o construtor da classe
         */
        TelaLista(sf::RenderWindow& window, sf::Font& fonte);
        /**
         * @brief carregarDadosJogadores é o método para carregar os dados dos jogadores
         * @return vetor de strings com os jogadores cadastrados
         */
        std::vector<std::string> carregarDadosJogadores();
        /**
         * @brief desenharJogadores é o método para desenhar os jogadores na tela
         * @return void
         */
        void desenharJogadores();
        /**
         * @brief desenharLista é o método para desenhar a lista de jogadores
         * @return void
         */
        void desenharLista();
};

class TelaExcluirConta {
    private:
        /**
         * @param window referência para a janela onde o jogo será desenhado
         */
        sf::RenderWindow& window; 
        /**
         * @param fonte referência para a fonte usada no jogo
         */
        sf::Font& fonte;

    public:
        /**
         * @param botaoApelido botão para inserir o apelido do jogador
         */
        Botao botaoApelido;
        /**
         * @param botaoExcluir botão para excluir a conta do jogador
         */
        Botao botaoExcluir;
        /**
         * @param botaoVoltar botão para voltar ao menu
         */
        Botao botaoVoltar;
        /**
         * @param campoApelido campo de texto para inserir o apelido do jogador
         */
        CampoTexto campoApelido;
        /**
         * @brief TelaExcluirConta é o construtor da classe
         */
        TelaExcluirConta(sf::RenderWindow& window, sf::Font& fonte);
        /**
         * @brief desenharExcluirConta é o método para desenhar a tela de exclusão de conta
         * @return void
         */
        void desenharExcluirConta();
        /**
         * @brief excluirConta é o método para excluir a conta do jogador
         */
};

class TelaEstatisticas {
    private:
        /**
         * @param window referência para a janela onde o jogo será desenhado
         */
        sf::RenderWindow& window; 
        /**
         * @param fonte referência para a fonte usada no jogo
         */
        sf::Font& fonte;

    public:
        /**
         * @param botaoApelido botão para inserir o apelido do jogador
         */
        Botao botaoApelido;
        /**
         * @param botaoVoltar botão para voltar ao menu
         */
        Botao botaoVoltar;
        /**
         * @param botaoPesquisa botão para pesquisar as estatísticas do jogador
         */
        Botao botaoPesquisa;
        /**
         * @param campoPesquisa campo de texto para inserir o apelido do jogador
         */
        CampoTexto campoPesquisa;
        /**
         * @param jogador objeto que representa o jogador
         */
        Jogador jogador;
        /**
         * @brief TelaEstatisticas é o construtor da classe
         */
        TelaEstatisticas(sf::RenderWindow& window, sf::Font& fonte);
        /**
         * @brief desenharTexto é o método para desenhar o texto na tela
         */
        void desenharTexto(const std::string& texto, float x, float y, float tamanho, sf::Color cor);
        /**
         * @brief desenharEstatisticas é o método para desenhar as estatísticas do jogador
         */
        void setJogador(const Jogador& jogador);
        /**
         * @brief desenharEstatisticas é o método para desenhar as estatísticas do jogador
         */
        void desenharEstatisticas();
};

class FimDeJogoLig4 {
    private:
        /**
         * @param window referência para a janela onde o jogo será desenhado
         */
        sf::RenderWindow& window; 
        /**
         * @param fonte referência para a fonte usada no jogo
         */
        sf::Font& fonte;
        /**
         * @param textoVencedor texto que indica o vencedor do jogo
         */
        sf::Text textoVencedor;
        
    public:
        /**
         * @param botaoMenu botão para voltar ao menu
         */
        Botao botaoMenu;
        /**
         * @param botaoRestart botão para reiniciar o jogo
         */
        Botao botaoRestart;
        /**
         * @brief FimDeJogoLig4 é o construtor da classe
         */
        FimDeJogoLig4(sf::RenderWindow& window, sf::Font& fonte);
        /**
         * @brief desenharTelaFinal é o método para desenhar a tela final do jogo
         */
        void desenharTelaFinal(const std::string& nomeVencedor);
};

//FimDeJogoRevesi
class FimDeJogoRevesi {
    private:
        /**
         * @param window referência para a janela onde o jogo será desenhado
         */
        sf::RenderWindow& window; 
        /**
         * @param fonte referência para a fonte usada no jogo
         */
        sf::Font& fonte;
        /**
         * @param textoVencedor texto que indica o vencedor do jogo
         */
        sf::Text textoVencedor;

    public:
        /**
         * @param botaoMenu botão para voltar ao menu
         */
        Botao botaoMenu;
        /**
         * @param botaoRestart botão para reiniciar o jogo
         */
        Botao botaoRestart;
        /**
         * @brief FimDeJogoRevesi é o construtor da classe
         */
        FimDeJogoRevesi(sf::RenderWindow& window, sf::Font& fonte);
        /**
         * @brief desenharTelaFinal é o método para desenhar a tela final do jogo
         * @return void
         */
        void desenharTelaFinal(const std::string& nomeVencedor);
};

#endif // TELA_MENU_HPP
