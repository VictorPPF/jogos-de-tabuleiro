#include <iostream>
#include <string> 
#include <fstream>
#include <memory> 
#include "Jogador.hpp"
#include "Historico.hpp" 

//Função para procurar apelidos. 

Jogador:: Jogador(std:: string _nome, std:: string _apelido){
    this->nome = _nome; 
    this-> apelido = _apelido;
    
    
}
Jogador:: Jogador(std:: string _apelido){
    // Acesso ao banco de dados
    // Puxando do banco de dados
    this-> apelido = _apelido; 
}

void Jogador:: criarCadastro(){
    //conferimos a sua validade. 
    vitorias_reversi = 0 ; 
    derrotas_reversi = 0; 
    empates_reversi = 0; 
    vitorias_lig4 = 0; 
    derrotas_lig4 = 0; 
    empates_lig4 = 0; 
    //Comunicar com o banco de dados para criar o cadastro. 
}

void Jogador :: setNome(std::string _nome){
    //Banco de dados 
    nome = _nome; 
}
void  Jogador:: setApelido(std::string _apelido){
    //Banco de dados
    apelido = _apelido; 
}
std::string  Jogador:: getNome(){
    //Banco de dados
    return nome;
}
std::string  Jogador:: getApelido(){
    //Banco de dados
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

//criar um para registrar V e D ou fazer um para J.vitorias += 1 ; 