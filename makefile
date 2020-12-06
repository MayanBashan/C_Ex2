CC=gcc
FLAGS=-Wall -g

all: prog
prog: main.o myBank.o
	$(CC) $(FLAGS) -o prog main.o myBank.o
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean all
clean:
	rm -f *.o *.a *.s prog