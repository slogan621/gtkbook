CC = gcc -g 

all: layout

layout: layout.o 
	$(CC) `gtk-config --libs` layout.o -o layout

layout.o: layout.c 
	$(CC) `gtk-config --cflags` -c layout.c -o layout.o

clean:
	rm layout *.o
