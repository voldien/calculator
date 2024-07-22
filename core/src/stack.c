#include "stack.h"
#include <stdlib.h>

int createStack(Stack *stack, long int typeSize, long int nrReserved) {
	stack->buffer = malloc(typeSize * nrReserved);
	if (stack->buffer) {
		return 0;
	}
	stack->index = 0;
	stack->nrReserved = nrReserved;
	stack->typeSize = typeSize;
	return 1;
}

int deleteStack(Stack *stack) { free(stack); }

void *push(Stack *stack) {
	stack->index++;
	return &stack->buffer[stack->index * stack->typeSize];
}

void *pop(Stack *stack) {
	stack->index--;
	return &stack->buffer[stack->index * stack->typeSize];
}

int nrElements(Stack *stack) { return stack->index; }

int stackNrReserved(Stack *stack) { return stack->nrReserved; }

void *stackPeek(Stack *stack) { return &stack->buffer[stack->index * stack->typeSize]; }