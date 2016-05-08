

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_ 1
#include<stdio.h>
#include<math.h>

#ifdef __cplusplus
extern "C"{
#endif

extern int transform_expression(const char* expression, char** trans_express);

/**
	replace original expression by a simplify expression
*/
extern int insert_expression(const char* paranthes_pos, char* express,const char* replace_express,unsigned int orignal_expression_size);



#ifdef __cplusplus
}
#endif

#endif
