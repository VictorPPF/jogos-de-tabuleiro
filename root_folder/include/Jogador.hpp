#include <iostream>
#include <string> 

#ifndef JOGADOR_H
#define JOGADOR_H

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

    public: 
        void criarCadastro(); 
        void setNome(std::string _nome); 
        void setApelido(std::string _apelido); 
        std::string getNome(); 
        std::string getApelido();
        void setResultado(std::string _nome_do_jogo, int _vitorias, int _derrotas, int _empates);
        void getResultado(); 
        void excluirConta();  
}; 

#endif 