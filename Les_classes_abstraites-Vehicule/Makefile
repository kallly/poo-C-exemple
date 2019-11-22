CC=gcc
CFLAGS= -Wall -ansi -pedantic -std=c11
LDFLAGS=
EXEC=vehicule

all: $(EXEC) clean

vehicule: Vehicule.o Camion.o Voiture.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Vehicule.h Camion.h Voiture.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
