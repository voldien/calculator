
#ifndef _POOL_H_
#define _POOL_H_ 1
#include <stdio.h>
#include <stdlib.h>
//TODO renmae file and functions.

/**
 *	Pool node element.
 */
typedef struct snt_pool_node_t {
	struct snt_pool_node_t *next;    /*	Next item in the pool frame.	*/
	void *data[];                    /*	Base pointer for the element.	*/
} SNTPoolNode;

/**
 *	Pool allocator container.
 */
typedef struct snt_pool_allocator_t {
	unsigned int num;        /*	Number of allocated elements in pool.	*/
	unsigned int itemsize;    /*	Size of each element in pool.	*/
	SNTPoolNode *pool;        /*	Pool frame.	*/
} SNTPool;


/**
 *	Create Poll allocator.
 *	[next|data]
 *
 *	@Return non null pointer if successfully.
 */
extern SNTPool *sntPoolCreate(unsigned int num,
                              unsigned int itemsize);

/**
 *	Lock pool frame from being swapped to
 *	swap storage.
 */
extern int sntPoolLockMem(SNTPool *poolallocator);

/**
 *	Obtain the next element from pool frame.
 *
 *	If the returned  value is null,
 *	then the allocator is full.
 *
 *	\allocator
 *
 *	Remark: The item may not be memset to 0.
 *
 *	@Return Non null pointer if pool is not full.
 */
extern void *sntPoolObtain(SNTPool *allocator);

/**
 *	Return item to pool. Item will be memset
 *	to zero.
 *
 *	\allocator
 *
 *	@Return current next element in allocator.
 */
extern void *sntPoolReturn(SNTPool *allocator,
                           void *data);

/**
 *	Resize the current pool frame size without removing
 *	current data in the pool frame iff the num is greater
 *	than the current number of elements.
 */
extern void *sntPoolResize(SNTPool *allocator, unsigned int num, unsigned int itemsize);

/**
 *	@Return number of nodes.
 */
extern unsigned int sntPoolNumNodes(const SNTPool *pool);

/**
 *	@Return item size in bytes.
 */
extern unsigned int sntPoolItemSize(const SNTPool *pool);

/**
 *	Get the node index of a valid node.
 */
extern int sntPoolGetIndex(const SNTPool *pool, const void *data);

/**
 *	Free pool.
 *
 *	\allocator
 *
 *	Remark: this function will call 'free' on allocator
 *	and pool frame pointer. The allocator pointer will be
 *	invalid afterward.
 */
extern void sntPoolFree(SNTPool *pool);

#endif
