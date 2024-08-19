#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <memory> 
//#include "Jogador.hpp"


class Historico{
    private: 
        /**
         * @param nomeArquivo: variável que guarda o nome do arquivo que guarda as informações
         */
        std::string nomeArquivo;

        /**
         * @param cabecalho: vetor de string que guarda o cabeçalho do arquivo, indicando os jogos, vitórias, derrotas, etc...
         */
        std::vector<std::string> cabecalho;
    public: 
        /**
         * @brief Construtor da classe Historico
         * Faz um arquivo escrevendo o cabeçalho, caso o arquivo nao exista, caso exista ele o abre
         */
        Historico();

        /**
         * @brief Função responsável por excluir linha do banco de dados
         * Essa função copia todas as linhas, menos a que será excluida, em um arquivo auxiliar, apaga o original e renomeia o auxiliar
         */
        void excluirLinha (std:: string apelido); 

        /**
         * @brief Função responsável por editar os dados
         * Essa função copia todas as linhas em um arquivo auxiliar, mudando apenas o dado na posicao estabelecida pelo apelido e coluna, 
         * apaga o arquivo original e renomeia o auxiliar
         */
        void Editar(std:: string apelido, std:: string coluna, std:: string novoDado); 

        /**
         * @brief Função responsável por adicionar dados
         * Adiciona  mais uma linha ao arquivo csv com base em um vector de strings com os dados referente a cada campo
         */
        void criarLinha(const std::vector<std::string>& dados); 

        /**
         * @brief Função que acessa dados específicos
         * Acessa um dado específico ditado pelo apelido e coluna, se ele não achar o apelido ela retorna -1
         * @param String contendo o nome do jogador e outra string indicando o tipo de dado
         * @return String de dado específico, caso exista, caso contrário retorna -1
         */
        std::string acessarDados(std:: string apelido, std:: string coluna); 

        /**
         * @brief Função que acessa dados gerais
         * Acessa todos os datos do jogador ditado pelo apelido, se ele não achar o apelido ela retorna -1
         * @param String contendo o nome do jogador
         * @return String de dados contendo todas as informações daquele jogador, caso exista, caso contrário retorna -1
         */   
        std:: string acessarDados( std::string apelido);  

        /**
         * @brief Função que acessa todos os dados
         * Acessa todos os dados e os escreve na tela
         */
        void acessarDados( ); 
        
        /**
         * @brief Função que adiciona estatística para o jogador
         * Acessa um jogador ditado pelo apelido e aumenta em 1 a estatística passada como parâmetro
         * @param String contendo o nome do jogador e outra string indicando o tipo de dado que terá seu valor aumentado em 1
         */
        void addEstatistica(std:: string apelido, std:: string coluna);

        /**
         * @brief Função que retorna o nome do arquivo
         * Acessa a variável contendo o nome do arquivo e a retorna como string
         * @return String contendo o nome do arquivo
         */   
        std::string getNomeArquivo() const;
       

}; 
#endif 