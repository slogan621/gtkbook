CC = gcc -g

all: gtklist

gtklist: gtklist.o 
	$(CC) `gtk-config --libs` gtklist.o -o gtklist 

gtklist.o: gtklist.c 
	$(CC) `gtk-config --cflags` -c gtklist.c -o gtklist.o

clean:
	rm gtklist *.o
