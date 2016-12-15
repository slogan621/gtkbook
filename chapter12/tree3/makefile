CC = gcc -g 

all: tree

tree: tree.o 
	$(CC) `gtk-config --libs` tree.o -o tree 

tree.o: tree.c 
	$(CC) `gtk-config --cflags` -c tree.c -o tree.o

clean:
	rm tree *.o
