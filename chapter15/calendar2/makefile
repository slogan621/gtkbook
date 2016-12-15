CC = gcc -g

all: calendar

calendar: calendar.o 
	$(CC) `gtk-config --libs` calendar.o -o calendar 

calendar.o: calendar.c 
	$(CC) `gtk-config --cflags` -c calendar.c -o calendar.o

clean: 
	rm calendar *.o
