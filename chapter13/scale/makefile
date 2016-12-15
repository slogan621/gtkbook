CC = gcc -g 

all: scale

scale: scale.o 
	$(CC) `gtk-config --libs` scale.o -o scale

scale.o: scale.c 
	$(CC) `gtk-config --cflags` -c scale.c -o scale.o

clean:
	rm scale *.o
