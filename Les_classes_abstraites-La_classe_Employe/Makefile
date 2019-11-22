CC=gcc
CFLAGS= -Wall -ansi -pedantic -std=c11
LDFLAGS=
EXEC=employe

all: $(EXEC) clean

employe: Employe.o Ouvrier.o Cadre.o Patron.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Employe.h Ouvrier.h Cadre.h Patron.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
