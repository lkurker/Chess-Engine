CC = g++
CFLAGS = -g -Wall

main: piece.o board.o main.o
	$(CC) $(CFLAGS) piece.o board.o main.o -o main

board.o: board.cpp board.h piece.h
	$(CC) $(CFLAGS) -c board.cpp

piece.o: piece.cpp piece.h
	$(CC) $(CFLAGS) -c piece.cpp

main.o: main.cpp board.h piece.h
	$(CC) $(CFLAGS) -c main.cpp

run: main
	./main