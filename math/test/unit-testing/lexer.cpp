#include <core/io/io.h>
#include <gtest/gtest.h>
#include <lexer-set.h>
#include <lexer.h>
#include <tokens.h>

class LexerTest : public testing::Test {
  protected:
	void SetUp() override {}

	constexpr static const int tokenExpectedList[] = {NAME,	 LPARE, NAME,  EXP,	   NAME,  MULTI, NAME,	EXP,	NAME,
													  COMMA, NAME,	RPARE, SUBTR,  NAME,  LPARE, NAME,	EXP,	LPARE,
													  NAME,	 ADDIT, NAME,  RPARE,  ADDIT, NAME,	 RPARE, TERMIN, NAME,
													  LPARE, NAME,	RPARE, ASSIGN, NAME,  EXP,	 NAME,	TERMIN};
};

TEST_F(LexerTest, TokenSequence) {

	Lexer* lexer;
	IO ios;

	ASSERT_EQ(openString("integ( x^2 * e^2, dx) - deriv(x^(2 + x) + 1); f(x) = x^2;", &ios), 0);

	ASSERT_EQ(createMathSolverLexer(&lexer, &ios), 0);

	const Token *token;
	IO *io = lexer->io;
	long int prevSeek = io->tell(io);

	unsigned int token_index = 0;

	while (nextToken(lexer, &token) != EOF) {
		SCOPED_TRACE(token_index);
		const char *text, *name;

		ASSERT_EQ(getTokenText(token, &text), 0);
		ASSERT_EQ(getTokenName(token, &name), 0);

		const int tok = getTokenType(token);
		// ASSERT_STREQ(name, )
		EXPECT_EQ(tokenExpectedList[token_index], tok);

		token_index++;
	}

	ASSERT_EQ(io->seek(io, prevSeek, IO_SEEK_SET), 0);
	ASSERT_EQ(io->tell(io), 0);
	releaseIO(io);
}

TEST_F(LexerTest, TokenFile) {}