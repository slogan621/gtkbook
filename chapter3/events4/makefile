CC = gcc -g

all: events4

events4: events4.o 
	$(CC) `gtk-config --libs` events4.o -o events4 

events4.o: events4.c 
	$(CC) `gtk-config --cflags` -c events4.c -o events4.o

clean:
	rm events4 *.o
