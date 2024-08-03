#include <iostream>
#include <string> 
#include <fstream>
#include <vector>

#ifndef HISTORICO_H
#define HISTORICO_H

class Historico{
    private: 
        std::string nome_arquivo;
        std::vector<std::string> cabecalho; 
    public: 
        Historico(); 
        void excluirLinha (); 
        void Editar(); 
        void criarLinha(); 
        void excluirLinha();
        std::string acessarDados(std:: string apelido, std:: string coluna); 
        template<typename T>
        T acessarDados( std::string apelido);  
        void acessarDados( ); 
        //Pensando se não devemos chamar de imprimirDados; 
       

}; 

#endif 