#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <memory> 
#include "Jogador.hpp"

#ifndef HISTORICO_H
#define HISTORICO_H

class Historico{
    private: 
        std::string nomeArquivo;
        std::vector<std::string> cabecalho; 
    public: 
        Historico(); 
        void excluirLinha (std:: string apelido); 
        void Editar(std:: string apelido, std:: string coluna, std:: string novoDado ); 
        void criarLinha(const class Jogador& jogador); 
        std::string acessarDados(std:: string apelido, std:: string coluna); 
        std:: string acessarDados( std::string apelido);  
        void acessarDados( ); 
        //Pensando se não devemos chamar de imprimirDados; 
       

}; 
#endif 