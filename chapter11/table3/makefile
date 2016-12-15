CC = gcc -g -DUSE_FRAMES

all: table

table: table.o 
	$(CC) `gtk-config --libs` table.o -o table 

table.o: table.c 
	$(CC) `gtk-config --cflags` -c table.c -o table.o

clean:
	rm table *.o
