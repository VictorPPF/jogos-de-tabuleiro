#include <SFML/Graphics.hpp>
#include <windows.h>

#include "../include/Wallpaper.hpp"
#include "../include/ExecutaPartida.hpp"
#include "../include/Tabuleiro.hpp"
#include <iostream>

using namespace std;

#include <SFML/Graphics.hpp>
#include <iostream>
// foi feito na pressa. acho que botao deveria ter um metodo que encapsula essa classe CampoTexto
class CampoTexto {
public:
    
    CampoTexto(float largura, float altura, float posicaoX, float posicaoY) :
        retangulo(sf::Vector2f(largura, altura)),
        texto("", fonte, 25),
        ativo(false) {
        retangulo.setPosition(posicaoX, posicaoY);
        retangulo.setFillColor(sf::Color(223, 232, 106, 100)); // cor semitransparente
        retangulo.setOutlineThickness(2);
        retangulo.setOutlineColor(sf::Color::Black);

        texto.setPosition(posicaoX + 5, posicaoY + 10); // pequeno deslocamento pra dentro do retângulo
        texto.setFillColor(sf::Color::Black);
        
        
        if (!fonte.loadFromFile("font_arcade.ttf")) {
            std::cerr << "deu ruim pra carregar a fonte" << std::endl;
        }
    }
    int deu_enter = 0;
    
    void limparTexto() {
            texto.setString("");
    }

    void desenhar(sf::RenderWindow& window) {
        window.draw(retangulo);
        window.draw(texto);
    }

    void processarEventos(sf::Event& event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (retangulo.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                ativar();
            } else {
                desativar();
            }
        }

        if (event.type == sf::Event::TextEntered) {
            if (ativo) {
                if (event.text.unicode == '\b') { // da backspace
                    removerUltimoCaractere();
                } else if (event.text.unicode < 128) {
                    adicionarCaractere(static_cast<char>(event.text.unicode));
                }
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) { // da enter
                if (ativo) {
                    cout << "Texto inserido: " << obterTexto() << endl;
                    deu_enter = 1;
                    desativar();
                }
            }
        }
    }

    string obterTexto() const {
        return texto.getString();
    }

private:
    void ativar() {
        ativo = true;
        retangulo.setFillColor(sf::Color(223, 232, 106, 200));
        retangulo.setOutlineColor(sf::Color(150, 129, 250));
        retangulo.setOutlineThickness(5);
    }

    void desativar() {
        ativo = false;
        retangulo.setFillColor(sf::Color(223, 232, 106, 100));
        retangulo.setOutlineColor(sf::Color::Black);
        retangulo.setOutlineThickness(2);
    }

    void adicionarCaractere(char c) {
        texto.setString(texto.getString() + c);
    }

    void removerUltimoCaractere() {
        sf::String str = texto.getString();
        if (str.getSize() > 0) {
            str.erase(str.getSize() - 1);
            texto.setString(str);
        }
    }

    sf::RectangleShape retangulo;
    sf::Text texto;
    sf::Font fonte;
    bool ativo;
};

