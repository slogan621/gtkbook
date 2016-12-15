CC = gcc -g

all: drawing

drawing: drawing.o 
	$(CC) `gtk-config --libs` drawing.o -o drawing 

drawing.o: drawing.c 
	$(CC) `gtk-config --cflags` -c drawing.c -o drawing.o

clean:
	rm drawing *.o
