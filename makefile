CC = g++
CFLAGS = -g -Wall

main: board.o rules.o main.o
	$(CC) $(CFLAGS) board.o rules.o main.o -o main

board.o: board.cpp board.h
	$(CC) $(CFLAGS) -c board.cpp

rules.o: rules.cpp rules.h
	$(CC) $(CFLAGS) -c rules.cpp

main.o: main.cpp board.h piece.h rules.h
	$(CC) $(CFLAGS) -c main.cpp

run: main
	./main