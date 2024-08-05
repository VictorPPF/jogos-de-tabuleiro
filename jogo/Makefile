all: compile link

compile:
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/jogo_principal.cpp -o obj/jogo_principal.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/ExecutaPartida.cpp -o obj/ExecutaPartida.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/Wallpaper.cpp -o obj/Wallpaper.o

link:
	g++ obj/jogo_principal.o obj/ExecutaPartida.o obj/Wallpaper.o -o bin/Jogo_executavel -LC:\SFML-2.6.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

run:
	./bin/Jogo_executavel.exe

clean:
	del obj\jogo_principal.o 
	del obj\ExecutaPartida.o
	del obj\EWallpaper.o
	del bin\Jogo_executavel.exe

all: compile link