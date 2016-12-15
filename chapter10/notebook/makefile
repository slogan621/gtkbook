CC = gcc -g 

all: notebook

notebook: notebook.o 
	$(CC) `gtk-config --libs` notebook.o -o notebook 

notebook.o: notebook.c 
	$(CC) `gtk-config --cflags` -c notebook.c -o notebook.o

clean:
	rm notebook *.o
