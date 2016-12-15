CC = gcc -g

all: statusbar

statusbar: statusbar.o 
	$(CC) `gtk-config --libs` statusbar.o -o statusbar 

statusbar.o: statusbar.c 
	$(CC) `gtk-config --cflags` -c statusbar.c -o statusbar.o

clean:
	rm statusbar *.o
