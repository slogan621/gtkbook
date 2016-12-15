CC = gcc -g

all: priority

priority: priority.o 
	$(CC) `gtk-config --libs` priority.o -o priority

priority.o: priority.c 
	$(CC) `gtk-config --cflags` -c priority.c -o priority.o

clean:
	rm priority *.o
