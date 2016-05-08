

#ifndef _SOLVE_H_ 
#define _SOLVE_H_ 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"transform.h"

#ifdef __cplusplus
extern "C"{
#endif

extern int solve(const char* equation);
extern int solveIntegral(const char* equation);
extern int solvearithmetic(const char* equation,long* answ);


#ifdef __cplusplus
}
#endif

#endif
