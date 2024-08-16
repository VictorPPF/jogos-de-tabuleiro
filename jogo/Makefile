# Diretórios e variáveis
INCLUDE_DIRS = -Iinclude -IC:\SFML-2.6.1\include
LIB_DIRS = -LC:\SFML-2.6.1\lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

# Lista de arquivos objeto
OBJECTS = obj/Interacao.o obj/Wallpaper.o obj/jogo_principal.o obj\Tabuleiro.o obj/Historico.o obj/Jogador.o obj/CampoTexto.o obj/Telas.o

# Alvo principal
all: link

# Compilação dos arquivos fonte em objetos
obj/%.o: src/%.cpp
	g++ $(INCLUDE_DIRS) -c $< -o $@

# Linkagem dos objetos para criar o executável
link: $(OBJECTS)
	g++ $(OBJECTS) -o bin/Jogo_executavel $(LIB_DIRS) $(LIBS)

# Rodar o executável
run:
	./bin/Jogo_executavel.exe

# Limpar os arquivos objeto e o executável
clean:
	del obj\*.o
	del bin\Jogo_executavel.exe