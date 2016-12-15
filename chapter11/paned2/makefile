CC = gcc -g 

all: paned

paned: paned.o 
	$(CC) `gtk-config --libs` paned.o -o paned 

paned.o: paned.c 
	$(CC) `gtk-config --cflags` -c paned.c -o paned.o

clean:
	rm paned *.o
