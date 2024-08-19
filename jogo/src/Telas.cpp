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
    try {
        Wallpaper wallpaper("menuInicial.png");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao carregar o wallpaper do menu: " << e.what() << std::endl;
    }

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
    try {
        Wallpaper wallpaper("menuCadastro.png");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao carregar o wallpaper do menu: " << e.what() << std::endl;
    }

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

std::vector<std::string> TelaLista::carregarDadosJogadores() {
    std::vector<std::string> jogadores;
    std::ifstream arquivo(historico.getNomeArquivo());
    std::string linha;

    if (arquivo.is_open()) {
        // Ignorar o cabeçalho
        std::getline(arquivo, linha);
        
        while (std::getline(arquivo, linha)) {
            jogadores.push_back(linha);
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de dados." << std::endl;
    }
    return jogadores; // Retorne a lista de jogadores
}
void TelaLista::desenharJogadores() {
    sf::Text texto;
    texto.setFont(fonte);
    texto.setCharacterSize(15);
    texto.setFillColor(sf::Color::Black);

    float yOffset = 250.f;

    for (const std::string& jogador : carregarDadosJogadores()) {
        texto.setString(jogador);
        texto.setPosition(180.f, yOffset);
        window.draw(texto);
        yOffset += 30.f;
    }
}

void TelaLista::desenharLista() {
    try {
        Wallpaper wallpaper("menuListaJogadores.png");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao carregar o wallpaper do menu: " << e.what() << std::endl;
    }
    desenharJogadores();
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
    try {
        Wallpaper wallpaper("menuExcluirConta.png");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao carregar o wallpaper do menu: " << e.what() << std::endl;
    }

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
void TelaEstatisticas::desenharTexto(const std::string& texto, float x, float y, float tamanho, sf::Color cor) {
    sf::Text textoSFML;
    textoSFML.setFont(fonte);
    textoSFML.setString(texto);
    textoSFML.setCharacterSize(tamanho);
    textoSFML.setFillColor(cor);
    textoSFML.setPosition(x, y);
    window.draw(textoSFML);
}

void TelaEstatisticas::setJogador(const Jogador& jogador) {
    this->jogador = jogador;
}

void TelaEstatisticas::desenharEstatisticas() {
    try {
        Wallpaper wallpaper("menuEstatisticas.png");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao carregar o wallpaper do menu: " << e.what() << std::endl;
    }

    botaoApelido.desenhar(window);
    botaoVoltar.desenhar(window);
    botaoPesquisa.desenhar(window);
    campoPesquisa.desenhar(window);

    // Exibir as estatísticas do jogador, se houver dados
    if (jogador.getNome() != "") { // Assumindo que o nome não pode ser vazio para um jogador válido
        desenharTexto(std::to_string(jogador.getVitoriasReversi()), 425.f, 285.f, 24.f, sf::Color::White);
        desenharTexto(std::to_string(jogador.getDerrotasReversi()), 425.f, 285+50.f, 24.f, sf::Color::White);
        desenharTexto(std::to_string(jogador.getEmpatesReversi()), 425.f, 285+100.f, 24.f, sf::Color::White);
        desenharTexto(std::to_string(jogador.getVitoriasLig4()), 425.f, 285+140.f, 24.f, sf::Color::White);
        desenharTexto(std::to_string(jogador.getDerrotasLig4()), 425.f, 285+190.f, 24.f, sf::Color::White);
        desenharTexto(std::to_string(jogador.getEmpatesLig4()), 425.f, 285+230.f, 24.f, sf::Color::White);
    } else {
        desenharTexto("Nenhum jogador selecionado.", 327.f, 200.f, 15.f, sf::Color::Red);
    }
}



FimDeJogoLig4::FimDeJogoLig4(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
    botaoMenu(150.f, 70.f, 175, 541, sf::Color(150, 129, 250), "Menu", 25.f, false, sf::Color(43, 0, 108)),
    botaoRestart(254.f, 70.f, 570, 541, sf::Color(150, 129, 250), "Restart", 25.f, false, sf::Color(43, 0, 108)) {
        botaoMenu.criarBotoes();
        botaoRestart.criarBotoes();

        textoVencedor.setFont(fonte);
        textoVencedor.setCharacterSize(40); // Ajuste o tamanho da fonte conforme necessário
        textoVencedor.setFillColor(sf::Color(255, 225, 97)); // Ajuste a cor conforme necessário
        textoVencedor.setPosition(310.f, 300.f); // Ajuste a posição conforme necessário
    }
void FimDeJogoLig4::desenharTelaFinal(const std::string& nomeVencedor) {
    try {
        Wallpaper wallpaper("telaFimDeJogo.png");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao carregar o wallpaper do menu: " << e.what() << std::endl;
    }
    // Configura o texto do vencedor
    textoVencedor.setString(nomeVencedor);
    // Desenha os elementos na tela
    window.draw(textoVencedor);
    botaoMenu.desenhar(window);
    botaoRestart.desenhar(window);
}

//FimDeJogoRevesi
FimDeJogoRevesi::FimDeJogoRevesi(sf::RenderWindow& window, sf::Font& fonte) : window(window), fonte(fonte),
    botaoMenu(150.f, 70.f, 175, 541, sf::Color(150, 129, 250), "Menu", 25.f, false, sf::Color(43, 0, 108)),
    botaoRestart(254.f, 70.f, 570, 541, sf::Color(150, 129, 250), "Restart", 25.f, false, sf::Color(43, 0, 108)) {
        botaoMenu.criarBotoes();
        botaoRestart.criarBotoes();

        textoVencedor.setFont(fonte);
        textoVencedor.setCharacterSize(40); // Ajuste o tamanho da fonte conforme necessário
        textoVencedor.setFillColor(sf::Color(255, 225, 97)); // Ajuste a cor conforme necessário
        textoVencedor.setPosition(310.f, 300.f); // Ajuste a posição conforme necessário
    }
void FimDeJogoRevesi::desenharTelaFinal(const std::string& nomeVencedor) {
    
    try {
        Wallpaper wallpaper("telaFimDeJogo.png");
        wallpaper.redimensionar(window.getSize());
        wallpaper.desenhar(window);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro ao carregar o wallpaper do menu: " << e.what() << std::endl;
    }
    
    // Configura o texto do vencedor
    textoVencedor.setString(nomeVencedor);
    // Desenha os elementos na tela
    window.draw(textoVencedor);
    botaoMenu.desenhar(window);
    //botaoRestart.desenhar(window);
}
