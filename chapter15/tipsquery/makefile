CC = gcc -g

all: tipsquery

tipsquery: tipsquery.o 
	$(CC) `gtk-config --libs` tipsquery.o -o tipsquery 

tipsquery.o: tipsquery.c 
	$(CC) `gtk-config --cflags` -c tipsquery.c -o tipsquery.o

clean:
	rm tipsquery *.o
