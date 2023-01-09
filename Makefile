CC = g++
CFLAGS = -Wall -O2 -std=c++11

all: Graphe_Test

Graphe_Test: Graphe_Test.o Sudoku.o
	$(CC) $(CFLAGS) -o Graphe_Test Sudoku.o

Graphe_Test.o: Graphe_Test.cpp Graphe.hpp
	$(CC) $(CFLAGS) -c Graphe_Test.cpp -o Graphe_Test.o

Sudoku.o: Sudoku.cpp Sudoku.hpp
	$(CC) $(CFLAGS) -c Sudoku.cpp -o Sudoku.o

clean:
	rm -f Graphe_Test *.o
