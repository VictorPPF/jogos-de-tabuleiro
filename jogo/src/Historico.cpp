#include <iostream>
#include <string> 
#include <fstream>
#include <memory> 
#include "Historico.hpp"
#include "Jogador.hpp"

Historico::Historico(){
    std::ofstream arquivo(nomeArquivo);
    cabecalho = {
        "Apelido", "Nome", "Vitorias Reversi", "Derrotas Reversi", 
        "Empates Reversi", "Vitorias Lig4", "Derrotas Lig4", "Empates Lig4"
    };

    if (arquivo.is_open()) {
        for (size_t i = 0; i < cabecalho.size(); ++i) {
            arquivo << cabecalho[i];
            if (i < cabecalho.size() - 1) {
                arquivo << ";"; 
        }
        arquivo << std::endl; 
        }
    }
    arquivo.close();
}

void Historico::excluirLinha (std:: string apelido){ 
    // Ainda precisa lidar com o caso de não encontrar o apelido
    std::ifstream arquivo(nomeArquivo);
    std::ofstream arquivoTemp("temp.csv");
    std::string linha; 
    if (arquivo.is_open()){
        getline(arquivo, linha); 
        arquivoTemp << linha << std::endl; 

        while (std::getline(arquivo, linha)){
            //Basicamente ele vai pular a linha que tem o apelido que queremos excluir
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if (apelidoLinha != apelido){
                arquivoTemp << linha << std::endl; 
            }
        }
    }
    arquivo.close();
    arquivoTemp.close();

    std::remove(nomeArquivo.c_str());
    std::rename("temp.csv", nomeArquivo.c_str());
} 


void Historico::Editar(std:: string apelido, std:: string coluna, std:: string novoDado){
    // Ainda precisa lidar com o caso de não encontrar o apelido
    //Minha dúvida está no Template 
    int posicaoColuna = 0; 
    for (size_t i = 0; i < cabecalho.size(); ++i) {
        if (cabecalho[i] == coluna) {
            posicaoColuna = i;
            break;
        }
    }

    std::ifstream arquivo(nomeArquivo);
    std::ofstream arquivoTemp("temp.csv");
    std::string linha; 
    if (arquivo.is_open()){
        getline(arquivo, linha); 
        arquivoTemp << linha << std::endl; 

        while (std::getline(arquivo, linha)){
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if (apelidoLinha != apelido){
                arquivoTemp << linha <<std::endl;  
            }else{
                std:: string novaLinha = "";
                for (size_t i = 0; i < cabecalho.size(); ++i) {
                    if (i == posicaoColuna) {
                        novaLinha += novoDado;
                    } else {
                        novaLinha = linha.substr(linha.find(";"));
                    }
                    if (i < cabecalho.size() - 1) {
                        novaLinha += ";";
                    }
                }
                arquivoTemp << novaLinha <<  std::endl;
            }
        }
    arquivo.close();
    arquivoTemp.close();

    std::remove(nomeArquivo.c_str());
    std::rename("temp.csv", nomeArquivo.c_str());

    }
}

/*void Historico::criarLinha(const Jogador& jogador){
    std::ofstream arquivo(nomeArquivo, std::ios::app);
    if (arquivo.is_open()){
        arquivo << jogador.getApelido() << ";";
        arquivo << jogador.getNome() << ";";
        arquivo << jogador.getVitoriasReversi() << ";";
        arquivo << jogador.getDerrotasReversi() << ";";
        arquivo << jogador.getEmpatesReversi() << ";";
        arquivo << jogador.getVitoriasLig4() << ";";
        arquivo << jogador.getDerrotasLig4() << ";";
        arquivo << jogador.getEmpatesLig4() << std::endl;
    }
    arquivo.close();
}*/

std::string Historico::acessarDados(std:: string apelido, std:: string coluna){
//[acessa uma célula específica; se ele não achar o apelido ela retorna a string -1]
    int posicaoColuna = 0; 
    for (size_t i = 0; i < cabecalho.size(); ++i) {
        if (cabecalho[i] == coluna) {
            posicaoColuna = i;
            break;
        }
    }
    std::ifstream arquivo(nomeArquivo);
    std::string linha; 
    if (arquivo.is_open()){
        getline(arquivo, linha); 
        while (std::getline(arquivo, linha)){
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if (apelidoLinha == apelido){
                return linha.substr(posicaoColuna, linha.find(";")); 
            }
        }
    arquivo.close();
    }
    return "-1"; 
}


std:: string Historico :: acessarDados( std::string apelido){
//[acessa uma linha específica, se ele não achar o apelido ela retorna -1] 
    std::ifstream arquivo(nomeArquivo);
    std::string linha; 
    if (arquivo.is_open()){
        getline(arquivo, linha); 
        while (std::getline(arquivo, linha)){
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if (apelidoLinha == apelido){
                return linha; 
            }
        }
    arquivo.close();
    }
    return "-1"; 
}



void Historico::acessarDados() {
    //[Imprime todos os dados]
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    }
}
        
       