class TelaMenu {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
    sf::Event& evento; 
    
public:
    Botao botaoJogador1;
    Botao botaoJogador2;
    Botao botaoListaJogadores;
    Botao botaoCadastro;
    Botao botaoExcluirConta;
    Botao botaoEstatistica;
    Botao play1;
    Botao play2;
    CampoTexto campoJogador1;
    CampoTexto campoJogador2;
    TelaMenu(sf::RenderWindow& window, sf::Font& fonte,sf::Event& evento) : window(window), fonte(fonte), evento(evento),
        /*botao recebe: largura, altura, posicao x, posicao y, cor em rgb (a última coluna é transparencia), 
        texto, tamanho da fonte, se for circulo é true, cor da fonte (o padrão é white)*/
        botaoJogador1(306.0, 49.f, 174.0, 206.f, sf::Color(223, 232, 106, 100), "", 15.f, false),
        botaoJogador2(306.0, 49.f, 177.0 + (306.0*1.5), 206.f, sf::Color(223, 232, 106, 100), "", 15.f, false),
        botaoCadastro(220.f, 65.f, 140.f, 368.f, sf::Color(150, 129, 250), "Cadastro", 25.f, false, sf::Color(43, 0, 108)),
        botaoListaJogadores(500.f, 65.f, 390.f, 368.f, sf::Color(150, 129, 250), "Lista de Jogadores", 25.f, false, sf::Color(43, 0, 108)),
        botaoExcluirConta(350.f, 65.f, 140.f, 458.f, sf::Color(150, 129, 250), "Excluir Conta", 25.f, false, sf::Color(43, 0, 108)),
        botaoEstatistica(350.f, 65.f, 540.f, 458.f, sf::Color(150, 129, 250), "Estatisticas", 25.f, false, sf::Color(43, 0, 108)),
        play1(200.f,100.f,140 + (350-200)/2,550.f, sf::Color(50, 50, 50), "REVERSI", 25.f, false, sf::Color(43, 0, 108)),
        play2(200.f,100.f,540 - 140 + (540 - 100)/2,550.f, sf::Color(50, 50, 50), "LIG4", 25.f, false, sf::Color(43, 0, 108)),
        campoJogador1(306.0, 49.f, 173.0, 206.f),
        campoJogador2(306.0, 49.f, 177.0 + (306.0 * 1.5), 206.f)
    {
        botaoJogador1.criarBotoes();
        botaoJogador2.criarBotoes();
        botaoCadastro.criarBotoes();
        botaoListaJogadores.criarBotoes();
        botaoExcluirConta.criarBotoes();
        botaoEstatistica.criarBotoes();
        play1.criarBotoes();
        play2.criarBotoes();
        
    }
    void desenharMenu() {
        Wallpaper wallpaper("menuInicial.png");
        wallpaper.redimensionar(window.getSize());


        wallpaper.desenhar(window);
        botaoJogador1.desenhar(window);
        botaoJogador2.desenhar(window);
        botaoCadastro.desenhar(window);
        botaoListaJogadores.desenhar(window);
        botaoExcluirConta.desenhar(window);
        botaoEstatistica.desenhar(window);
        play1.desenhar(window);
        play2.desenhar(window);
        campoJogador1.desenhar(window);
        campoJogador2.desenhar(window);
    }

    
};

class TelaCadastro {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;

public:
    Botao botaoNome;
    Botao botaoApelido;
    Botao botaoConfirma;
    Botao botaoVoltar;
    CampoTexto campoNome;
    CampoTexto campoApelido;

    TelaCadastro(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
        //223, 232, 106, 100
        botaoNome(502.0, 49.f, 327.f, 283.f, sf::Color(203, 202, 106,100), "", 15.f, false),
        botaoApelido(502.0, 49.f, 327.f, 359.f, sf::Color(203, 202, 106,100), "", 15.f, false),
        botaoConfirma(502.0/3, 49.f, 327.f + 502*(2.f/3.f), 359.f + (359 - 283), sf::Color(220, 100, 180,100), "confirma", 15.f, false),
        botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)),
        campoNome(502.0, 49.f, 327.f, 283.f),
        campoApelido(502.0, 49.f, 327.f, 359.f)
    {
        
        botaoNome.criarBotoes();
        botaoApelido.criarBotoes();
        botaoConfirma.criarBotoes();
        botaoConfirma.setCorHover(sf::Color(255, 0, 20, 100));
        botaoConfirma.criarBotoes();
        botaoVoltar.criarBotoes();
    }

    void desenharJogo() {
        Wallpaper wallpaper("menuCadastro.png");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        botaoNome.desenhar(window);
        botaoApelido.desenhar(window);
        botaoConfirma.desenhar(window);
        botaoVoltar.desenhar(window);
        campoNome.desenhar(window);
        campoApelido.desenhar(window);
    }
};

class TelaReversi {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;

public:
    Botao botaoApelido;
    Botao botaoVoltar;

