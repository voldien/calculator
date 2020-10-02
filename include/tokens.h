/**
    Copyright (C) 2019 Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _TOKENS_H_
#define _TOKENS_H_ 1
#include<stdlib.h>

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
	const char *text;       /*	Text associated with token - like for variable tokens.  */  //TODO add cstring.
	int type;               /*	Unique token type.  */
	int len;                /*	Length. */
	const char *name;       /*	Name of the token type.  */
	token_process proc;     /*	Custom token_process function.    */
} Token;

extern int copyToken(const Token *source_token, Token *dest_token);

extern int getTokenType(const Token *token);

extern int getTokenName(const Token *token, const char **name);

extern int getTokenText(const Token *token, const char **text);

extern token_process getTokenProc(const Token* token);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

//TODo add function for creating token list object or something.

#endif