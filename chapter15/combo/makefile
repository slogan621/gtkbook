CC = gcc -g

all: combo combo2 combo3

combo: combo.o 
	$(CC) `gtk-config --libs` combo.o -o combo 

combo.o: combo.c 
	$(CC) `gtk-config --cflags` -c combo.c -o combo.o
combo2: combo2.o 
	$(CC) `gtk-config --libs` combo2.o -o combo2 

combo2.o: combo2.c 
	$(CC) `gtk-config --cflags` -c combo2.c -o combo2.o

combo3: combo3.o 
	$(CC) `gtk-config --libs` combo3.o -o combo3 

combo3.o: combo3.c 
	$(CC) `gtk-config --cflags` -c combo3.c -o combo3.o

clean:
	rm combo combo2 combo3 *.o
