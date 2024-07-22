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
#ifndef SOLVER_HASHTABLE_H_
#define SOLVER_HASHTABLE_H_ 1
#include"core-def.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 *
 */
typedef struct hash_table_t {
	void* pair;         /*  */
	int nrElements;     /*  */
	int nrReserved;     /*  */
	int typeSize;       /*  */
} HashTable;

extern int hashTableAllocate(HashTable* hashTable, unsigned int nrElements, unsigned int typeSize);
extern int hashTableCreate(HashTable* hashTable, unsigned int nrElements, unsigned int typeSize);
extern int hashTableReHash(HashTable* hashTable, unsigned int size);
extern int hashTableResize(int size);
extern int hashTableAdd(HashTable* hashTable, unsigned int key, const void* pObject);
extern int hashTableRemove(HashTable* hashTable, unsigned int key);
extern int hashTableSize(const HashTable* hashTable);
extern int hashTableNrElements(const HashTable* hashTable);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif
#endif