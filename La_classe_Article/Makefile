CC=gcc
CFLAGS= -Wall -ansi -std=c11
LDFLAGS=
EXEC=article

all: $(EXEC) clean

article: Article.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: Article.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
