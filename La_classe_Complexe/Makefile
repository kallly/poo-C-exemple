CC=gcc
CFLAGS= -Wall -ansi -pedantic -std=c11
LDFLAGS=
EXEC=complexe

all: $(EXEC) clean

complexe: Complexe.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Complexe.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
