CC=gcc
CFLAGS= -Wall -ansi -std=c11
LDFLAGS=
EXEC=batiment

all: $(EXEC) clean

batiment: Batiment.o Maison.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Batiment.h Maison.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
