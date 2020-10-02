#ifndef SOLVER_ARRAY_H_
#define SOLVER_ARRAY_H_ 1

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

typedef struct array_t {
	void* pData;
	unsigned int nrElements;
	unsigned int reserved;
} Array;

extern void allocateArray(Array* array, unsigned int nrReserved, unsigned int typeSize);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif