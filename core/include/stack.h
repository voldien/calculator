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

extern int createStack(Stack *stack, long int typeSize, long int nrReserved);
extern int deleteStack(Stack *stack);

extern void *push(Stack *stack);
extern void *pop(Stack *stack);

extern int nrElements(const Stack *stack);

extern int stackNrReserved(Stack *stack);
extern void *stackPeek(const Stack *stack);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif