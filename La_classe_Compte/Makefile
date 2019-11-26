CC=gcc
CFLAGS= -Wall -ansi -pedantic -std=c11
LDFLAGS=
EXEC=compte

all: $(EXEC) clean

compte: Compte.o Client.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Compte.h Client.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
