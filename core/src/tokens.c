#include "tokens.h"
#include "error.h"

int copyToken(const Token *source_token, Token *dest_token) {
	// TODO: add rest
	dest_token->len = source_token->len;
	return SOL_OK;
}

int getTokenText(const Token *token, const char **text) {
	*text = token->text;
	return SOL_OK;
}

int getTokenType(const Token *token) { return token->type; }

int getTokenName(const Token *token, const char **name) {
	*name = token->name;
	return SOL_OK;
}
