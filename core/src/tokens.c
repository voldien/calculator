#include "tokens.h"

int getTokenText(const Token *token, const char **text) {
	*text = token->text;
	return 0;
}

int getTokenType(const Token *token) { return token->type; }

int getTokenName(const Token *token, const char **name) {
	*name = token->name;
	return 0;
}
