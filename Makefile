all: test

dlist: main.o hello.o
	g++ main.o factorial.o hello.o -o hello

main.o: main.cpp
	g++ -c main.cpp

dlist.o: dlist.c
	gcc -c dlist.c

clean:
	rm *.o

