CC = gcc -g

all: colorsel 

colorsel: colorsel.o 
	$(CC) `gtk-config --libs` colorsel.o -o colorsel 

colorsel.o: colorsel.c 
	$(CC) `gtk-config --cflags` -c colorsel.c -o colorsel.o

clean:
	rm colorsel *.o
