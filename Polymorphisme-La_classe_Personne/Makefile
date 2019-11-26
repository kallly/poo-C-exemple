CC=gcc -g
CFLAGS= -Wall -ansi -std=c11
LDFLAGS=
EXEC=personne

all: $(EXEC) clean

personne: Personne.o Employe.o Chef.o Directeur.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Personne.h Employe.h Chef.h Directeur.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
