
#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_ 1
#include "scope.h"
#include "cstring.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef struct symbol_t {
	unsigned int type;
	CString string;
} Symbol;

typedef struct symbol_table_t {
	Scope scope;
} SymbolTable;

#ifdef __cplusplus
}
#endif

#endif