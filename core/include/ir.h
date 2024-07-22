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
#ifndef _IR_H_
#define _IR_H_ 1
#include "parser.h"
#include "scope.h"
#include "snt_pool.h"
#include "tree.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

// TODO add custom function pointers.
typedef struct ir_root_t {
	Parser *parser;
	Node *root;
	SNTPool *treePool;
	Scope *scope;
} IRRoot;

extern void allocateIR(IRRoot *ir);
extern void createIR(IRRoot *ir, Parser *parser, Node *node);
extern void buildIR(IRRoot *ir);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif
#endif