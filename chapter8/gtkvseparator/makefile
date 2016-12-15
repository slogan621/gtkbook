CC = gcc -g

all: gtkvseparator

gtkvseparator: gtkvseparator.o 
	$(CC) `gtk-config --libs` gtkvseparator.o -o gtkvseparator 

gtkvseparator.o: gtkvseparator.c 
	$(CC) `gtk-config --cflags` -c gtkvseparator.c -o gtkvseparator.o

clean:
	rm gtkvseparator *.o
