CC = gcc -g 

all: ttt

ttt: ttt.o 
	$(CC) `gtk-config --libs` ttt.o -o ttt 

ttt.o: ttt.c 
	$(CC) `gtk-config --cflags` -c ttt.c -o ttt.o

clean:
	rm ttt *.o
