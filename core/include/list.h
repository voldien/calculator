/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Valdemar Lindberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 */
#ifndef SOLVER_LIST_H_
#define SOLVER_LIST_H_ 1

#ifdef __cplusplus
extern "C" {
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

extern void *listPeek(const List *list);

extern void listInsert(List *list, unsigned int index, const void *element);

extern void listAppend(List *list, const void *element);

extern void listRemoveAt(List *list, unsigned int index);

extern void *listGet(List *list, int index);

extern void listClear(List *pList);

extern unsigned int listSize(const List *list);

extern unsigned int listReserved(const List *list);

#ifdef __cplusplus
}
#endif

#endif