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
#ifndef _CORE_SOLVER_TREE_H_
#define _CORE_SOLVER_TREE_H_ 1
#include <stdlib.h>

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

typedef struct node_t {
	/*  Tree Relation.  */
	struct node_t *parent;
	struct node_t *sibling;
	struct node_t *child;
	int numChildren;
	/*  Internal object.    */
	void *_data; /**/
} Node;

typedef struct tree_t {
	unsigned int nrNodes;
	Node *nodes;
} Tree;

extern void createTree(Tree **tree, unsigned int nodes);
extern void treeAddNode(Tree *root, Node *child);
extern void treeSetParent(Tree *node, Node *parent);
extern void treeSetChild(Tree *node, int nthChild, Node *child);

extern Node *treeGetParent(Tree *parent);
extern int treeIsRoot(Node *node);
extern int treeNumChildren(Node *parent);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif