CC = gcc -g

all: events1

events1: events1.o 
	$(CC) `gtk-config --libs` events1.o -o events1 

events1.o: events1.c 
	$(CC) `gtk-config --cflags` -c events1.c -o events1.o

clean:
	rm events1 *.o
