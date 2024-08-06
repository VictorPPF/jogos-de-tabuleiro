#include <iostream>
#include <string> 
#include <fstream>
#include "../include/Historico.hpp"

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
        arquivo << "\n"; 
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
        arquivoTemp << linha << "\n"; 

        while (std::getline(arquivo, linha)){
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if (apelidoLinha != apelido){
                arquivoTemp << linha << "\n"; 
            }
        }
    }
    arquivo.close();
    arquivoTemp.close();

    std::remove(nomeArquivo.c_str());
    std::rename("temp.csv", nomeArquivo.c_str());
} 

template<typename T>
void Historico::Editar(std:: string apelido, std:: string coluna, T novoDado){
    // Ainda precisa lidar com o caso de não encontrar o apelido
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
        arquivoTemp << linha << endl; 

        while (std::getline(arquivo, linha)){
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if (apelidoLinha != apelido){
                arquivoTemp << linha << endl;  
            }else{
                for (size_t i = 0; i < cabecalho.size(); ++i) {
                    if (i == posicaoColuna) {
                        novaLinha += std::to_string(novoDado);
                    } else {
                        novaLinha += linha.substr(linha.find(";"));
                    }
                    arquivoTemp << endl;
                }
        }
    }
    arquivo.close();
    arquivoTemp.close();

    std::remove(nomeArquivo.c_str());
    std::rename("temp.csv", nomeArquivo.c_str());

    }
}

void Historico::criarLinha(const Jogador& jogador){

} 

std::string Historico::acessarDados(std:: string apelido, std:: string coluna){
//[acessa uma célula específica; se ele não achar o apelido ela retorna -1]
}
template<typename T>
T Historico :: acessarDados( std::string apelido){
//[acessa uma linha específica, se ele não achar o apelido ela retorna -1] 
}
void Historico:: acessarDados( ){
 //[Imprime todos os dados] 
}
        
       