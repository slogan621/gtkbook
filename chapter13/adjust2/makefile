CC = gcc -g 

all: adjust

adjust: adjust.o 
	$(CC) `gtk-config --libs` adjust.o -o adjust

adjust.o: adjust.c 
	$(CC) `gtk-config --cflags` -c adjust.c -o adjust.o

clean:
	rm adjust *.o
