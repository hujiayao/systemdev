#ifndef _DLIST_H
#define _DLIST_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct _DListNode {
	struct _DListNode *prev;
	struct _DListNode *next;
	void *data;
} DListNode;

typedef struct _DList {
	DListNode *first;  
} DList;

typedef int (*DListPrint)(void *data);

extern int dlist_print(DList *, DListPrint);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _DLIST_H */
