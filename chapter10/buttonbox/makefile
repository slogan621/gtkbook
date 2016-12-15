CC = gcc -g 

all: buttonbox

buttonbox: buttonbox.o 
	$(CC) `gtk-config --libs` buttonbox.o -o buttonbox 

buttonbox.o: buttonbox.c 
	$(CC) `gtk-config --cflags` -c buttonbox.c -o buttonbox.o

clean:
	rm buttonbox *.o
