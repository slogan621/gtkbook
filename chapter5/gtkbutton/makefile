CC = gcc -g

all: gtkbutton

gtkbutton: gtkbutton.o 
	$(CC) `gtk-config --libs` gtkbutton.o -o gtkbutton 

gtkbutton.o: gtkbutton.c 
	$(CC) `gtk-config --cflags` -c gtkbutton.c -o gtkbutton.o

clean:
	rm gtkbutton *.o
