CC = gcc -g

all: colorsel colorseldialog

colorsel: colorsel.o 
	$(CC) `gtk-config --libs` colorsel.o -o colorsel 

colorsel.o: colorsel.c 
	$(CC) `gtk-config --cflags` -c colorsel.c -o colorsel.o

colorseldialog: colorseldialog.o 
	$(CC) `gtk-config --libs` colorseldialog.o -o colorseldialog 

colorseldialog.o: colorseldialog.c 
	$(CC) `gtk-config --cflags` -c colorseldialog.c -o colorseldialog.o

clean:
	rm colorsel colorseldialog *.o
