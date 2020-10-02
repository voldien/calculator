#include <lexer.h>
#include<stdio.h>
#include<stdio.h>
#include"lexer-set.h"

const Token ignoreTokens[] = {
		{" ",  WS,       1, "White space"},
		{"\n", NEWLINE,  1, "new line"},
		{"\r", RETLINE,  1, "return line"},
		{"\t", TABSPACE, 1, "tab space"},
};

const int nIgnoreTokens = sizeof(ignoreTokens) / sizeof(ignoreTokens[0]);

static int handleSingleLineComment(Lexer *lexer, const Token *token) {
	IO *io = lexer->io;
	int found;
	char buf[32];
	do {
		found = 0;
		io->peak(io, 1, buf);
		if (buf[0] == '\n')
			found = 1;
		consume(lexer, 1);
	} while (!found);

	return isLexerEof(lexer);
}

static int handleMultilineComment(Lexer *lexer, const Token *token) {
	IO *io = lexer->io;
	char buf[32];

	int found;
	const char *endComment = "*/";
	do {
		found = 0;
		io->peak(io, token->len, buf);
		if (strcmp(buf, endComment) == 0)
			found = 1;
		consume(lexer, 2);
	} while (!found);

	return isLexerEof(lexer);
}

const Token commentToken[] = {
		{"/*", SINGLE_LINE_COMMENT, 2, "Multiline comment",   handleMultilineComment},
		{"#",  SINGLE_LINE_COMMENT, 1, "Single Line comment", handleSingleLineComment},
		{"//", MULTI_LINE_COMMENT,  2, "Single Line comment", handleSingleLineComment},
};

const int nCommentTokens =  sizeof(commentToken) / sizeof(commentToken[0]);

const Token tokens[] = {
		{"(",     LPARE,   1, "left parenthesis",         NULL},
		{")",     RPARE,   1, "right parenthesis",        NULL},
		{"[",     LSQBR,   1, "left open bracket",        NULL},
		{"]",     RSQBR,   1, "right close bracket",      NULL},
		{"{",     LCURBRA, 1, "left open curl bracket",   NULL},
		{"}",     RCURBRA, 1, "right close curl bracket", NULL},
		{"..",    DOT2,    2, "2 punctuation",            NULL},
		{".",     DOT,     1, "punctuation",              NULL},
		{",",     COMMA,   1, "comma",                    NULL},
		{"+",     ADDIT,   1, "addition",                 NULL},
		{"-",     SUBTR,   1, "subtraction",              NULL},
		{"*",     MULTI,   1, "multiplication",           NULL},
		{"/",     DIVIS,   1, "division",                 NULL},
		{"^",     EXP,     1, "exponent",                 NULL},
		{"|",     GIVEN,   1, "given",                    NULL},
		{">=",    GREAEQ,  2, "greater equal",            NULL},
		{"<=",    LESSEQ,  2, "less equal",               NULL},
		{"<-", 22,         2, "",                         NULL},
		{"=",     ASSIGN,  1, "assign",                   NULL},
		{";",     TERMIN,  1, "terminate",                NULL},
		{"<",     LESS,    1, "less",                     NULL},
		{">",     GREATER, 1, "greater",                  NULL},
		{":",     SEMIC,   1, "semi colon",               NULL},
		{"!",     EXCLA,   1, "exclamation",              NULL},
		{"'",     SINQO,   1, "single quote",             NULL},
		{"in",    TERMIN,  4, "in",                       NULL},
		{"where", TERMIN,  7, "where",                    NULL},
};
const int ntokens = sizeof(tokens) / sizeof(tokens[0]);


int createSolverLexer(Lexer** lexer, IO* io){

	if(!allocateLexer(&lexer)){
		return 0;
	}

	LexerDesc lexerDesc = {
			.tokens = tokens,
			.nrTokens = ntokens,
			.comments = commentToken,
			.nrCommentTokens = nCommentTokens,
			.ignoreToken = ignoreTokens,
			.nrIgnoreTokens = nIgnoreTokens,
	};

	createLexer(&lexer, &lexerDesc);
	lexerSetIO(lexer, io);

	return 0;
}
int releaseSolverLexer(Lexer* lexer){
	deallocteLexer(lexer);
}