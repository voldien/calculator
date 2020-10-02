

#ifndef _SOLVE_H_
#define _SOLVE_H_ 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"transform.h"

#ifdef __cplusplus
extern "C"{
#endif

extern const char* get_version(void);
/*	Solve any given input.	*/
extern int solve(const char* equation);

#ifdef __cplusplus
}
#endif

#endif
