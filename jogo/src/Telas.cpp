#include "../include/Telas.hpp"
#include "../include/Wallpaper.hpp"
#include "../include/Interacao.hpp"

TelaMenu::TelaMenu(sf::RenderWindow& window, sf::Font& fonte,sf::Event& evento) : window(window), fonte(fonte), evento(evento),
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

void TelaMenu::desenharMenu() {
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

TelaCadastro::TelaCadastro(sf::RenderWindow& window, sf::Font& fonte)
    : window(window), fonte(fonte),
    botaoNome(502.0, 49.f, 327.f, 283.f, sf::Color(203, 202, 106,100), "", 15.f, false),
    botaoApelido(502.0, 49.f, 327.f, 359.f, sf::Color(203, 202, 106,100), "", 15.f, false),
    botaoConfirma(502.0/3, 49.f, 327.f + 502*(2.f/3.f), 359.f + (359 - 283), sf::Color(220, 100, 180,100), "confirma", 15.f, false),
    botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)),
    campoNome(502.0, 49.f, 327.f, 283.f),
    campoApelido(502.0, 49.f, 327.f, 359.f) {

        botaoNome.criarBotoes();
        botaoApelido.criarBotoes();
        botaoConfirma.criarBotoes();
        botaoConfirma.setCorHover(sf::Color(255, 0, 20, 100));
        botaoConfirma.criarBotoes();
        botaoVoltar.criarBotoes();
    }

void TelaCadastro::desenharJogo() {
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

TelaLista::TelaLista(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
    botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)) {
        botaoVoltar.criarBotoes();
    }

void TelaLista::desenharLista() {
    Wallpaper wallpaper("menuListaJogadores.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    botaoVoltar.desenhar(window);
}

TelaExcluirConta::TelaExcluirConta(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
    botaoApelido(502.0, 49.f, 327.f, 264.f, sf::Color(203, 202, 106,100), "", 15.f, false),
    botaoExcluir(350.f, 65.f, 171.f, 345.f, sf::Color(220, 100, 180,100), "Excluir Conta", 25.f, false),
    botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)),
    campoApelido(502.0, 49.f, 327.f, 264.f) {
        botaoApelido.criarBotoes();
        botaoExcluir.criarBotoes();
        botaoExcluir.setCorHover(sf::Color(255, 0, 20, 100));
        botaoVoltar.criarBotoes();
    }

void TelaExcluirConta::desenharExcluirConta() {
    Wallpaper wallpaper("menuExcluirConta.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    botaoApelido.desenhar(window);
    botaoExcluir.desenhar(window);
    botaoVoltar.desenhar(window);
    campoApelido.desenhar(window);
}

TelaEstatisticas::TelaEstatisticas(sf::RenderWindow& window, sf::Font& fonte)
    : window(window), fonte(fonte),
    botaoApelido(502.0, 49.f, 327.f, 217.f, sf::Color(203, 202, 106,100), "", 15.f, false),
    botaoVoltar(284.f, 65.f, 358.f, 557.f, sf::Color(150, 129, 250), "Voltar", 25.f, false, sf::Color(43, 0, 108)),
    botaoPesquisa(130.0, 49.f, 327.f + 25 + 502.0, 217.f, sf::Color(150, 129, 200,200), "Pesquisa", 15.f, false),
    campoPesquisa(502.0, 49.f, 327.f, 217.f) {

        botaoApelido.criarBotoes();
        botaoVoltar.criarBotoes();
        botaoPesquisa.criarBotoes();
        botaoPesquisa.setCorHover(sf::Color(150, 129 - 50, 200,50)); //150, 129, 250 roxo padrao
    }

void TelaEstatisticas::desenharEstatisticas() {
    Wallpaper wallpaper("menuEstatisticas.png");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    botaoApelido.desenhar(window);
    botaoVoltar.desenhar(window);
    botaoPesquisa.desenhar(window);
    campoPesquisa.desenhar(window);
}


FimDeJogoLig4::FimDeJogoLig4(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
    botaoMenu(84.f*3, 65.f*1.5, 84/4, 84*1, sf::Color(150, 129, 250), "Menu", 25.f, false, sf::Color(43, 0, 108)),
    botaoRestart(84.f*3, 65.f*1.5, 84/4, 84*3, sf::Color(150, 129, 250), "Restart", 25.f, false, sf::Color(43, 0, 108)) {
        botaoMenu.criarBotoes();
        botaoRestart.criarBotoes();
    }
void FimDeJogoLig4::desenharTelaFinal() {
    Wallpaper wallpaper("wallpaperflare.jpg");
    wallpaper.redimensionar(window.getSize());

    wallpaper.desenhar(window);
    botaoMenu.desenhar(window);
    botaoRestart.desenhar(window);
}