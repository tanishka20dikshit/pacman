all: compile link

compile:
	g++ -std=c++11 -Isrc/include -c code/*.cpp

link:
	g++ *.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio