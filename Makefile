CC = gcc
CFLAGS = -Wall -g

wait_waitpid_demo: wait_waitpid_demo.c
	$(CC) $(CFLAGS) -o wait_waitpid_demo  wait_waitpid_demo.c

process: process.c
	$(CC) $(CFLAGS) -o process process.c
prog2: prog2.c
	$(CC) $(CFLAGS) -o prog2 prog2.c
prog1: prog1.c
	$(CC) $(CFLAGS) -o prog1 prog1.c
all: process prog2 prog1

clean:
	rm -f prog1 prog2 process  wait_waitpid_demo.c
