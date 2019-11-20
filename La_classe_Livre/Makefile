CC=gcc
CFLAGS= -Wall -ansi -pedantic -std=c11
LDFLAGS=
EXEC=livre

all: $(EXEC) clean

livre: Livre.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Livre.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
