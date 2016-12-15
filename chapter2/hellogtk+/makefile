CC = gcc -g

all: hellogtk+

hellogtk+: hellogtk+.o 
	$(CC) `gtk-config --libs` hellogtk+.o -o hellogtk+

hellogtk+.o: hellogtk+.c 
	$(CC) `gtk-config --cflags` -c hellogtk+.c -o hellogtk+.o

clean:
	rm hellogtk+ *.o
