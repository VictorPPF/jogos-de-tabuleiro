#include <iostream>
#include <string> 
#include <fstream>
#include "../include/Jogador.hpp"
 

Jogador:: Jogador(std:: string _nome, std:: string _apelido){
    this->nome = _nome; 
    this-> apelido = _apelido; 
    vitorias_reversi = 0 ; 
    derrotas_reversi = 0; 
    empates_reversi = 0; 
    vitorias_lig4 = 0; 
    derrotas_lig4 = 0; 
    empates_lig4 = 0; 
}


void Jogador:: criarCadastro(){
    // Aqui o cadastro é criado, não é onde conferimos a sua validade. 
    // Comunicar com o banco de dados para criar o cadastro. 
    
}

void Jogador :: setNome(std::string _nome){
    nome = _nome; 
}
void  Jogador:: setApelido(std::string _apelido){
    apelido = _apelido; 
}
std::string  Jogador:: getNome(){
    return nome;
}
std::string  Jogador:: getApelido(){
    return apelido; 
}

void Jogador :: setResultado(std::string _nome_do_jogo, int _vitorias, int _derrotas, int _empates){
    if (_nome_do_jogo == "reversi"){
        vitorias_reversi = _vitorias; 
        derrotas_reversi = _derrotas; 
        empates_reversi = _empates; 
    }
    else if (_nome_do_jogo == "lig4"){
        vitorias_lig4 = _vitorias; 
        derrotas_lig4 = _derrotas; 
        empates_lig4 = _empates; 
    }
}
void Jogador:: getResultado(){
    std::cout << "Vitorias reversi: " << vitorias_reversi << std::endl; 
    std::cout << "Derrotas reversi: " << derrotas_reversi << std::endl; 
    std::cout << "Empates reversi: " << empates_reversi << std::endl; 
    std::cout << "Vitorias lig4: " << vitorias_lig4 << std::endl; 
    std::cout << "Derrotas lig4: " << derrotas_lig4 << std::endl; 
    std::cout << "Empates lig4: " << empates_lig4 << std::endl;
    

}
void Jogador:: excluirConta(){
    // Comunicar com o banco de dados

}