#include <iostream>
#include <string> 
#include <fstream>
#include <memory> 
#include <filesystem>
#include <sstream>

#include "../include/Historico.hpp"
//#include "Jogador.hpp"

Historico::Historico(){
    /*É o contrutor da classe Historico, se o arquivo não existe ele o cria escreve o cabeçario, se ela já existe ele o abre*/
    nomeArquivo = "../dados.csv";
    cabecalho = {
        "Apelido", "Nome", "Vitorias Reversi", "Derrotas Reversi", 
        "Empates Reversi", "Vitorias Lig4", "Derrotas Lig4", "Empates Lig4"
    };
    if(std::filesystem::exists(nomeArquivo)){
        std::cout << "Arquivo ja existe!\n";
    }else{
    std::ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (int i = 0; i < cabecalho.size(); i++) {
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
    /*Essa função copia todas as linhas, menos a que será excluida, em um arquivo auxiliar, apaga o original e renomeia o auxiliar */
    bool existeApelido=false;

    std::ifstream arquivo(nomeArquivo);
    std::ofstream arquivoTemp("../temp.csv");
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
    std::rename("../temp.csv", nomeArquivo.c_str());


    //Lidando com o caso de não achar o apelido
    if(!existeApelido){
         std::cout << "ERRO!! Apelido não encontrado!" << std::endl;
    }
    //Como a função não retorna nada, só consigo escrever no terminal por enquanto o erro
    //Ideal -> trocar o tipo de função para bool para certificar que não há erros

} 


void Historico::Editar(std:: string apelido, std:: string coluna, std:: string novoDado){
    /*Essa função copia todas as linhas em um arquivo auxiliar, mudando apenas o dado na posicao estabelecida pelo apelido e coluna, 
    apaga o arquivo original e renomeia o auxiliar */
    std::ifstream arquivo(nomeArquivo);
    std::ofstream arquivoTemp("../temp.csv");
    std::string linha;

    if (arquivo.is_open()){
        //Copiando o cabeçalho
        getline(arquivo, linha); 
        arquivoTemp << linha << std::endl;  

        while (std::getline(arquivo, linha)){
            //Manipular dados atraves dessas variaveis
            std::stringstream ss(linha);
            std::string dado;

            //leio o apelido e testo se é esse mesmo;
            std::string apelidoLido;
            getline(ss, apelidoLido, ';');
            if(apelidoLido==apelido){
                arquivoTemp << apelidoLido << ";"; //Copio o apelido pro arquivo temp

                //Leio o restante dos dados do jogador, tirando o apelido (i=1)
                for (int i = 1; i < cabecalho.size(); ++i){
                    getline(ss, dado, ';'); //Separo os dados por ;

                    if(coluna==cabecalho[i]){ //Testo se é o dado que eu quero editar
                        dado=novoDado;
                    }

                    arquivoTemp << dado;
                    if (i < cabecalho.size() - 1) {
                        arquivoTemp << ";"; 
                    }
                }
                arquivoTemp << std::endl;
            }else{//Se nao é o apelido que eu quero copio pro arquivo temp
                arquivoTemp << linha << std::endl;
            }
        }
    arquivo.close();
    arquivoTemp.close();

    std::remove(nomeArquivo.c_str());
    std::rename("../temp.csv", nomeArquivo.c_str());

    }
}


void Historico::criarLinha(const std::vector<std::string>& dados) {
    /*Adiciona  mais uma linha ao arquivo csv com base em um vector de strings com os dados referente a cada campo*/
    std::ofstream arquivo(nomeArquivo, std::ios::app);
    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }else{
        // Constrói a linha a partir do vetor de strings
        for (int i = 0; i < dados.size(); ++i) {
            arquivo << dados[i];
            if (i < dados.size() - 1) {
                arquivo << ";"; // Adiciona ponto e vírgula entre os campos
            }
        }
        arquivo << std::endl; // Nova linha após a última entrada

        arquivo.close();
    }
}


std::string Historico::acessarDados(std:: string apelido, std:: string coluna){
    //[acessa um dado específico ditado pelo apelido e coluna, se ele não achar o apelido ela retorna -1]
    std::ifstream arquivo(nomeArquivo);
    std::string linha; 

    if (arquivo.is_open()){
        //Enquanto ainda ha linha para ler
        while (std::getline(arquivo, linha)){
            
            //Variaveis para manipular os dados
            std::stringstream ss(linha);
            std::string dado;

            //leio o apelido e testo se é esse mesmo;
            std::string apelidoLido;
            getline(ss, apelidoLido, ';');
            if(apelidoLido==apelido){
                //Leio o restante dos dados do jogador, tirando o apelido (i=1)
                for (int i = 1; i < cabecalho.size(); i++){
                    getline(ss, dado, ';'); //Separo os dados por ;
                    if(coluna==cabecalho[i]){ //Testo se é o dado que eu quero retornar
                        return dado;
                    }
                }
            }
            
        }
    arquivo.close();
    }

    return "-1"; 
}


std:: string Historico :: acessarDados( std::string apelido){
    /*acessa uma linha específica, se ele não achar o apelido ela retorna -1*/
    std::ifstream arquivo(nomeArquivo);
    std::string linha; 
    if (arquivo.is_open()){ 
        while (std::getline(arquivo, linha)){

            std::stringstream ss(linha);
            std::string dado;

            //leio o apelido e testo se é esse mesmo;
            std::string apelidoLido;
            getline(ss, apelidoLido, ';');
            if(apelidoLido==apelido){
                return linha;
            }
        }
    arquivo.close();
    }
    return "-1"; 
}



void Historico::acessarDados() {
    /*Imprime todos os dados do arquivo csv*/
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    }
}

void Historico::addEstatistica(std:: string apelido, std:: string coluna){
    /*Adiciona 1 a uma estatistica específica*/
    if (coluna=="Apelido" || coluna=="Nome"){
        std::cout << "Erro: Não é possível adicionar estatísticas a esse campo." << std::endl;
        return;
    }else{
        std::string estatistica=acessarDados(apelido, coluna);
        int numeroEstatistica=std::stoi(estatistica);
        numeroEstatistica++;
        estatistica=std::to_string(numeroEstatistica);
        Editar(apelido, coluna, estatistica);
    }
}
        
       