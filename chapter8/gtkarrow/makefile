CC = gcc -g 

all: gtkarrow

gtkarrow: gtkarrow.o 
	$(CC) `gtk-config --libs` gtkarrow.o -o gtkarrow 

gtkarrow.o: gtkarrow.c 
	$(CC) `gtk-config --cflags` -c gtkarrow.c -o gtkarrow.o

clean:
	rm *.o gtkarrow
