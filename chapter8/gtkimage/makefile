CC = gcc -g

all: gtkimage

gtkimage: gtkimage.o 
	$(CC) `gtk-config --libs` gtkimage.o -o gtkimage -ltiff

gtkimage.o: gtkimage.c 
	$(CC) `gtk-config --cflags` -c gtkimage.c -o gtkimage.o 

clean:
	rm gtkimage *.o
