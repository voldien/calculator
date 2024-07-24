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
#ifndef SOLVER_ARRAY_H_
#define SOLVER_ARRAY_H_ 1

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

typedef struct array_t {
	void *pData;
	unsigned int nrElements;
	unsigned int reserved;
} Array;

extern void allocateArray(Array *array, unsigned int nrReserved, unsigned int typeSize);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif