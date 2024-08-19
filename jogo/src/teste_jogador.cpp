#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "../include/Jogador.hpp"
#include "../include/Historico.hpp" 

TEST_CASE("Teste da classe Jogador") {
    // Testando a criação de um novo jogador
    Jogador jogador1("Alice", "Ali");
    CHECK(jogador1.getNome() == "Alice");
    CHECK(jogador1.getApelido() == "Ali");

    // Testando a alteração do nome
    jogador1.setNome("Alicia");
    CHECK(jogador1.getNome() == "Alicia");

    // Testando a alteração do apelido
    jogador1.setApelido("Lia");
    CHECK(jogador1.getApelido() == "Lia");

    // Testando os resultados
    jogador1.setResultado("Reversi", 5, 3, 2);
 
 // Testando métodos de resultados de partidas
    jogador1.vencedor("Bob", "Reversi");
    // Adicione verificação para garantir que o histórico foi alterado

    jogador1.empate("Lig4", "Charlie");
    // Adicione verificação para garantir que o empate foi registrado

    // Teste para a exclusão de conta
    jogador1.excluirConta();
    // Adicione verificação para garantir que a conta foi realmente excluída
}
