CC = gcc -g

all: gtkhseparator

gtkhseparator: gtkhseparator.o 
	$(CC) `gtk-config --libs` gtkhseparator.o -o gtkhseparator 

gtkhseparator.o: gtkhseparator.c 
	$(CC) `gtk-config --cflags` -c gtkhseparator.c -o gtkhseparator.o

clean:
	rm gtkhseparator *.o
