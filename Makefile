CC = g++
CFLAGS = -Wall -O2 -std=c++11

all: Graphe_Projet

Graphe_Projet: Graphe_Projet.o Sudoku.o
	$(CC) $(CFLAGS) -o Graphe_Projet Sudoku.o

Graphe_Projet.o: Graphe_Projet.cpp Graphe.hpp
	$(CC) $(CFLAGS) -c Graphe_Projet.cpp -o Graphe_Projet.o

Graphe.o: Graphe.cpp Graphe.hpp
	$(CC) $(CFLAGS) -c Graphe.cpp -o Graphe.o

Sudoku.o: Sudoku.cpp Sudoku.hpp
	$(CC) $(CFLAGS) -c Sudoku.cpp -o Sudoku.o

clean:
	rm -f Graphe_Projet *.o
