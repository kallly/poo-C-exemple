CC=gcc
CFLAGS= -Wall -ansi  -pedantic -std=c11
LDFLAGS=
EXEC=compte

all: $(EXEC) clean

compte: ComptePayant.o CompteEpargne.o Compte.o Client.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: ComptePayant.h CompteEpargne.h Compte.h Client.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
