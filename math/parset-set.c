#include "error.h"
#include "parser-set.h"
#include <stdlib.h>

RuleSet rule_set[] = {{0, NULL, "stat"}, {1, NULL, "include"}};
unsigned int nParserRules = sizeof(rule_set) / sizeof(rule_set[0]);

int createSolverParser(Parser **parser, Lexer *lexer) {

	if (!allocateParser(parser)) {
	}

	const ParserDesc parserDesc = {
		.ruleSet = rule_set,
		.nr = nParserRules,
		.k = 8,
	};

	if (createParser(*parser, lexer, &parserDesc)) {
	}

	return SOL_OK;
}

int releaseSolverParser(Parser *parser) { return deallocteParser(parser); }