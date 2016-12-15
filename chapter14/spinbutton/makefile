CC = gcc -g

all: spinbutton

spinbutton: spinbutton.o 
	$(CC) `gtk-config --libs` spinbutton.o -o spinbutton 

spinbutton.o: spinbutton.c 
	$(CC) `gtk-config --cflags` -c spinbutton.c -o spinbutton.o

clean:
	rm spinbutton *.o
