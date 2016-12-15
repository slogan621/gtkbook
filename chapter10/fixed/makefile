CC = gcc -g 

all: fixed

fixed: fixed.o 
	$(CC) `gtk-config --libs` fixed.o -o fixed 

fixed.o: fixed.c 
	$(CC) `gtk-config --cflags` -c fixed.c -o fixed.o

clean:
	rm fixed *.o
