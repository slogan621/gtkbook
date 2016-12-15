CC = gcc -g 

all: packer

packer: packer.o 
	$(CC) `gtk-config --libs` packer.o -o packer 

packer.o: packer.c 
	$(CC) `gtk-config --cflags` -c packer.c -o packer.o

clean:
	rm packer *.o
