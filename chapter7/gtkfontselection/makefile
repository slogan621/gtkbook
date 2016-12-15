CC = gcc -g

all: gtkfontsel 

gtkfontsel: gtkfontsel.o 
	$(CC) `gtk-config --libs` gtkfontsel.o -o gtkfontsel 

gtkfontsel.o: gtkfontsel.c 
	$(CC) `gtk-config --cflags` -c gtkfontsel.c -o gtkfontsel.o 

clean:
	rm gtkfontsel *.o
