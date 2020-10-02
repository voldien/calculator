

#ifndef _SCOPE_H_
#define _SCOPE_H_ 1
#include "stack.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

typedef struct scope_t {
	struct scope_t *parent;
} Scope;

extern Scope *scope(void);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif