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
        std::string nomeArquivo;
        std::vector<std::string> cabecalho;
    public: 
        Historico();
        void excluirLinha (std:: string apelido); 
        void Editar(std:: string apelido, std:: string coluna, std:: string novoDado ); 
        //void criarLinha(const class Jogador& jogador); 
        void criarLinha();
        std::string acessarDados(std:: string apelido, std:: string coluna); 
        std:: string acessarDados( std::string apelido);  
        void acessarDados( ); 
        //Pensando se não devemos chamar de imprimirDados; 
        
        bool addEstatistica(std:: string apelido, std:: string coluna); //Retorna 0 se ok -- Incompleto, preciso saber como o arquivo .csv vai ficar
       

}; 
#endif 