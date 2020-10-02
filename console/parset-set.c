#include"parser-set.h"
#include<stdlib.h>

RuleSet rule_set[] = {
		{
				0,
				NULL,
				"stat"
		}
};
unsigned int nParserRules = sizeof(rule_set) / sizeof(rule_set[0]);

int createSolverParser(Parser **parser, Lexer *lexer) {

	if (!allocateParser(parser)) {

	}

	ParserDesc parserDesc = {
			.ruleSet = rule_set,
			.nr = nParserRules,
			.k = 8,
	};

	if (createParser(parser, lexer, &parserDesc)){

	}
}

int releaseSolverParser(Parser *parser) {
	deallocteParser(parser);
}