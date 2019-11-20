CC=gcc
CFLAGS= -Wall -ansi -pedantic -std=c11
LDFLAGS= -lm
EXEC=cercle

all: $(EXEC) clean

cercle: Cercle.o Point.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Cercle.h Point.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
