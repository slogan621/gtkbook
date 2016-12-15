CC = gcc -g

all: signals

signals: signals.o 
	$(CC) `gtk-config --libs` signals.o -o signals 

signals.o: signals.c 
	$(CC) `gtk-config --cflags` -c signals.c -o signals.o

clean:
	rm signals *.o

