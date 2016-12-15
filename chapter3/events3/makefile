CC = gcc -g

all: events3

events3: events3.o 
	$(CC) `gtk-config --libs` events3.o -o events3 

events3.o: events3.c 
	$(CC) `gtk-config --cflags` -c events3.c -o events3.o

clean:
	rm events3 *.o
