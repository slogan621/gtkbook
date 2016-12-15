CC = gcc -g

all: gtkclist

gtkclist: gtkclist.o 
	$(CC) `gtk-config --libs` gtkclist.o -o gtkclist 

gtkclist.o: gtkclist.c 
	$(CC) `gtk-config --cflags` -c gtkclist.c -o gtkclist.o

clean:
	rm gtkclist *.o
