CC = gcc -g

all: args args2 args3

args: args.o 
	$(CC) `gtk-config --libs` args.o -o args 

args2: args2.o 
	$(CC) `gtk-config --libs` args2.o -o args2 

args3: args3.o 
	$(CC) `gtk-config --libs` args3.o -o args3 

args.o: args.c 
	$(CC) `gtk-config --cflags` -c args.c -o args.o

args2.o: args2.c 
	$(CC) `gtk-config --cflags` -c args2.c -o args2.o

args3.o: args3.c 
	$(CC) `gtk-config --cflags` -c args3.c -o args3.o

clean:
	rm args args2 args3 *.o
