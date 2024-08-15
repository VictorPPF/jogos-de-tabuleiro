all: compile link

compile:
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/ExecutaPartida.cpp -o obj/ExecutaPartida.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/Wallpaper.cpp -o obj/Wallpaper.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/jogo_principal.cpp -o obj/jogo_principal.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/Tabuleiro.cpp -o obj/Tabuleiro.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/JogoLig4.cpp -o obj/JogoLig4.o
	g++ -c src/Historico.cpp -o obj/Historico.o
	g++ -c src/Jogador.cpp -o obj/Jogador.o

link:
	g++ obj/ExecutaPartida.o obj/Wallpaper.o obj/jogo_principal.o obj\Tabuleiro.o obj/JogoLig4.o obj/Historico.o obj/Jogador.o -o bin/Jogo_executavel -LC:\SFML-2.6.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

run:
	./bin/Jogo_executavel.exe

clean:
	del obj\jogo_principal.o 
	del obj\ExecutaPartida.o
	del obj\Wallpaper.o
	del bin\Jogo_executavel.exe
	del obj\Tabuleiro.o
	del obj\JogoLig4.o