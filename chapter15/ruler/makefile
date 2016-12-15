CC = gcc -g

all: ruler ruler2

ruler: ruler.o 
	$(CC) `gtk-config --libs` ruler.o -o ruler 

ruler.o: ruler.c 
	$(CC) `gtk-config --cflags` -c ruler.c -o ruler.o

ruler2: ruler2.o 
	$(CC) `gtk-config --libs` ruler2.o -o ruler2 

ruler2.o: ruler2.c 
	$(CC) `gtk-config --cflags` -c ruler2.c -o ruler2.o

clean:
	rm ruler ruler2 *.o
