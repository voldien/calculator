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
#ifndef _TOKENS_H_
#define _TOKENS_H_ 1
#include <stdlib.h>

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

// Forward declaration.
struct lexer_t;
struct token_t;

typedef int (*token_process)(struct lexer_t *lexer, struct token_t *token);

/**
 *
 */
typedef struct token_t {
	const char *text; /*	Text associated with token - like for variable tokens.  */ // TODO add cstring.
	int type;																		   /*	Unique token type.  */
	int len;																		   /*	Length. */
	const char *name;																   /*	Name of the token type.  */
	token_process proc; /*	Custom token_process function.    */
} Token;

extern int copyToken(const Token *source_token, Token *dest_token);

/**
 * @brief Get the Token Type object
 * 
 * @param token 
 * @return int 
 */
extern int getTokenType(const Token *token);

/**
 * @brief Get the Token Name object
 * 
 * @param token 
 * @param name 
 * @return int 
 */
extern int getTokenName(const Token *token, const char **name);

/**
 * @brief Get the Token Text object
 * 
 * @param token 
 * @param text 
 * @return int 
 */
extern int getTokenText(const Token *token, const char **text);

/**
 * @brief Get the Token Proc object
 * 
 * @param token 
 * @return token_process 
 */
extern token_process getTokenProc(const Token *token);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif