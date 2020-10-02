#include"ir.h"

void createIR(IRRoot* ir, Parser* parser, Node *node) {
	ir->parser = parser;
	ir->root = node;
}