    TelaReversi(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
        
        botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(223, 232, 106, 100), "", 15.f, false),
        botaoVoltar(284.f, 65.f, 0, 0, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108))
    {
        
        botaoApelido.criarBotoes();
        botaoVoltar.criarBotoes();
    }

    void desenharJogo() {
        Wallpaper wallpaper("wallpaperflare.jpg");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        botaoApelido.desenhar(window);
        botaoVoltar.desenhar(window);
    }
};

class TelaLista {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
public:
    Botao botaoVoltar;
    TelaLista(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte), 
    botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)) {
        botaoVoltar.criarBotoes();
    }

    
    void desenharLista() {
        Wallpaper wallpaper("menuListaJogadores.png");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        botaoVoltar.desenhar(window);
    }
};

class TelaLig4 {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;

public:
    Botao botaoApelido;
    Botao botaoVoltar;

    TelaLig4(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
        
        botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(223, 232, 106, 100), "", 15.f, false),
        botaoVoltar(284.f, 65.f, 0, 0, sf::Color(150, 129, 250), "DESISTI!", 25.f, false, sf::Color(43, 0, 108))
    {
        botaoApelido.criarBotoes();
        botaoVoltar.criarBotoes();
    }

    void desenharJogo() {
        Wallpaper wallpaper("wallpaper_lig4.png");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        botaoApelido.desenhar(window);
        botaoVoltar.desenhar(window);
    }
};

class TelaExcluirConta {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
public:
    Botao botaoApelido;
    Botao botaoExcluir;
    Botao botaoVoltar;
    CampoTexto campoApelido;

    TelaExcluirConta(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
    botaoApelido(502.0, 49.f, 327.f, 264.f, sf::Color(203, 202, 106,100), "", 15.f, false),
    botaoExcluir(350.f, 65.f, 171.f, 345.f, sf::Color(220, 100, 180,100), "Excluir Conta", 25.f, false),
    botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)),
    campoApelido(502.0, 49.f, 327.f, 264.f) {
        botaoApelido.criarBotoes();
        botaoExcluir.criarBotoes();
        botaoExcluir.setCorHover(sf::Color(255, 0, 20, 100));
        botaoVoltar.criarBotoes();
    }
    void desenharExcluirConta() {
        Wallpaper wallpaper("menuExcluirConta.png");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        botaoApelido.desenhar(window);
        botaoExcluir.desenhar(window);
        botaoVoltar.desenhar(window);
        campoApelido.desenhar(window);
    }
};

class TelaEstatisticas {
private:
    sf::RenderWindow& window; 
    sf::Font& fonte;
public:
    Botao botaoApelido;
    Botao botaoVoltar;
    Botao botaoPesquisa;
    CampoTexto campoPesquisa;
    TelaEstatisticas(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
    botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(203, 202, 106,100), "", 15.f, false),
    botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)),
    botaoPesquisa(130.0, 49.f, 327.f + 25 + 502.0, 217.f, sf::Color(150, 129, 200,200), "Pesquisa", 15.f, false),
    campoPesquisa(502.0, 49.f, 327.f, 217.f) {
        botaoApelido.criarBotoes();
        botaoVoltar.criarBotoes();
        botaoPesquisa.criarBotoes();
        botaoPesquisa.setCorHover(sf::Color(150, 129 - 50, 200,50)); //150, 129, 250 roxo padrao
    }
    void desenharEstatisticas() {
        Wallpaper wallpaper("menuEstatisticas.png");
        wallpaper.redimensionar(window.getSize());

        wallpaper.desenhar(window);
        botaoApelido.desenhar(window);
        botaoVoltar.desenhar(window);
        botaoPesquisa.desenhar(window);
        campoPesquisa.desenhar(window);
    }
};

 //logica idiota de teste pra validar entrada de campos de texto
bool dois_enter(CampoTexto campoJogador1, CampoTexto campoJogador2) {
        if (campoJogador1.obterTexto() != "" && campoJogador2.obterTexto() != "" && 
        campoJogador1.deu_enter == 1 && campoJogador2.deu_enter == 1) {
            // campoJogador1.deu_enter = 0;
            // campoJogador2.deu_enter = 0;
            return true;
        }
        return false;
    };


int main() {
    //carrega a fonte só uma vez 
    sf::Font fonte;
    if (!fonte.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return 1;
    }
    //--------------- MÓDULO PARA INICIAR A TELA DO JOGO NAS DIMENSÕES DA TELA DA PESSOA-----------------//
    // Obtém as dimensões da tela
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);
    int screenWidth = screenRect.right - screenRect.left;
    sf::Event event;
    // Define as dimensões da janela
    int windowLargura = 1000;
    int windowAltura = 690;

    // Calcula a posição horizontal centralizada e define a posição vertical no topo da tela
    int windowPosX = (screenWidth - windowLargura) / 2;
    int windowPosY = 0;

    // Criação da janela com a posição ajustada
    sf::RenderWindow window(sf::VideoMode(windowLargura, windowAltura), "Deluxe Collection");
    window.setPosition(sf::Vector2i(windowPosX, windowPosY));

    string estadoAtual = "MenuPrincipal"; // I CANT STRESS ENOUGH HOW IMPORTANT THIS VARIABLE IS

    //---------------------------------------------------------------------------------------------//

    // Configurações iniciais de cor e forma
    sf::Color cor(255, 130, 190); //variavel com parametros de valor de cor (vai de 0 a 255)
    sf::CircleShape circulo(50.f);
    circulo.setFillColor(sf::Color::Blue);

    // Define a posição inicial do círculo
    circulo.setPosition(0.0, 0.0);
    //retangulo igual o circulo
    sf::RectangleShape retangulo(sf::Vector2f(100.f, 100.f));
    retangulo.setFillColor(sf::Color::Red);
    retangulo.setPosition(0.0, 0.0);

    // Cria dois pontos com coordenadas diferentes
    PontoF pos1(2.0,3.0);
    PontoF pos2(200.0,200.0);
    Movimentacao teste;
    
    
    // Cria um relógio para medir o tempo
    sf::Clock relogio;
    
    PontoF pos3 = pos1 + pos2;

    //cout << pos3 << endl;

    // Criação dos campos de texto
    
    Tabuleiro tabuleiro;
    

    TelaMenu telaMenu (window,fonte,event);
    TelaReversi telaRever (window,fonte);
    TelaLig4 telaLig (window,fonte);
    TelaCadastro telaCadastro (window,fonte);
    TelaLista telaLista (window,fonte);
    TelaExcluirConta telaExcluir (window,fonte);
    TelaEstatisticas telaEstat (window,fonte);
    bool nao_ignora_mouse = true;

    while (window.isOpen()) {

        bool jogadores_validos = true; //dois_enter(telaMenu.campoJogador1,telaMenu.campoJogador2);
        bool cadastro_valido = dois_enter(telaCadastro.campoNome,telaCadastro.campoApelido);
        bool jogador_existe = telaExcluir.campoApelido.obterTexto() != "";
        bool jogador_encontrado = telaEstat.campoPesquisa.obterTexto() != "";
        // Checa todos os eventos que ocorreram desde a última iteração do loop
        
        while (window.pollEvent(event)) {    //pollEvent é uma função que retorna true se houver eventos na fila
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (estadoAtual == "MenuPrincipal") {
                
                telaMenu.campoJogador1.processarEventos(event, window);
                telaMenu.campoJogador2.processarEventos(event, window);

            }
            if (estadoAtual == "Cadastro") {
                telaCadastro.campoNome.processarEventos(event, window);
                telaCadastro.campoApelido.processarEventos(event, window);
            }
            if (estadoAtual == "ExcluirConta") {
                telaExcluir.campoApelido.processarEventos(event, window);

            }
            if (estadoAtual == "Estatisticas") {
                telaEstat.campoPesquisa.processarEventos(event, window);
                if (!telaEstat.botaoPesquisa.passouMouse(window)) {
                        telaEstat.botaoPesquisa.setCor(sf::Color(150, 129, 200,200)); 
                    }
            }
            //agora se sabe q deu enter nos dois campos e tem condição pra comparar se sao validos
            //pra entrar na tela de jogo
            //logica idiota de teste pra validar entrada de campos de texto (substituir pela logica correta consultando no banco de dados)
            
            if (jogadores_validos) { 
                telaMenu.play1.setCor(sf::Color(150, 129, 250));
                telaMenu.play2.setCor(sf::Color(150, 129, 250));
            }
            else {
                telaMenu.play1.setCor(sf::Color(50, 50, 50));
                telaMenu.play2.setCor(sf::Color(50, 50, 50));
            }
            //logica idiota de teste pra validar entrada de campos de texto (substituir pela logica correta consultando no banco de dados)
            
            if (cadastro_valido) { 
                telaCadastro.botaoConfirma.setCor(sf::Color(43, 246, 21,100));
                telaCadastro.botaoConfirma.setCorHover(sf::Color(43, 246, 21,200));
            }
            //logica idiota de teste pra validar entrada de campos de texto (substituir pela logica correta consultando no banco de dados)
            
            if (jogador_existe) { 
                telaExcluir.botaoExcluir.setCor(sf::Color(43, 246, 21,100));
                telaExcluir.botaoExcluir.setCorHover(sf::Color(43, 246, 21,200));
                
            }
            if (jogador_encontrado) { 
                telaEstat.botaoPesquisa.setCor(sf::Color(43, 246, 21,100));
                telaEstat.botaoPesquisa.setCorHover(sf::Color(43, 246, 21,200));
            }
            
            

            if ( event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                
                if (estadoAtual == "MenuPrincipal") {
                    //sf::sleep(sf::milliseconds(1000)); // Atraso de 100 milissegundos
                    // os botoes excluir, estatistica e lista estão sobrepostos, então tem que ignorar o primeiro evento de clique
                    if (telaMenu.botaoCadastro.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "Cadastro";
                    }
                    //nao_ignora_mouse = true;
                    if (telaMenu.botaoListaJogadores.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "ListaDeJogadores";
                    }
                    //nao_ignora_mouse = true;
                    if (telaMenu.botaoExcluirConta.passouMouse(window)) {
                        estadoAtual = "ExcluirConta";
                    }
                    if (telaMenu.botaoEstatistica.passouMouse(window) && nao_ignora_mouse) {
                        estadoAtual = "Estatisticas";
                    }
                    // os botoes confirma e estatistica estão sobrepostos, então tem que ignorar o primeiro evento de clique
                    nao_ignora_mouse = true;

                    if (telaMenu.play1.passouMouse(window) && jogadores_validos) { //AQUI ENTRA NO JOGO REVERSI
                        telaMenu.campoJogador1.limparTexto();
                        telaMenu.campoJogador2.limparTexto();
                        estadoAtual = "Reversi";
                    }
                    if (telaMenu.play2.passouMouse(window) && jogadores_validos) { //AQUI ENTRA NO JOGO LIG4
                        telaMenu.campoJogador1.limparTexto();
                        telaMenu.campoJogador2.limparTexto();
                        estadoAtual = "Lig4";
                    }
                    
                } else {
                    //regiao retangular padrao do "botao" de voltar só pra ALGUMAS telas
                    if (mousePos.x > 358 && mousePos.x < 642 && mousePos.y > 557 && mousePos.y < 624 
                    && (estadoAtual == "Cadastro" || estadoAtual == "ListaDeJogadores" || 
                        estadoAtual == "ExcluirConta" || estadoAtual == "Estatisticas")) { 
                    
                        estadoAtual = "MenuPrincipal";
                        telaMenu.campoJogador1.deu_enter = 0; //tem que desvalidar quem muda o estadoAtual para Jogo
                        telaMenu.campoJogador2.deu_enter = 0;

                        //pra nao ficar escrito na tela coisa antiga
                        telaCadastro.campoNome.limparTexto();
                        telaCadastro.campoApelido.limparTexto();
                        

                    }
                }
                if (estadoAtual == "Reversi") {
                    //botao de voltar do jogo vai ficar em posição diferente
                    if (telaRever.botaoVoltar.passouMouse(window)) { 
                        estadoAtual = "MenuPrincipal";
                        telaMenu.campoJogador1.deu_enter = 0;
                        telaMenu.campoJogador2.deu_enter = 0;
                    }
                }
                if (estadoAtual == "Lig4") {
                    //botao de voltar do jogo vai ficar em posição diferente
                    if (telaLig.botaoVoltar.passouMouse(window)) { 
                        estadoAtual = "MenuPrincipal";
                        telaMenu.campoJogador1.deu_enter = 0;
                        telaMenu.campoJogador2.deu_enter = 0;
                    }
                }
                
                if (estadoAtual == "Cadastro") {
                    if (telaCadastro.botaoConfirma.passouMouse(window) && cadastro_valido) {
                        telaCadastro.campoNome.limparTexto();
                        telaCadastro.campoApelido.limparTexto();
                        nao_ignora_mouse = false;
                        telaCadastro.botaoConfirma.setCor(sf::Color(220, 100, 180,100)); 
                        telaCadastro.botaoConfirma.setCorHover(sf::Color(255, 0, 20, 100));
                        estadoAtual = "MenuPrincipal";
                        
                    }
                }
                if (estadoAtual == "ListaDeJogadores") {
                    
                        
                }
                if (estadoAtual == "ExcluirConta") {
                    if (telaExcluir.botaoExcluir.passouMouse(window) && jogador_existe) {
                        telaExcluir.campoApelido.limparTexto();
                        nao_ignora_mouse = false;
                        telaExcluir.botaoExcluir.setCor(sf::Color(220, 100, 180,100)); 
                        telaExcluir.botaoExcluir.setCorHover(sf::Color(255, 0, 20, 100));
                        estadoAtual = "MenuPrincipal";
                        
                    }
                        
                }
                if (estadoAtual == "Estatisticas") { //AQUI CHAMA AS ESTATISTICAS CONSULTANDO O HISTÓRICO
                    if (telaEstat.botaoPesquisa.passouMouse(window) && event.mouseButton.button == sf::Mouse::Left) {

                        telaEstat.botaoPesquisa.setCor(sf::Color(100, 129 - 50, 200)); //150, 129, 250 roxo padrao

                    }
                    
                    
                }
            }
            if (estadoAtual == "Reversi") {
                sf::Vector2i mousePos_jogo = sf::Mouse::getPosition(window);
                // Verifica as teclas pressionadas e move o círculo
                
                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    teste.mover(retangulo, sf::Keyboard::W);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        
                        teste.mover(retangulo, sf::Keyboard::A);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        teste.mover(retangulo, sf::Keyboard::S);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        teste.mover(retangulo, sf::Keyboard::D);
                    }
                }
                
            }
            if (estadoAtual == "Lig4") {
                sf::Vector2i mousePos_jogo = sf::Mouse::getPosition(window);
                // Verifica as teclas pressionadas e move o círculo
                
                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    teste.mover(circulo, sf::Keyboard::W);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        
                        teste.mover(circulo, sf::Keyboard::A);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        teste.mover(circulo, sf::Keyboard::S);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        teste.mover(circulo, sf::Keyboard::D);
                    }
                }

                //matriz
                
            }
            
        }

        window.clear();

        if (estadoAtual == "MenuPrincipal") {
                telaMenu.desenharMenu();
            } else if (estadoAtual == "Cadastro") { //se o condicional da regiao do botao mudar o estadoAtual
                telaCadastro.desenharJogo();  //pra Cadastro entao chama a função desenharCadastro e assim por diante
            } else if (estadoAtual == "ListaDeJogadores") {
                telaLista.desenharLista();
            } else if (estadoAtual == "ExcluirConta") {
                telaExcluir.desenharExcluirConta();
            } else if (estadoAtual == "Estatisticas") {
                telaEstat.desenharEstatisticas();
            } else if (estadoAtual == "Reversi") {
                telaRever.desenharJogo();
                window.draw(retangulo);
            }else if (estadoAtual == "Lig4") {
                telaLig.desenharJogo();
                window.draw(circulo);
                tabuleiro.desenhar(window);
            }
            

        window.display();
    }

    return 0;
}

