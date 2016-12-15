CC = gcc -g

all: gtkpixmap

gtkpixmap: gtkpixmap.o 
	$(CC) `gtk-config --libs` gtkpixmap.o -o gtkpixmap 

gtkpixmap.o: gtkpixmap.c 
	$(CC) `gtk-config --cflags` -c gtkpixmap.c -o gtkpixmap.o

clean:
	rm gtkpixmap *.o
