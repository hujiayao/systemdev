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

static DListRet
max_cb(void *data, void *ctx)
{
	int *max = ctx;
	if ((int)(uintptr_t)data > *max)
		*max = (int)(uintptr_t)data;
	return (DLIST_OK);
}

static void
int_test(void)
{
	DList *list;
	int sum = 0;
	int max = 0;
	DListRet ret;
	int a = 1, b = 2, c = 3;
	size_t len;

	list = dlist_create();
	if ((ret = dlist_append(list, (void *)(uintptr_t)a)) != DLIST_OK)
		goto fail;
	if ((ret = dlist_append(list, (void*)(uintptr_t)b)) != DLIST_OK)
		goto fail;
	if ((ret = dlist_append(list, (void *)(uintptr_t)c)) != DLIST_OK)
		goto fail;
	if ((ret = dlist_insert(list, 1, (void *)4)) != DLIST_OK)
		goto fail;
	len = dlist_length(list);
	printf("length of the list: %d\n", (unsigned int)len);
	(void) dlist_foreach(list, print_int, NULL);
	(void) dlist_foreach(list, sum_cb, &sum);
	printf("sum int data: %d\n", sum);
	(void) dlist_foreach(list, max_cb, &max);
	printf("max int data: %d\n", max);
	dlist_destroy(list);
	return;

fail:
	printf("dlist fail: %d\n", ret);
	
}

int
main(int argc, char *argv[])
{
	int_test();
	return (0);
}
