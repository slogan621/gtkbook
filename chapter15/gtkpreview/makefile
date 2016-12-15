CC = gcc -g

all: gtkpreview

gtkpreview: gtkpreview.o 
	$(CC) `gtk-config --libs` gtkpreview.o -o gtkpreview -ltiff

gtkpreview.o: gtkpreview.c 
	$(CC) `gtk-config --cflags` -c gtkpreview.c -o gtkpreview.o 

clean:
	rm gtkpreview *.o
