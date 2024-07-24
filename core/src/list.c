#include "list.h"
#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

void listAllocate(List *list, unsigned int elementSize, unsigned int reserved) {
	list->begin = malloc((unsigned long)elementSize * reserved);
	list->end = list->begin;
	list->elementSize = elementSize;
	list->nrNodes = 0;
	list->nrReserved = reserved;
}
void listDealloc(List *list) { free(list->begin); }

void listResize(List *list, unsigned int nrElements) {
	list->begin = realloc(list->begin, (unsigned long)nrElements * list->elementSize);
	list->nrReserved = nrElements;
}

void *listNext(List *list) {
	list->current = list->current->next;
	return list->current->pdata;
}

void *listPrev(List *list) {
	list->current = list->current->prev;
	return list->current->pdata;
}

void *listPeek(const List *list) { return list->current; }

void listInsert(List *list, unsigned int index, const void *element) {
	unsigned long int offset = ((unsigned long)list->nrNodes * list->elementSize);
	ListNode *insertNode = (ListNode *)&((uint8_t *)list->begin)[offset];
	memcpy(insertNode->pdata, element, list->elementSize);

	// Update list attributes.
	list->current->next->prev = insertNode;
	list->current->next = insertNode;
	list->current = insertNode;
	list->nrNodes++;
}

void listAppend(List *list, const void *element) {
	unsigned long int offset = (list->nrNodes * list->elementSize);
	ListNode *append = &(((uint8_t *)list->begin)[offset]);
	memcpy(append->pdata, element, list->elementSize);

	// Update list attributes.
	append->prev = list->end;
	append->next = NULL;
	list->end = append;
	list->nrNodes++;
}

void listRemoveAt(List *list, unsigned int index) { list->nrNodes--; }

void *listGet(List *list, int i) { return list->current[i].pdata; }

void listClear(List *list) {

	/*  Reset counter.  */
	list->nrNodes = 0;

	/*  Reset start an end point.   */
	list->end = list->begin;
}

unsigned int listSize(const List *list) { return list->nrNodes; }

unsigned int listReserved(const List *list) { return list->nrReserved; }