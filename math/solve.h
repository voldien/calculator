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
#ifndef _SOLVE_H_
#define _SOLVE_H_ 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"transform.h"

#ifdef __cplusplus
extern "C"{
#endif

extern const char* get_version();

/*	Solve any given input.	*/
extern int solve(const char* equation);

#ifdef __cplusplus
}
#endif

#endif
