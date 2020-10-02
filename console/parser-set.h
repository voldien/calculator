#ifndef SOLVER_PARSER_SET_H_
#define SOLVER_PARSER_SET_H_ 1
#include<parser.h>
#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

extern RuleSet rule_set[];
extern unsigned int nParserRules;

/*  */
extern int createSolverParser(Parser** parser, Lexer* lexer);
extern int releaseSolverParser(Parser* parser);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif