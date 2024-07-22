#include "lexer.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

int allocateLexer(Lexer **lexer) {
	*lexer = (Lexer *)malloc(sizeof(Lexer));
	if (!*lexer) {
		return 0;
	}

	return 1;
}

int deallocteLexer(Lexer *lexer) { free(lexer); }

int initLexer(Lexer *lexer) { lexer->io = NULL; }

int createLexer(Lexer *lexer, const LexerDesc *desc) {
	int status;

	if (lexer == NULL) {
		return 0;
	}
	if (desc == NULL) {
		return 0;
	}

	initLexer(lexer);

	/*  Verify the token list.  */
	status = verifiyTokenList(desc->tokens, desc->nrTokens);
	if (!status) {
		return status;
	}
	status = verifiyTokenList(desc->comments, desc->nrCommentTokens);
	if (!status) {
		return status;
	}
	status = verifiyTokenList(desc->ignoreToken, desc->nrIgnoreTokens);
	if (!status) {
		return status;
	}

	/*  Assign token list.  */
	lexer->tokens = desc->tokens;
	lexer->nrIgnoreTokens = desc->nrTokens;

	/*  Assign comment token list.  */
	lexer->comments = desc->comments;
	lexer->nrCommentTokens = desc->nrCommentTokens;

	/*  Assign ignore token list.  */
	lexer->ignoreToken = desc->ignoreToken;
	lexer->nrIgnoreTokens = desc->nrTokens;
	return 0;
}

int lexerSetIO(Lexer *lexer, IO *io) {
	verifiyLexerIO(io);
	lexer->io = io;
	return 1;
}

int verifiyLexerIO(IO *io) {
	if (io->tell && io->read && io->seek) {
		return 1;
	}
	return 0;
}

int isLexerEof(const Lexer *lexer) {
	/*  End of line*/
	return lexer->io->eof(lexer->io);
}

int verifiyTokenList(const Token *tokens, int nrTokens) {
	int i;

	assert(tokens != NULL && nrTokens > 0);

	/*  Iterate each token and validate.    .    */
	for (i = 0; i < nrTokens; i++) {
		const Token *tok = &tokens[i];
		if (tok->text == NULL) {
			return i;
		}
	}

	return 1;
}

int consume(Lexer *lexer, int nchar) {

	IO *io = lexer->io;
	/*  */
	return io->seek(io, nchar, IO_SEEK_CUR);
}

long int nextToken(Lexer *lexer, const Token **token) {

	IO *io = lexer->io;
	char buf[512];

	/*  Check if no data to be tokenized.   */
	if (isLexerEof(lexer)) {
		return EOF;
	}

	/*  Check if white space and other character to ignore in till nothing is found.*/
	int found;

	/*  Check for comments. */
	for (int i = 0; i < lexer->nrCommentTokens; i++) {

		const Token *tok = &lexer->comments[i];
		const char *text = tok->text;
		io->peak(io, tok->len, buf);

		if (strncmp(text, buf, tok->len) == 0) {

			if (tok->proc) {
				tok->proc(lexer, tok);
			} else {
				consume(lexer, tok->len);
			}
		}
	}

	do {
		found = 0;
		for (int j = 0; j < lexer->nrIgnoreTokens; j++) {

			const Token *ignoreTok = &lexer->ignoreToken[j];
			const char *text = ignoreTok->text;
			io->peak(io, ignoreTok->len, buf);
			if (strncmp(text, buf, ignoreTok->len) == 0) {
				consume(lexer, ignoreTok->len);
				found = 1;
				break;
			}
		}
	} while (found);

	/*  End of line*/
	if (isLexerEof(lexer)) {
		return EOF;
	}

	for (int i = 0; i < lexer->nrToken; i++) {
		const Token *curTok = &lexer->tokens[i];
		const char *text = curTok->text;
		if (io->peak(io, curTok->len, buf) > 0) {
			if (strncmp(text, buf, curTok->len) == 0) {
				*token = curTok;
				return consume(lexer, curTok->len);
			}
		} else {
			return EOF;
		}
	}

	/*  Determine if a name object.    */
	// lexer->nameToken(lexer, &lexer->name);
	int nameLen = 0;
	char c;
	do {
		io->read(io, 1, &buf[nameLen]);
		c = buf[nameLen];
		nameLen++;
	} while (isalpha(c) || isdigit(c));
	buf[nameLen - 1] = '\0';
	nameLen--;
	io->seek(io, -1, IO_SEEK_CUR);

	if (nameLen > 0) {
		lexer->name.text = buf;
		lexer->name.len = nameLen;
		lexer->name.type = 0; // TOOD add name
		lexer->name.name = "name";
		*token = &lexer->name;
		return io->tell(io);
	}
	return EOF; /*  Error.  */
}

int lexerDebugPrint(Lexer *lexer) {
	
	const Token *token;
	IO *io = lexer->io;
	long int prevSeek = io->tell(io);

	while (nextToken(lexer, &token) != EOF) {
		const char *text, *name;
		getTokenText(token, &text);
		getTokenName(token, &name);
		int tok = getTokenType(token);
		printf("token %d, symbol %s  len %d, desc-name: %s \n", tok, text, token->len, name);
	}

	io->seek(io, prevSeek, IO_SEEK_SET);
}
