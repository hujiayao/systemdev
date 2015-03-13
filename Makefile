all: dlist

dlist: dlist_main.o dlist.o
	gcc -g dlist_main.o dlist.o -o dlist_test

dlist_main.o: dlist_main.c
	gcc -g -c dlist_main.c

dlist.o: dlist.c
	gcc -g -c dlist.c

clean:
	rm *.o dlist_test

