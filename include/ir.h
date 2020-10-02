#ifndef _IR_H_
#define _IR_H_ 1
#include "parser.h"
#include "tree.h"
#include "snt_pool.h"
#include "symbolTable.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

	//TODO add custom function pointers.
typedef struct ir_root_t{
	Parser* parser;
	Node* root;
	SNTPool* treePool;
	Scope* scope;
}IRRoot;

extern void allocateIR(IRRoot* ir);
extern void createIR(IRRoot* ir, Parser* parser, Node* node);
extern void buildIR(IRRoot* ir);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif
#endif