#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <memory> 
#include "Historico.hpp"

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
        static Historico historico;


    public: 
        Jogador(std:: string _nome, std:: string _apelido); 
        Jogador(std:: string _apelido); 
        void criarCadastro();
        void setNome(std::string _nome); 
        void setApelido(std::string _apelido); 
        std::string getNome(); 
        std::string getApelido();
        void setResultado(std::string _nome_do_jogo, int _vitorias, int _derrotas, int _empates);
        void setResultado(std::string _nome_do_jogo, std::string ganhador, std::string perdedor);
        void setResultado(std::string _nome_do_jogo); 
        void getResultado(); 
        void excluirConta();  

}; 



#endif 