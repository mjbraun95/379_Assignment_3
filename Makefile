CC = gcc
CFLAGS = -Wall -Wextra

all: a2p2 a3w23

a3w23: a3w23.c
	$(CC) $(CFLAGS) -o a3w23 a3w23.c

a2p2: a2p2.c
	$(CC) $(CFLAGS) -o a2p2 a2p2.c

clean:
	rm -f a2p2 a2p2_test a3w23 a3w23_test