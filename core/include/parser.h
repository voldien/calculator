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
#ifndef _PARSER_H_
#define _PARSER_H_ 1
#include "lexer.h"
#include "list.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 *
 */
struct parser_t;
struct rule_t;
typedef int (*process_rule)(struct parser_t *parser, struct rule_t *rule);
enum {
	RuleToken = 1,
	RuleSubRule = 2,
};

typedef struct rule_t {
	List *list;
	union {
		Token *sequenceToken; /*  Sequence of tokens. */
		struct rule_t *rule;
	};
	struct rule_t *nextRule;
	process_rule customRule;
} Rule;

typedef struct rule_set_t {
	int nrAlt;
	struct rule_t *altRules;
	const char *name;
} RuleSet;

typedef struct parser_t {
	Lexer *lexer; /*  Lexer analyzer. */

	/*  Parser internal components. */
	List lookahead;
	List makers;
	Token **tokens; /*	LL(k).	*/
	int k;			/*	LL(k).	*/
	int p;			/*  */

	RuleSet *rules;	   /*  */
	int numberofRules; /*  */
} Parser;

// TODO add error and exception handling equivalence.

// TODO add creation for function for creating the rule set.
typedef struct parser_desc_t {
	RuleSet *ruleSet; /*  */
	unsigned int nr;  /*  Number of rules.    */
	unsigned int k;	  /*  LL(k)   */
} ParserDesc;

/*  Parser Allocating and creation functions.   */
extern int allocateParser(Parser **parser);
extern int deallocteParser(Parser *parser);
extern int createParser(Parser *parser, Lexer *lexer, ParserDesc *parserDesc); // TODO add list of rules.
extern int verifyParserRules(RuleSet *ruleSet, unsigned int nRules);
extern int deleteParser(Parser *parser);

/*  Parser parsing functionalities. */
extern int consumeTokens(Parser *parser);
extern int parserMatch(Parser *parser, unsigned int token);
extern int parserSync(Parser *parser, unsigned int index);
extern int fillParser(Parser *parser, unsigned int n);
extern int isSpeculating(const Parser *parser);
extern int releaseSpeculating(Parser *parser);
extern void parserSeek(Parser *parser, int index);
extern int parserMark(Parser *parser);

extern int parserAlreadyParsedRule(Parser *parser);
extern void memoize(Parser *parser, void *memoization, int startTokenIndex, int failed);

extern int parserRuleExecute(Parser *parser, RuleSet *ruleSet);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif