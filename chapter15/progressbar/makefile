CC = gcc -g

all: progressbar

progressbar: progressbar.o 
	$(CC) `gtk-config --libs` progressbar.o -o progressbar 

progressbar.o: progressbar.c 
	$(CC) `gtk-config --cflags` -c progressbar.c -o progressbar.o

clean:
	rm progressbar *.o
