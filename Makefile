CC = gcc
CFLAGS = -Wall -g

prog2: prog2.c
	$(CC) $(CFLAGS) -o prog2 prog2.c
prog1: prog1.c
	$(CC) $(CFLAGS) -o prog1 prog1.c
all: prog2 prog1

clean:
	rm -f prog1 prog2
