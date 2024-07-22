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
#include "parser-set.h"
#include "solve.h"
#include <clocale> /* struct lconv, setlocale, localeconv */
#include <cstdlib>
#include <cxxopts.hpp>
#include <getopt.h>
#include <iostream>
#include <ir.h>
#include <lexer-set.h>
#include <lexer.h>
#include <parser.h>
#include <string>

int main(int argc, char **argv) {

	/*	Default common options between all samples.	*/
	cxxopts::Options options("Solver ", "");
	cxxopts::OptionAdder &addr = options.add_options("Solver")("h,help", "helper information.")(
		"d,debug", "Debug Mode.", cxxopts::value<bool>()->default_value("true"))("h,help", "helper information.")(
		"f,file", "File Path.", cxxopts::value<std::string>())("i,interactive", "Interactive Mode.",
															   cxxopts::value<bool>()->default_value("false"))(
		"V,verbose", "Verbose Mode.", cxxopts::value<bool>()->default_value("false"));

	const cxxopts::ParseResult result = options.parse(argc, argv);

	if (result.count("help") > 0) {
		return EXIT_SUCCESS;
	}

	std::string filePath = "samples/algebra.ms";

	// Check pipe,
	//

	long value;

	// TODO deal with the locale.
	const char *locale = setlocale(LC_ALL, "");
	int t = MB_CUR_MAX;

	// setlocale (LC_COLLATE,"");
	struct lconv *lc = localeconv();

	/*  Create lexer.   */
	Lexer *lexer;
	Token *token;
	Node root;

	if (!allocateLexer(&lexer)) {
		/*	*/
		fprintf("Failed to Allocate Lexer Object");
		return EXIT_FAILURE;
	}

	const LexerDesc lexerDesc = {
		.tokens = tokens,
		.nrTokens = ntokens,
		.comments = commentToken,
		.nrCommentTokens = nCommentTokens,
		.ignoreToken = ignoreTokens,
		.nrIgnoreTokens = nIgnoreTokens,
	};

	createLexer(lexer, &lexerDesc);
	IO io, ios;
	openFile("samples/algebra.ms", &io);

	lexerSetIO(lexer, &io);

	openString("integ( x^2 * e^2, dx) - deriv(x^(2 + x) + 1); f(x) = x^2; //  \n /* \n \n \t */ \n // Compute "
			   "something \n integ(x^2, dx); fy(x) = {x^2 where x > 10, x^0.5 where 0 < x <= 10};",
			   &ios);
	lexerSetIO(lexer, &ios);
	lexerDebugPrint(lexer);

	std::string str;
	std::getline(std::cin, str);

	/*  Parser. */
	Parser parser;
	createParser(&parser, lexer, nullptr);

	/*  IR. */
	IRRoot irnode;
	createIR(&irnode, &parser, &root);

	/*  */
	// buildIR(&irnode);

	/*  Semantic analysis.  */

	deallocteLexer(lexer);

	/*  Main code.  */
	createSolverLexer(&lexer, &io);
	// createSolverParser(parser, lexer);

	releaseSolverParser(&parser);
	releaseSolverLexer(lexer);

	// TODO move the logic to the solve function and other functions.
	solve("x = { x | x <- [0..1]}; ");

	return EXIT_SUCCESS;
}
