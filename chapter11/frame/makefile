#CC = gcc -g -DUSE_FRAMES
CC = gcc -g 

all: gtkframe

gtkframe: gtkframe.o 
	$(CC) `gtk-config --libs` gtkframe.o -o gtkframe 

gtkframe.o: gtkframe.c 
	$(CC) `gtk-config --cflags` -c gtkframe.c -o gtkframe.o

clean:
	rm gtkframe *.o
