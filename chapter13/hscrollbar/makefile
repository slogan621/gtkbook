CC = gcc -g 

all: hscroll

hscroll: hscroll.o 
	$(CC) `gtk-config --libs` hscroll.o -o hscroll

hscroll.o: hscroll.c 
	$(CC) `gtk-config --cflags` -c hscroll.c -o hscroll.o

clean:
	rm hscroll *.o
