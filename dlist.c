#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_print(DList *list, DListPrint print) {
	int err = 0;

	DListNode *iter = list->first;
	while (iter != NULL) {
		print(iter->data);
		iter = iter->next;
	}
	return (err);
}
