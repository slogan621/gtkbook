CC = gcc -g

all: events2

events2: events2.o 
	$(CC) `gtk-config --libs` events2.o -o events2

events2.o: events2.c 
	$(CC) `gtk-config --cflags` -c events2.c -o events2.o

clean:
	rm *.o events2
