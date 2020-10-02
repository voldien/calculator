
#ifndef _STACK_H_
#define _STACK_H_ 1

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

typedef struct stack_t {
	char *buffer;
	long int typeSize;
	long int nrReserved;
	long int index;
} Stack;

extern int createStack(Stack* stack, long int typeSize, long int nrReserved);
extern int deleteStack(Stack* stack);
extern void* push(Stack* stack);
extern void* pop(Stack* stack);
extern int nrElements(Stack* stack);
extern int stackNrReserved(Stack* stack);
extern void* stackPeek(Stack* stack);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif


#endif