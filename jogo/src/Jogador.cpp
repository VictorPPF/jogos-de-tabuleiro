#include <iostream>
#include <sstream>
#include <string> 
#include <fstream>
#include <memory> 
#include "../include/Jogador.hpp"
//#include "../include/Historico.hpp" 

// Inicialização do histórico (Era isso que você estava falando ?)
Historico Jogador::historico;

Jogador::Jogador(){
}

Jogador:: Jogador(std:: string _nome, std:: string _apelido){
    try{
    //Cria um jogador do zero
    this->nome = _nome; 
    this-> apelido = _apelido;
    vitorias_reversi = 0 ; 
    derrotas_reversi = 0; 
    empates_reversi = 0; 
    vitorias_lig4 = 0; 
    derrotas_lig4 = 0;
    empates_lig4 = 0; 
    criarCadastro();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar jogador: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }
}

Jogador:: Jogador(std:: string _apelido){
    // Acesso ao arquivo csv
    // Puxando do arquivo csv o jogador com o apelido _apelido
    //this->apelido = _apelido;
    try {
    std::string dadosJogador = historico.acessarDados(_apelido);
    if (dadosJogador != "-1") {
        std::stringstream ss(dadosJogador);
        std::string string_aux;
        getline(ss, apelido, ';');
        getline(ss, nome, ';');
        getline(ss, string_aux, ';');
        vitorias_reversi = std::stoi(string_aux);
        getline(ss, string_aux, ';');
        derrotas_reversi = std::stoi(string_aux);
        getline(ss, string_aux, ';');
        empates_reversi = std::stoi(string_aux);
        getline(ss, string_aux, ';');
        vitorias_lig4 = std::stoi(string_aux);
        getline(ss, string_aux, ';');
        derrotas_lig4 = std::stoi(string_aux);
        getline(ss, string_aux, ';');
        empates_lig4 = std::stoi(string_aux);

        // ss >> vitorias_reversi >> derrotas_reversi >> empates_reversi;
        // ss >> vitorias_lig4 >> derrotas_lig4 >> empates_lig4;
    } else {
        std::cout << "Erro: Apelido não encontrado no histórico." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar jogador a partir do apelido: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }
}
void Jogador:: criarCadastro(){
    //Comunicar com o arquivo csv para criar o cadastro. (Deve ser chamada no Jogador(nome, apelido))
    //Nessa função conferimos a se o apelido já existe. 
    try {
    if (historico.acessarDados(apelido) != "-1") {
        std::cout << "Erro: Apelido ja existente no historico." << std::endl;
        return;
    }
    std::vector<std::string> dados = {apelido, nome, "0", "0", "0", "0", "0", "0"};
    historico.criarLinha(dados);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar cadastro: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }
}

void Jogador :: setNome(std::string _nome){
    //muda o nome do jogador nele e no arquivo csv
    try {
    nome = _nome;
    historico.Editar(apelido, "Nome", _nome);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao definir nome: " << e.what() << std::endl;
        throw;
    }
}
void  Jogador:: setApelido(std::string _apelido){
    //muda o apelido do jogador nele e no arquivo csv
    try {
    historico.Editar(apelido, "Apelido", _apelido);
    apelido = _apelido;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao definir apelido: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }
}
std::string  Jogador:: getNome(){
    //acessa o jogador apenas já que ele já está puxado do arquivo csv
    return nome;
}
std::string  Jogador:: getApelido(){
    //acessa o jogador apenas já que ele já está puxado do arquivo csv
    return apelido; 
}

void Jogador :: setResultado(std::string _nome_do_jogo, int _vitorias, int _derrotas, int _empates){
    //Aqui é para a gente mudar os resultados do jogador no arquivo csv
    //Jogador
    try {
    if (_nome_do_jogo == "Reversi") {
        vitorias_reversi = _vitorias; 
        derrotas_reversi = _derrotas; 
        empates_reversi = _empates; 
    } else if (_nome_do_jogo == "Lig4") {
        vitorias_lig4 = _vitorias; 
        derrotas_lig4 = _derrotas; 
        empates_lig4 = _empates; 
    }else{
        std::cout<< "Erro: Nao existe esse jogo!\n";
    }

    //Histórico
    // posso fazer isso? 
    historico.Editar(apelido, "Vitorias " + _nome_do_jogo, std::to_string(_vitorias));
    historico.Editar(apelido, "Derrotas " + _nome_do_jogo, std::to_string(_derrotas));
    historico.Editar(apelido, "Empates " + _nome_do_jogo, std::to_string(_empates));

    } catch (const std::exception& e) {
        std::cerr << "Erro ao definir resultado: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }
}

//Eu queria fazer essas próximas duas funções com sobrecarga de operadores, mas não sei se ficaria bom:

void Jogador::setResultado(std::string _nome_do_jogo, std::string ganhador, std::string perdedor, bool empatou){
    try {
        if(empatou){
            historico.addEstatistica(ganhador, "Empates " + _nome_do_jogo);
            historico.addEstatistica(perdedor, "Empates " + _nome_do_jogo);
        }else{
            //Aqui é para a gente mudar os resultados do jogador no arquivo csv, após uma partida que não acaba em empate
            if (ganhador == apelido) {
                if (_nome_do_jogo == "Reversi") {
                    vitorias_reversi++;
                } else if (_nome_do_jogo == "Lig4") {
                    vitorias_lig4++;
                }
            } else if (perdedor == apelido) {
                if (_nome_do_jogo == "Reversi") {
                    derrotas_reversi++;
                } else if (_nome_do_jogo == "Lig4") {
                    derrotas_lig4++;
                }
            }

            historico.addEstatistica(ganhador, "Vitorias " + _nome_do_jogo);
            historico.addEstatistica(perdedor, "Derrotas " + _nome_do_jogo);
            }
        } catch (const std::exception& e) {
        std::cerr << "Erro ao definir resultado com ganhador e perdedor: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }    
}

void Jogador::empate(std::string _nome_do_jogo, std::string player2){
    //Adiciona empate para ambos os jogadores
    try {
    historico.addEstatistica(apelido, "Empates " + _nome_do_jogo);
    historico.addEstatistica(player2, "Empates " + _nome_do_jogo);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao registrar empate: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }
}

void Jogador::vencedor(std::string perdedor, std::string _nome_do_jogo){
    //Adiciona vitoria para quem chamou a função e derrota pro segundo player;
    try {
    historico.addEstatistica(apelido, "Vitorias " +_nome_do_jogo);
    historico.addEstatistica(perdedor, "Derrotas " + _nome_do_jogo);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao registrar vitória: " << e.what() << std::endl;
        throw; // Re-lançar a exceção após o tratamento
    }
}

void Jogador:: getResultado(){
    //Aqui é para a gente acessar os resultados do jogador já puxado do csv
    std::cout << "Vitorias reversi: " << vitorias_reversi << std::endl; 
    std::cout << "Derrotas reversi: " << derrotas_reversi << std::endl; 
    std::cout << "Empates reversi: " << empates_reversi << std::endl; 
    std::cout << "Vitorias lig4: " << vitorias_lig4 << std::endl; 
    std::cout << "Derrotas lig4: " << derrotas_lig4 << std::endl; 
    std::cout << "Empates lig4: " << empates_lig4 << std::endl;
}

void Jogador:: excluirConta(){
    // Comunicar com o barquivo csv e apagar a linha
    historico.excluirLinha(apelido);
}

//criar um para registrar V e D ou fazer um para J.vitorias += 1 (sobrecarga de operadores) ; 
// ISSO AQUI DEU UM CONFLITO E NAO SABIA SE PODIA APAGAR

bool Jogador::existeConta(){
    
    if(historico.acessarDados(apelido)!= "-1"){
        return true;
    }else{
        return false;
    }
}
