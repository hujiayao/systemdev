#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "dlist.h"

static DListRet
print_int(void *data, void *ctx)
{
	int tmp = (int)(uintptr_t)data;
	printf("node data: %d\n", tmp);
	return (DLIST_OK);
}

static DListRet
sum_cb(void *data, void *ctx)
{
	int *result = ctx;
	*result += (int)(uintptr_t)data;
	return (DLIST_OK);
}

static void
int_test(void)
{
	DList *list = NULL;
	DListNode *node = NULL;
	int sum = 0;

	list = (DList *)malloc(sizeof (DList));
	list->first = NULL;

	node = (DListNode *)malloc(sizeof (DListNode));
	node->data = (void *) 1;
	node->next = NULL;
	node->prev = NULL;

	node->prev = list->first;
	list->first = node;

	node = (DListNode *)malloc(sizeof (DListNode));
	node->data = (void *) 2;
	node->prev = list->first->prev;
	node->next = list->first;
	list->first = node;
	(void) dlist_foreach(list, print_int, NULL);
	(void) dlist_foreach(list, sum_cb, &sum);
	printf("sum int data: %d\n", sum);
	
}

int
main(int argc, char *argv[])
{
	int_test();
	return (0);
}
