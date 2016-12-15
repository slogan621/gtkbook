CC = gcc -g

all: snoop

snoop: snoop.o 
	$(CC) `gtk-config --libs` snoop.o -o snoop

snoop.o: snoop.c 
	$(CC) `gtk-config --cflags` -c snoop.c -o snoop.o

clean:
	rm snoop *.o

