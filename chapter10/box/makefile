CC = gcc -g 

all: box

box: box.o 
	$(CC) `gtk-config --libs` box.o -o box 

box.o: box.c 
	$(CC) `gtk-config --cflags` -c box.c -o box.o

clean:
	rm box *.o
