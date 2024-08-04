#include <iostream>
#include <string> 
#include <fstream>
#include "../include/Historico.hpp"

Historico::Historico(){
    std::ofstream arquivo("dados.csv");
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

void Historico::excluirLinha (){

} 
void Historico::Editar(){

}
void Historico::criarLinha(){

} 
void Historico::excluirLinha(){

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
        
       