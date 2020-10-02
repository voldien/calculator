#ifndef _LEXER_H_
#define _LEXER_H_ 1
#include"core/io/io.h"
#include "tokens.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/*TODO relocate errors!.    */
#define ERROR_NO_TYPE

typedef int (*nameTokenSyntex)(struct lexer* lexer, Token* token);

typedef struct lexer {

	/*  TODO add vector object. */
	const Token *tokens;
	const Token *comments;
	const Token *ignoreToken;
	Token name;
	int nrIgnoreTokens;
	int nrCommentTokens;
	int nrToken;

	/*	Buffers*/
	char* buffer;

	nameTokenSyntex nameToken;
	/*  TODO add support for interfacing with IO.   */
	IO* io;
} Lexer;

// TODO add support for costume lexer rules.
typedef struct lexer_desc_t {
	const Token *tokens;
	int nrTokens;
	const Token *comments;
	int nrCommentTokens;
	const Token *ignoreToken;
	int nrIgnoreTokens;

} LexerDesc;

//TODO add functions for creating and handling the resources.
extern int allocateLexer(Lexer** lexer);
extern int deallocteLexer(Lexer* lexer);
extern int initLexer(Lexer* lexer);

extern int createLexer(Lexer *lexer, const LexerDesc *desc);

extern int lexerSetIO(Lexer* lexer, IO* io);
extern int verifiyLexerIO(IO* io);

extern int verifiyTokenList(const Token *tokens, int nrTokens);

extern int resetLexer(Lexer* lexer);
extern int isLexerEof(const Lexer* lexer);

extern int consume(Lexer *lexer, int nchar);
extern int extractName(Lexer *lexer, const char *name);

/**
 * Get the next token.
 * @param lexer
 * @param token
 * @return the index in the text stream.
 */
extern long int nextToken(Lexer *lexer, const Token **token);

extern long int LexerGetError(void);

/**
 * Debug print the current lexer
 * objec to stdout.
 * @param lexer
 * @return
 */
extern int lexerDebugPrint(Lexer* lexer);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif