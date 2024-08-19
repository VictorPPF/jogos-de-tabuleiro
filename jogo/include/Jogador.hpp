#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <memory> 
#include "Historico.hpp"

class Jogador{
    private:
        std:: string nome;  
        std::string apelido;
        int vitorias_reversi; 
        int derrotas_reversi; 
        int empates_reversi; 
        int vitorias_lig4; 
        int derrotas_lig4; 
        int empates_lig4; 
        std:: string nome_jogo;
        static Historico historico;


    public:
        /**
         * @brief Construtor padrão
         */ 
        Jogador();

        /**
         * @brief Sobecarga de construtor.
         * Construtor que recebe o nome e o apelido e cria um jogador no banco de dados
         * @param String contendo o nome e o apelido do jogador
         */
        Jogador(std:: string _nome, std:: string _apelido); 

        /**
         * @brief Sobrecarga de construtor.
         * Ao receber o apelido, o construtor recebe os dados do jogador que estão no banco de dados
         * e o inicializa.
         * @param String contendo o apelido do jogador
         */
        Jogador(std:: string _apelido); 

        /**
         * @brief Crie o cadastro de um jogador.
         * Testa se é possível criar um novo cadastro, se for, adiciona o jogador no banco de dados
         */
        void criarCadastro();

        /**
         * @brief Muda o nome de um jogador.
         */
        void setNome(std::string _nome); 

        /**
         * @brief Muda o apelido do jogador.
         */
        void setApelido(std::string _apelido); 

        /**
         * @brief Um dos metodos get
         * Recebe o nome do jogador
         * @return Retorna uma string com o nome do jogador
         */
        std::string getNome(); 

        /**
         * @brief Um dos metodos get.
         * Recebe o apelido do jogador
         * @return Retorna uma string com o apelido do jogador
         */
        std::string getApelido();

        /**
         * @brief Define as vitorias, derrotas e empate que um jogador têm naquele jogo.
         */
        void setResultado(std::string _nome_do_jogo, int _vitorias, int _derrotas, int _empates);

        /**
         * @brief Função que dado o vencedor, calcula as novas estatística.
         * Usa o addEstatistica para adicionar vitoria para o jogador que chamou a função e derrota para o outro jogador
         * @param perdedor é a string que contém o nome do jogador que perde, _nome_do_jogo é a string que indica qual é o jogo
         */
        void vencedor(std::string perdedor, std::string _nome_do_jogo);

        /**
         * @brief Função que é responsável pelo empate.
         * Usa o addEstatistica para adicionar as novas estatísticas dos jogadores
         * @param perdedor é a string que contém o nome do outro jogador, _nome_do_jogo é a string que indica qual é o jogo
         */
        void empate(std::string _nome_do_jogo, std::string perdedor);

        /**
         * @brief Função obsoleta que definia as estatisticas dos jogadores.
         * @deprecated Use o vencedor ou empate ao invés disso.
         */
        void setResultado(std::string _nome_do_jogo, std::string ganhador, std::string perdedor,bool empatou);

        /**
         * @brief Função que imprime na tela as estatísticas do jogador.
         */
        void getResultado(); 

        /**
         * @brief Exclui a conta corrente do jogador.
         * Testa se a conta existe, se for verdade a conta é excluída
         */
        void excluirConta();  

        /**
         * @brief Testa se o jogador está no banco de dados.
         * @return Caso o jogador esteja no banco de dados retorna true, se não estiver retorna false 
         */
        bool existeConta();

        /**
         * @brief Um dos metodos get.
         * Consegue o número de vitorias do jogador no jogo Reversi
         * @return Retorna as vitorias do Reversi
         */
        int getVitoriasReversi() const;

        /**
         * @brief Um dos metodos get.
         * Consegue o número de derrotas do jogador no jogo Reversi
         * @return Retorna as derrotas do Reversi
         */
        int getDerrotasReversi() const;

        /**
         * @brief Um dos metodos get.
         * Consegue o número de empates do jogador no jogo Reversi
         * @return Retorna os empates do Reversi
         */
        int getEmpatesReversi() const;


        /**
         * @brief Um dos metodos get.
         * Consegue o número de vitorias do jogador no jogo Lig4
         * @return Retorna as vitorias do Lig4
         */
        int getVitoriasLig4() const;

        /**
         * @brief Um dos metodos get.
         * Consegue o número de derrotas do jogador no jogo Lig4
         * @return Retorna as derrotas do Lig4
         */
        int getDerrotasLig4() const;

        /**
         * @brief Um dos metodos get.
         * Consegue o número de empates do jogador no jogo Lig4
         * @return Retorna os empates do Lig4
         */
        int getEmpatesLig4() const;

}; 



#endif 