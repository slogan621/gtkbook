CC = gcc -g 

all: itemfactory

itemfactory: itemfactory.o 
	$(CC) `gtk-config --libs` itemfactory.o -o itemfactory 

itemfactory.o: itemfactory.c 
	$(CC) `gtk-config --cflags` -c itemfactory.c -o itemfactory.o

clean:
	rm itemfactory *.o
