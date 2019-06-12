CC = gcc
CFLAGS = --std=c11 -Wall -Wextra -pedantic -g
LDLIBS = -lm

default: all

all:
	$(CC) $(CFLAGS) main.c -o main $(LDLIBS)

clean:
	rm main
