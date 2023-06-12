CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: test1

test1: test1.o creation_matrice.o
	$(CC) $(CFLAGS) -o test1 test1.o creation_matrice.o

test1.o: test1.c creation_matrice.h
	$(CC) $(CFLAGS) -c test1.c

creation_matrice.o: creation_matrice.c creation_matrice.h
	$(CC) $(CFLAGS) -c creation_matrice.c

clean:
	rm -f test1 test1.o creation_matrice.o
