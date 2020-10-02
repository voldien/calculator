#include<gtest/gtest.h>
#include <core/io/io.h>
#include <tokens.h>
#include <lexer.h>
#include "../../../console/lexer-set.h" //TODO resolve path.

class LexerTest : public testing::Test {
protected:
	void SetUp() override {

	}
};

TEST_F(LexerTest, TokenString) {

	static const int tokenExpectedList[] = {
			NAME,
			LPARE,
			NAME,
			EXP,
			NAME,
			MULTI,
			NAME,
			EXP,
			NAME,
			COMMA,
			NAME,
			RPARE,
			SUBTR,
			NAME,
			LPARE,
			NAME,
			EXP,
			LPARE,
			NAME,
			ADDIT,
			NAME,
			RPARE,
			ADDIT,
			NAME,
			RPARE,
			TERMIN,
			NAME,
			LPARE,
			NAME,
			RPARE,
			ASSIGN,
			NAME,
			EXP,
			NAME,
			TERMIN
	};

	Lexer lexer;
	IO ios;
	openString("integ( x^2 * e^2, dx) - deriv(x^(2 + x) + 1); f(x) = x^2;", &ios);
	createLexer(&lexer, NULL);
	lexerSetIO(&lexer, &ios);

	const Token *token;
	IO *io = lexer.io;
	long int prevSeek = io->tell(io);

	unsigned int i = 0;
	while (nextToken(&lexer, &token) != EOF) {
		SCOPED_TRACE(i);
		const char *text, *name;
		getTokenText(token, &text);
		getTokenName(token, &name);
		int tok = getTokenType(token);
		//ASSERT_STREQ(name, )
		ASSERT_EQ(tokenExpectedList[i], tok);
		i++;
	}
	ASSERT_EQ(io->seek(io, prevSeek, IO_SEEK_SET), 0);
	ASSERT_EQ(io->tell(io), 0);
	releaseIO(io);

	openString("/*[Hello * World]*/", &ios);
	lexerSetIO(&lexer, &ios);
}

TEST_F(LexerTest, TokenFile) {

}