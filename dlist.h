#ifndef _DLIST_H
#define _DLIST_H

#ifdef __cplusplus
extern "C"{
#endif

typedef enum {
	DLIST_OK = 0,
	DLIST_STOP,
	DLIST_NOMEM,
	DLIST_UNKNOWN
} DListRet;

typedef struct _DListNode {
	struct _DListNode *prev;
	struct _DListNode *next;
	void *data;
} DListNode;

typedef struct _DList {
	DListNode *first;  
} DList;

typedef void (*DListPrint)(void *data);
typedef DListRet (*DListVisit)(void *data, void *ctx);

extern DListRet dlist_foreach(DList *, DListVisit, void *);
extern DList *dlist_create(void);
extern size_t dlist_length(DList *);
extern DListRet dlist_insert(DList *, size_t, void *);
extern DListRet dlist_append(DList *, void *);
extern DListRet dlist_prepend(DList *, void *);
extern void dlist_destroy(DList *);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _DLIST_H */
