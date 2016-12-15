CC = gcc -g

all: yesno.o

yesno.o: yesno.c 
	$(CC) `gtk-config --cflags` -c yesno.c -o yesno.o

clean:
	rm *.o
