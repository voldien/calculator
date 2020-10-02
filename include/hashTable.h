
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