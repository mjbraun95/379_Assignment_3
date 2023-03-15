CC = gcc
# CFLAGS = -Wall -Wextra
# CFLAGS = 

all: a2p2 a3w23

a3w23: a3w23.c
	$(CC) -o a3w23 a3w23.c

a2p2: a2p2.c
	$(CC) -o a2p2 a2p2.c

clean:
	rm -f a2p2 a2p2_test a3w23 a3w23_test 