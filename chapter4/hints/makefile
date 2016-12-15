CC = gcc -g

all: hints

hints: hints.o 
	$(CC) `gtk-config --libs` hints.o -o hints 

hints.o: hints.c 
	$(CC) `gtk-config --cflags` -c hints.c -o hints.o

clean:
	rm hints *.o
