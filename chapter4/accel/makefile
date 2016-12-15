CC = gcc -g

all: accel

accel: accel.o 
	$(CC) `gtk-config --libs` accel.o -o accel 

accel.o: accel.c 
	$(CC) `gtk-config --cflags` -c accel.c -o accel.o

clean:
	rm accel *.o

