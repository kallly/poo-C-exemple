CC=gcc
CFLAGS= -Wall -ansi  -pedantic -std=c11
LDFLAGS= -lm
EXEC=vecteur

all: $(EXEC) clean

vecteur: Vecteur2D.o Vecteur3D.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o:	Vecteur2D.h Vecteur3D.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
