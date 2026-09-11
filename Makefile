CC = gcc
CFLAGS = -Wall -g

ls_grep_pipe: ls_grep_pipe.c
	$(CC) $(CFLAGS) -o ls_grep_pipe ls_grep_pipe.c

prog5: prog5.c
	$(CC) $(CFLAGS) -o prog5 prog5.c

wait_waitpid_demo: wait_waitpid_demo.c
	$(CC) $(CFLAGS) -o wait_waitpid_demo  wait_waitpid_demo.c

process: process.c
	$(CC) $(CFLAGS) -o process process.c
prog2: prog2.c
	$(CC) $(CFLAGS) -o prog2 prog2.c
prog1: prog1.c
	$(CC) $(CFLAGS) -o prog1 prog1.c
all: ls_grep_pipe prog5 wait_waitpid_demo process prog2 prog1

clean:
	rm -f prog1 prog2 process wait_waitpid_demo.c prog5 ls_grep_pipe

