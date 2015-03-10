#ifndef _DLIST_H
#define _DLIST_H

#ifdef __cplusplus
extern "C"{
#endif

typedef enum {
	DLIST_OK = 0,
	DLIST_STOP,
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

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _DLIST_H */
