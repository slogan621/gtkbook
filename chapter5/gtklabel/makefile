CC = gcc -g

all: gtklabel

gtklabel: gtklabel.o 
	$(CC) `gtk-config --libs` gtklabel.o -o gtklabel 

gtklabel.o: gtklabel.c 
	$(CC) `gtk-config --cflags` -c gtklabel.c -o gtklabel.o

clean:
	rm gtklabel *.o
