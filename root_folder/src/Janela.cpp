#include <SFML\Graphics.hpp>
#include <iostream>

#define LARGURA 400
#define ALTURA 400


class Janela{
    private:
        int altura, largura;
        bool estaAberto;
        sf::RenderWindow janela;
    public:
        Janela(): altura(ALTURA), largura (LARGURA){};
        Janela(const int x, const int y): altura(x), largura (y){};
        void criarJanela(){
            janela.create(sf::VideoMode(largura, altura), "Jogos de Tabuleiro", sf::Style::Default);
            estaAberto=true;
        }
        void criarJanela(int x, int y){
            janela.create(sf::VideoMode(x, y), "Jogos de Tabuleiro", sf::Style::Default);
            estaAberto=true;
        }

        bool getIsOpen(){
            return janela.isOpen();
        }

        void fecharJanela(){
            janela.close();
        }

        void eventos(){
            sf::Event evento;
            while (janela.pollEvent(evento)){
                if(evento.type == sf::Event::Closed){
                    janela.close();
                }
            }
            
        }

};

// int main(){
//     Janela* janela = new Janela();
//     janela->criarJanela();
//     std::string entrada;
//     while (janela->getIsOpen()){
//         janela->eventos();
//         std::cin >> entrada;
//         if(entrada == "f")
//             break;
//     }
    
//     return 0;
// }