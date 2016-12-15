CC = gcc -g

all: showhide

showhide: showhide.o 
	$(CC) `gtk-config --libs` showhide.o -o showhide 

showhide.o: showhide.c 
	$(CC) `gtk-config --cflags` -c showhide.c -o showhide.o

clean:
	rm showhide *.o
