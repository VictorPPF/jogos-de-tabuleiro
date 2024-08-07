#include <iostream>
#include <string> 
#include <fstream>
#include <memory> 
#include <filesystem>
#include <sstream>

#include "../include/Historico.hpp"
//#include "Jogador.hpp"

Historico::Historico(){
    nomeArquivo = "teste.csv";
    if(std::filesystem::exists(nomeArquivo)){
        std::cout << "Arquivo ja existe!\n";
    }else{
    std::ofstream arquivo(nomeArquivo);
    cabecalho = {
        "Apelido", "Nome", "Vitorias Reversi", "Derrotas Reversi", 
        "Empates Reversi", "Vitorias Lig4", "Derrotas Lig4", "Empates Lig4"
    };
    if (arquivo.is_open()) {
        for (int i = 0; i < cabecalho.size(); ++i) {
            arquivo << cabecalho[i];
            if (i < cabecalho.size() - 1) {
                arquivo << ";"; 
            }
        }
        arquivo << std::endl; 
    }
    arquivo.close();
    }
}

void Historico::excluirLinha (std:: string apelido){ 
    // Ainda precisa lidar com o caso de não encontrar o apelido
    bool existeApelido=false;

    std::ifstream arquivo(nomeArquivo);
    std::ofstream arquivoTemp("temp.csv");
    std::string linha; 
    if (arquivo.is_open()){
        //Copiando o cabeçalho
        getline(arquivo, linha); 
        arquivoTemp << linha << std::endl; 

        

        //Lendo linha por linha
        while (std::getline(arquivo, linha)){
            //Basicamente ele vai pular a linha que tem o apelido que queremos excluir
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if (apelidoLinha != apelido){
                arquivoTemp << linha << std::endl; 
            }else{
                existeApelido=true;
            }
        }
    
    }
    
    arquivo.close();
    arquivoTemp.close();

    std::remove(nomeArquivo.c_str());
    std::rename("temp.csv", nomeArquivo.c_str());


    //Lidando com o caso de não achar o apelido
    if(!existeApelido){
         std::cout << "ERRO!! Apelido não encontrado!" << std::endl;
    }
    //Como a função não retorna nada, só consigo escrever no terminal por enquanto o erro
    //Ideal -> trocar o tipo de função para bool para certificar que não há erros

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


void Historico::criarLinha(){
    std::ofstream arquivo(nomeArquivo, std::ios::app);
    if(arquivo.is_open()){
        arquivo << "Tuco" << ";";
        arquivo << "Roberto Luiz" << ";";
        arquivo << "0" << ";";
        arquivo << "0" << ";";
        arquivo << "0" << ";";
        arquivo << "0" << ";";
        arquivo << "0"  << ";";
        arquivo << "0"  << std::endl;
    }
    arquivo.close();
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

    //Escolhendo qual tipo de dado retornar
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

bool Historico::addEstatistica(std:: string apelido, std:: string coluna){
    int posicaoColuna = 0; 
    for (size_t i = 0; i < cabecalho.size(); ++i) {
        if (cabecalho[i] == coluna) {
            posicaoColuna = i;
            break;
        }
    }

    bool existeApelido=false;

    std::ifstream arquivo(nomeArquivo);
    std::ofstream arquivoTemp("temp.csv");
    std::string linha; 
    
    if (arquivo.is_open()){
        getline(arquivo, linha); 
        arquivoTemp << linha << std::endl; 

        while (std::getline(arquivo, linha)){
            std:: string apelidoLinha = linha.substr(0, linha.find(";"));
            if(apelido == apelidoLinha){
                existeApelido=true;

                std::stringstream manipulaLinha(linha.substr(posicaoColuna, linha.find(";")));
                //int estatistica = std::stoi(linha.substr(posicaoColuna, linha.find(";")));
                int estatistica;
                manipulaLinha >> estatistica;
                if(manipulaLinha.fail()){ //Testa se a conversao falhou
                    std::cout<< "ERRO!! Não foi possível manipular os dados corretamente!" <<std::endl;
                    return -1;
                }
                estatistica++;
                Editar(apelido, coluna, std::to_string(estatistica));
                
                //Pra fazer isso preciso entender melhor como o arquivo funciona
            }else{
                arquivoTemp << linha <<std::endl;
            }
        }
    
    }

    arquivo.close();
    arquivoTemp.close();

    std::remove(nomeArquivo.c_str());
    std::rename("temp.csv", nomeArquivo.c_str());

    if(!existeApelido){
        std::cout<< "ERRO!! Não existe esse apelido!" <<std::endl;
        return -1;
    }
    return 0;
}
        
       