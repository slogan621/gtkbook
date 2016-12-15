CC = gcc -g 

all: text

text: text.o 
	$(CC) `gtk-config --libs` text.o -o text

text.o: text.c 
	$(CC) `gtk-config --cflags` -c text.c -o text.o

clean:
	rm text *.o
