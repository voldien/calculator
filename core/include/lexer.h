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
#ifndef _LEXER_H_
#define _LEXER_H_ 1
#include "core/io/io.h"
#include "tokens.h"

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/*TODO relocate errors!.    */
#define ERROR_NO_TYPE

typedef int (*nameTokenSyntex)(struct lexer *lexer, Token *token);

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
	char *buffer;

	nameTokenSyntex nameToken;
	/*  TODO add support for interfacing with IO.   */
	IO *io;
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

// TODO add functions for creating and handling the resources.

/*  Lexer Allocating and creation functions.   */
extern int allocateLexer(Lexer **lexer);
extern int deallocteLexer(Lexer *lexer);
extern int initLexer(Lexer *lexer);
extern int createLexer(Lexer *lexer, const LexerDesc *desc);

extern int lexerSetIO(Lexer *lexer, IO *io);
extern int verifiyLexerIO(IO *io);

extern int verifiyTokenList(const Token *tokens, int nrTokens);

extern int resetLexer(Lexer *lexer);
extern int isLexerEof(const Lexer *lexer);

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
extern int lexerDebugPrint(Lexer *lexer);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif