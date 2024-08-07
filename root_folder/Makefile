all: compile link

compile:
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/test_sfml_lib.cpp -o obj/test_sfml_lib.o
	g++ -Iinclude -IC:\SFML-2.6.1\include -c src/ExecutaPartida.cpp -o obj/ExecutaPartida.o

link:
	g++ obj/test_sfml_lib.o obj/ExecutaPartida.o -o bin/XABLAU -LC:\SFML-2.6.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

run:
	./bin/XABLAU.exe

clean:
	del obj\test_sfml_lib.o 
	del obj\ExecutaPartida.o
	del bin\XABLAU.exe