

#ifndef _SOLVE_H_
#define _SOLVE_H_ 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"transform.h"

#ifdef __cplusplus
extern "C"{
#endif

/*	Solve any given input.	*/
extern int solve(const char* equation);

/*	solve integral.	*/
extern double solveIntegral(const char* equation);

/**/
extern double solvearithmetic(const char* equation, long* answ);

/**/
extern double solveEquation(const char* equatioin);


#ifdef __cplusplus
}
#endif

#endif
