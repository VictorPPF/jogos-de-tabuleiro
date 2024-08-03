all: compile link

compile:
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/Lig4_main.cpp -o obj/Lig4_main.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/ExecutaPartida.cpp -o obj/ExecutaPartida.o

link:
	g++ obj/Lig4_main.o obj/ExecutaPartida.o -o bin/Lig4_BETA -LC:\SFML-2.6.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

run:
	./bin/Lig4_BETA.exe

clean:
	del obj\Lig4_main.o 
	del obj\ExecutaPartida.o
	del bin\Lig4_BETA.exe