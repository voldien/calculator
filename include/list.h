#ifndef SOLVER_LIST_H_
#define SOLVER_LIST_H_ 1

#ifdef __cplusplus
extern "C"{
#endif

typedef struct list_node_t {
	struct list_node_t *next;
	struct list_node_t *prev;
	void *pdata[0];
} ListNode;

typedef struct list_t {
	unsigned int nrNodes;
	unsigned int nrReserved;
	unsigned int elementSize;
	ListNode *begin;
	ListNode *current;
	ListNode *end;
} List;

extern void listAllocate(List *list, unsigned int elementSize, unsigned int reserved);

extern void listDealloc(List *list);

extern void listResize(List *list, unsigned int nrElements);

extern void *listNext(List *list);

extern void *listPrev(List *list);

extern void* listPeek(const List* list);

extern void listInsert(List *list, unsigned int index, const void *element);

extern void listAppend(List *list, const void *element);

extern void listRemoveAt(List *list, unsigned int index);

extern void *listGet(List *list, int i);

extern void listClear(List *pList);

extern unsigned int listSize(const List *list);

extern unsigned int listReserved(const List *list);

#ifdef __cplusplus
}
#endif

#endif