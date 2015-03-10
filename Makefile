all: dlist

dlist: dlist_main.o dlist.o
	gcc dlist_main.o dlist.o -o dlist_test

dlist_main.o: dlist_main.c
	gcc -c dlist_main.c

dlist.o: dlist.c
	gcc -c dlist.c

clean:
	rm *.o dlist_test

