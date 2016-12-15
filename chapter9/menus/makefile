CC = gcc -g 

all: menu

menu: menu.o 
	$(CC) `gtk-config --libs` menu.o -o menu 

menu.o: menu.c 
	$(CC) `gtk-config --cflags` -c menu.c -o menu.o

clean:
	rm menu *.o
