#include "stack.h"
#include "error.h"
#include <stdlib.h>

int createStack(Stack *stack, long int typeSize, long int nrReserved) {
	stack->buffer = malloc(typeSize * nrReserved);
	if (stack->buffer) {
		return -1;
	}
	stack->index = 0;
	stack->nrReserved = nrReserved;
	stack->typeSize = typeSize;
	return SOL_OK;
}

int deleteStack(Stack *stack) {
	free(stack);
	return SOL_OK;
}

void *push(Stack *stack) {
	stack->index++;
	return &stack->buffer[stack->index * stack->typeSize];
}

void *pop(Stack *stack) {
	stack->index--;
	return &stack->buffer[stack->index * stack->typeSize];
}

int nrElements(const Stack *stack) { return stack->index; }

int stackNrReserved(Stack *stack) { return stack->nrReserved; }

void *stackPeek(const Stack *stack) { return &stack->buffer[stack->index * stack->typeSize]; }