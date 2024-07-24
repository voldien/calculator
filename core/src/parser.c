#include "parser.h"
#include "error.h"
#include <malloc.h>
#include <stdio.h>

int allocateParser(Parser **parser) {
	*parser = (Parser *)malloc(sizeof(Parser));

	/*  Allocate essential objects. */
	listAllocate(&(*parser)->lookahead, sizeof(Token *), 64);
	listAllocate(&(*parser)->makers, sizeof(unsigned int), 64);

	return SOL_OK;
}

int deallocteParser(Parser *parser) {

	/*  */
	listDealloc(&parser->lookahead);
	listDealloc(&parser->makers);
	return SOL_OK;
}

int createParser(Parser *parser, Lexer *lexer, const ParserDesc *parserDesc) {

	/*  Verify the parameters.  */
	if (parser == NULL || lexer == NULL || parserDesc == NULL) {
		return SOL_ERROR_INVALID_ARG;
	}

	if (parser->lookahead.current == NULL || parser->makers.current == NULL) {
		return SOL_ERROR_INVALID_ARG;
	}

	/*  Verify the rule set.    */
	int status = verifyParserRules(parserDesc->ruleSet, parserDesc->nr);

	/*  Initialize the k tokens for internal parsing usage. */
	parser->k = parserDesc->k;
	parser->p = 0;
	parser->tokens = (Token **)malloc(sizeof(Token *) * parser->k);

	parser->lexer = lexer;

	/*  Cache k tokens.*/
	for (unsigned int i = 0; i < parser->k; i++) {
		consumeTokens(parser);
	}

	return SOL_OK;
}

int verifyParserRules(RuleSet *ruleSet, unsigned int nRules) {
	for (int i = 0; i < nRules; i++) {
	}
	return SOL_OK;
}

static Token *TL(Parser *parser, int i) {
	parserSync(parser, i);

	return listGet(&parser->lookahead, parser->p + i - 1);
}

static int LA(Parser *parser, int i) { return getTokenType(TL(parser, i)); }

int consumeTokens(Parser *parser) {
	parser->p++;

	if (parser->p == listSize(&parser->lookahead) && !isSpeculating(parser)) {
		parser->p = 0;
		listClear(&parser->lookahead);
	}

	parserSync(parser, 1);

	return SOL_OK;
}

int parserMatch(Parser *parser, unsigned int token) {
	const Token *to = NULL; // list

	if (getTokenType(to) == token) {
		consumeTokens(parser);
	}

	return SOL_OK;
}

int parserSync(Parser *parser, unsigned int i) {
	unsigned int p = parser->p;

	const int lookahead = listSize(&parser->lookahead) - 1;
	int pSync = p + i - 1;
	if (pSync > lookahead) {
		int n = pSync - lookahead;
		fillParser(parser, n);
	}

	return SOL_OK;
}

int fillParser(Parser *parser, unsigned int n) {
	for (int i = 1; i <= n; i++) {
		const Token *token;
		if (nextToken(parser->lexer, &token) != EOF) {
			listAppend(&parser->lookahead, (const void *)&token);
		}
	}

	return SOL_OK;
}

int isSpeculating(const Parser *parser) { return listSize(&parser->makers) > 0; }

int releaseSpeculating(Parser *parser) {
	const int marker = listGet(&parser->makers, listSize(&parser->makers) - 1);
	listRemoveAt(&parser->makers, marker);
	parserSeek(parser, marker);

	return SOL_OK;
}

void parserSeek(Parser *parser, int index) { parser->p = index; }

int parserRuleExecute(Parser *parser, RuleSet *ruleSet) {}
