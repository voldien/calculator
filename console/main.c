#include<stdio.h>
#include"solve.h"
#include"lexer-set.h"
#include<getopt.h>
#include <lexer.h>
#include <parser.h>
#include <ir.h>
#include <locale.h>     /* struct lconv, setlocale, localeconv */
#include<string.h>

void parseArguments(int argc, char **argv) {

	const char *shortopt = "vVdqhD:wSp:r:P:dD:Isar:g:C:f:A:t:vF:cRH:E:nNC:G:p:UP:~_";
	const char *shortoptReduced = "vVDq";
	int c;
	static struct option longoption[] = {
			/*  First pass options. */
			{"version",         no_argument,        NULL, 'v'}, /*	Print out version.	*/
			{"verbose",         no_argument,        NULL, 'V'}, /*	Enable verbose.	*/
			{"debug",           no_argument,        NULL, 'D'}, /*	Enable debug.	*/
			{"quite",           no_argument,        NULL, 'q'}, /*	Enable debug.	*/

			{"",                required_argument,  NULL, 'o'}, /*	Output.	*/
			{"",                required_argument,  NULL, 'O'}, /*	Optimization.	*/

			{"ipv4",            no_argument,        NULL, '6'}, /*	Use IPv4.	*/
			{"ipv6",            no_argument,        NULL, '4'}, /*	Use IPv6 mode.	*/
			{"syslog",          no_argument,        NULL, 'y'}, /*	Syslog.	*/
			{"udp",             no_argument,        NULL, 'U'}, /*	UDP protocol for transfer. TCP will be used for exchanging keys.	*/
			{"tcp",             no_argument,        NULL, 'T'}, /*	TCP protocol for transfer.	*/
			{"payload",         required_argument,  NULL, 'm'}, /*	payload.	*/
			{"frequency",       required_argument,  NULL, 'F'}, /*	frequency.	*/
			{"delta",           required_argument,  NULL, 'd'}, /*	Delta type.	*/
			{"duration",        required_argument,  NULL, 'r'}, /*	Duration.	*/
			{"duplex",          required_argument,  NULL, 'M'}, /*	Duplex.	*/
			{"compression",     optional_argument,  NULL, 'C'}, /*	Use compression.	*/
			{"secure",          optional_argument,  NULL, 'S'}, /*	Use secure connection.	*/
			{"server",          optional_argument,  NULL, 's'}, /*	Server mode.	*/
			{"hash",            required_argument,  NULL, 'H'}, /*	Use secure connection.	*/
			{"host",            required_argument,  NULL, 'h'}, /*	Host to connect too.	*/
			{"port",            required_argument,  NULL, 'p'}, /*	Port to connect via too.*/
			{"transport",       required_argument,  NULL, 't'}, /*	Transport layer.	*/
			{"listen",          required_argument,  NULL, 'l'}, /*	Number TCP listen	*/
			{"parallel",        required_argument,  NULL, 'n'}, /*	Parallel connections. (Not supported.)	*/
			{"benchmarkmode",   required_argument,  NULL, 'b'}, /*	benchmark mode.	*/
			{"cipher",          required_argument,  NULL, 'c'}, /*	Cipher mode.	*/
			{"public-key",      required_argument,  NULL, 'P'}, /*	Public cipher used for exchanging symmetric key.	*/
			{"public-nbits",    required_argument,  NULL, 'B'}, /*	Number of bits used for public cipher.	*/
			{"file",            required_argument,  NULL, 'f'}, /*	File to be transfered.	*/
			{"affinity",        required_argument,  NULL, 'A'}, /*	Affinity mapping, -A, --affinity n/n,m 	*/
			{"certificate",     required_argument,  NULL, 'X'}, /*	Certificate.	*/
			{"private-key",     required_argument,  NULL, 'x'}, /*	Private key.	*/
			{"dh",              optional_argument,  NULL, 'i'}, /*	Diffie hellman parameter.	*/

			{NULL,      NULL,        NULL, NULL}
	};

	while ((c = getopt_long(argc, (char *const *) argv, shortoptReduced, longoption,
	                        NULL)) != EOF) {
		switch (c) {
			case 'v':
				printf("version %s\n", get_version());
				exit(EXIT_SUCCESS);
			case 'V':   /*  Increase verbosity.   */
				break;
			case 'd':   /*  Highest verbosity.  */
				break;
			case 'q':   /*  Lowest verbosity.   */
				break;
			default:    /*  Option not a member of the first pass.*/
				break;
		}
	}

	/*	Default options.	*/
	//snt_default_con_option(option, g_server);

	/*	Reset getopt.	*/
	opterr = 0;
	optind = 0;
	optopt = 0;
	optarg = NULL;

	while ((c = getopt_long(argc, (char *const *) argv, shortoptReduced, longoption,
	                        NULL)) != EOF) {
		switch (c) {
			case 'h':
				break;
			case 'i':
				break;
			case 'e':
				break;
			case 'a':
				break;
			default:
				break;
		}

	}

	/*	Reset getopt.	*/
	opterr = 0;
	optind = 0;
	optopt = 0;
	optarg = NULL;
}

int main(int argc, char **argv) {

	parseArguments(argc, argv);
	long value;

	/*  Create lexer.   */
	Lexer* lexer;
	Token* token;
	Node root;

	//TODO deal with the locale.
	const char* locale = setlocale(LC_ALL, "");
	int t = MB_CUR_MAX;

	//setlocale (LC_COLLATE,"");
	struct lconv * lc = localeconv ();

	if(!allocateLexer(&lexer))
		return EXIT_FAILURE;
	LexerDesc lexerDesc = {
			.tokens = tokens,
			.nrTokens = ntokens,
			.comments = commentToken,
			.nrCommentTokens = nCommentTokens,
			.ignoreToken = ignoreTokens,
			.nrIgnoreTokens = nIgnoreTokens,
	};

	createLexer(&lexer, &lexerDesc);
	IO io, ios;
	openFile("samples/algebra.ms", &io);

	lexerSetIO(lexer, &io);

	openString("integ( x^2 * e^2, dx) - deriv(x^(2 + x) + 1); f(x) = x^2; //  \n /* \n \n \t */ \n // Compute something \n integ(x^2, dx); fy(x) = {x^2 where x > 10, x^0.5 where 0 < x <= 10};", &ios);
	lexerSetIO(lexer, &ios);
	lexerDebugPrint(lexer);

	/*  Parser. */
	Parser parser;
	createParser(&parser, lexer, NULL);

	/*  IR. */
	IRRoot irnode;
	createIR(&irnode, &parser, &root);

	/*  */
	//buildIR(&irnode);

	/*  Semantic analysis.  */

	deallocteLexer(lexer);

	/*  Main code.  */
	createSolverLexer(&lexer, &io);
	createSolverParser(parser, lexer);

	releaseSolverParser(parser);
	releaseSolverLexer(lexer);

	//TODO move the logic to the solve function and other functions.
	solve("x = { x | x <- [0..1]}; ");

	return EXIT_SUCCESS;
}
