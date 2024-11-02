CC = gcc
CFLAGS = -Wall

all:
	$(CC) $(CFLAGS) -o rsa rsa.c 