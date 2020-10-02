#ifndef _TREE_H_
#define _TREE_H_ 1
#include<stdlib.h>

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

typedef struct node_t {
	/*  Tree Relation.  */
	struct node_t *parent;
	struct node_t *sibling;
	struct node_t *chid;
	int nrChildrens;
	/*  Internal object.    */
	void *_data;     /**/
} Node;

extern void treeAddNode(Node *root, Node *child);
extern void treeSetParent(Node *node, Node *parent);
extern void treeSetChild(Node *node, int nthChild, Node *child);

extern Node *treeGetParent(Node *parent);
extern int treeIsRoot(Node* node);
extern int treeNumChildren(Node *parent);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif