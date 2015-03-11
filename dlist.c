#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

DList *
dlist_create(void)
{
	DList *list;

	list = (DList *)malloc(sizeof (DList));
	if (list != NULL)
		list->first = NULL;

	return (list);
}

static DListNode *
dlist_node_create(void *data)
{
	DListNode *node;

	node = (DListNode *)malloc(sizeof (DListNode));
	if (node != NULL) {
		node->prev = NULL;
		node->next = NULL;
		node->data = data;
	}
	return (node);
}

/*
 *return the ith index node. If index is greater
 *than DList length, always return the last node
 */
static DListNode *
dlist_get_node(DList *list, size_t index)
{
	DListNode *iter = list->first;

	while (iter != NULL && iter->next != NULL && index > 0) {
		iter = iter->next;
		index--;
	}

	return (iter);
}

size_t
dlist_length(DList *list)
{
	DListNode *iter;
	size_t length = 0;

	assert(list != NULL);

	iter = list->first;
	while (iter != NULL) {
		iter = iter->next;
		length++;
	}
	return (length);
}

/*
 *if index == -1, insert the node to the end of the list
 */
DListRet
dlist_insert(DList *list, size_t index, void *data)
{
	DListNode *node;
	DListNode *tmp = NULL;

	assert(list != NULL);

	if((node = dlist_node_create(data)) == NULL)
		return (DLIST_NOMEM);

	if (list->first == NULL) {
		list->first = node;
		return (DLIST_OK);
	}
	if (index == 0) {
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
		return (DLIST_OK);
	}

	tmp = dlist_get_node(list, index);
	if (index < dlist_length(list)) {
		tmp->prev->next = node;
		node->prev = tmp->prev;
		node->next = tmp;
		tmp->prev = node;
		
	} else {
		tmp->next = node;
		node->prev = tmp;
	}
	return (DLIST_OK);
}

DListRet
dlist_append(DList *list, void *data)
{
	return (dlist_insert(list, -1, data));
}

DListRet
dlist_prepend(DList *list, void *data)
{
	return (dlist_insert(list, 0, data));
}

void
dlist_destroy(DList *list)
{
	DListNode *iter;
	DListNode *tmp;
	
	if (list == NULL)
		return;

	iter = list->first;
	while(iter != NULL) {
		tmp = iter;
		iter = iter->next;
		free(tmp);
	}
	list->first = NULL;
	free(list);
	return;
}
