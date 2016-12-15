CC = gcc -g

all: gtkcolorseldialog 

gtkcolorseldialog: gtkcolorseldialog.o 
	$(CC) `gtk-config --libs` gtkcolorseldialog.o -o gtkcolorseldialog 

gtkcolorseldialog.o: gtkcolorseldialog.c 
	$(CC) `gtk-config --cflags` -c gtkcolorseldialog.c -o gtkcolorseldialog.o 

clean:
	rm gtkcolorseldialog *.o
