CC = gcc -g 

all: toolbar

toolbar: toolbar.o 
	$(CC) `gtk-config --libs` toolbar.o -o toolbar 

toolbar.o: toolbar.c 
	$(CC) `gtk-config --cflags` -c toolbar.c -o toolbar.o

clean:
	rm toolbar *.o
