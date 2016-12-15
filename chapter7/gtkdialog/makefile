CC = gcc -g

all: gtkdialog gtkdialog2 gtkdialog3 gtkdialog4

gtkdialog: gtkdialog.o 
	$(CC) `gtk-config --libs` gtkdialog.o -o gtkdialog 

gtkdialog.o: gtkdialog.c 
	$(CC) `gtk-config --cflags` -c gtkdialog.c -o gtkdialog.o 

gtkdialog2: gtkdialog2.o 
	$(CC) `gtk-config --libs` gtkdialog2.o -o gtkdialog2 

gtkdialog2.o: gtkdialog2.c 
	$(CC) `gtk-config --cflags` -c gtkdialog2.c -o gtkdialog2.o 

gtkdialog3: gtkdialog3.o 
	$(CC) `gtk-config --libs` gtkdialog3.o -o gtkdialog3 

gtkdialog3.o: gtkdialog3.c 
	$(CC) `gtk-config --cflags` -c gtkdialog3.c -o gtkdialog3.o 

gtkdialog4: gtkdialog4.o 
	$(CC) `gtk-config --libs` gtkdialog4.o -o gtkdialog4 

gtkdialog4.o: gtkdialog4.c 
	$(CC) `gtk-config --cflags` -c gtkdialog4.c -o gtkdialog4.o 

clean:
	rm gtkdialog gtkdialog2 gtkdialog3 gtkdialog4 *.o
