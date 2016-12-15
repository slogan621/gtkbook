CC = gcc -g

all: gtkfilesel 

gtkfilesel: gtkfilesel.o 
	$(CC) `gtk-config --libs` gtkfilesel.o -o gtkfilesel 

gtkfilesel.o: gtkfilesel.c 
	$(CC) `gtk-config --cflags` -c gtkfilesel.c -o gtkfilesel.o 

clean:
	rm gtkfilesel *.o
