CC=gcc
CFLAGS= -Wall -ansi -pedantic -std=c11
LDFLAGS= -lm
EXEC=point

all: $(EXEC) clean

point: Point.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Point.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
