CC = gcc -g

all: casts

casts: casts.o 
	$(CC) `gtk-config --libs` casts.o -o casts 

casts.o: casts.c 
	$(CC) `gtk-config --cflags` -c casts.c -o casts.o

clean:
	rm casts *.o
