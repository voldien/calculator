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
#ifndef SOLVER_LEXER_SET_H_
#define SOLVER_LEXER_SET_H_ 1
#include <core/io/io.h>
#include <lexer.h>
#include <limits.h>
#include <tokens.h>

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

// TODO add prefix.
/*  Language tokens.    */
#define LPARE 1				/*  */
#define RPARE 2				/*  */
#define COMMA 3				/*  */
#define LSQBR 4				/*  */
#define RSQBR 5				/*  */
#define ADDIT 6				/*  */
#define SUBTR 7				/*  */
#define MULTI 8				/*  */
#define DIVIS 9				/*  */
#define EXP 10				/*  */
#define GIVEN 11			/*  */
#define ASSIGN 12			/*  */
#define TERMIN 13			/*  */
#define LESS 14				/*  */
#define GREATER 15			/*  */
#define LESSEQ 16			/*  */
#define GREAEQ 17			/*  */
#define LCURBRA 18			/*  */
#define RCURBRA 19			/*  */
#define DOT 20				/*  */
#define EXCLA 21			/*  */
#define SEMIC 22			/*  */
#define SINQO 23			/*  */
#define DOT2 24				/*  */
#define INCLUDE 25			/*  */
#define STRING_QUOTATION 26 /*  */
#define CONSTANT 27			/*  */
#define NAME 0				/*  */

/*  Ignore token types.   */
#define WS INT_MAX - 0
#define NEWLINE INT_MAX - 1
#define TABSPACE INT_MAX - 2
#define RETLINE INT_MAX - 3

/*  Comment token types.    */
#define SINGLE_LINE_COMMENT -1
#define MULTI_LINE_COMMENT -1

/*  */
extern const Token ignoreTokens[];
extern const int nIgnoreTokens;
/*  */
extern const Token commentToken[];
extern const int nCommentTokens;
/*  */
extern const Token tokens[];
extern const int ntokens;

/*  Abstract high level parser creation functions.   */
extern int createMathSolverLexer(Lexer **lexer, IO *io);
extern int releaseSolverLexer(Lexer *lexer);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif