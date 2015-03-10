#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

DListRet
dlist_foreach(DList *list, DListVisit visit, void *ctx)
{
	DListRet err = DLIST_OK;
	DListNode *iter = list->first;

	while (iter != NULL && err == DLIST_OK) {
		err = visit(iter->data, ctx);
		iter = iter->next;
	}
}
