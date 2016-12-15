CC = gcc -g

all: destroy

destroy: destroy.o 
	$(CC) `gtk-config --libs` destroy.o -o destroy 

destroy.o: destroy.c 
	$(CC) `gtk-config --cflags` -c destroy.c -o destroy.o

clean:
	rm destroy *.o
