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
#include <cstdio>
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
		"d,debug", "Debug Mode.", cxxopts::value<bool>()->default_value("true"))(
		"f,file", "File Path.", cxxopts::value<std::string>())("i,interactive", "Interactive Mode.",
															   cxxopts::value<bool>()->default_value("false"))(
		"V,verbose", "Verbose Mode.", cxxopts::value<bool>()->default_value("false"));

	const cxxopts::ParseResult result = options.parse(argc, argv);

	if (result.count("help") > 0) {
		return EXIT_SUCCESS;
	}

	const bool debug = result["debug"].as<bool>();
	const bool interactive = result["interactive"].as<bool>();
	std::string filePath = "samples/algebra.ms";

	// Check pipe,
	//
	// TODO deal with the locale.
	const char *locale = setlocale(LC_ALL, "");
	int t = MB_CUR_MAX;

	// setlocale (LC_COLLATE,"");
	struct lconv *lc = localeconv();

	Token *token;
	Node root;

	/*  Create lexer.   */
	Lexer *lexer;
	Parser *parser;

	IO ioData;

	openString("integ( x^2 * e^2, dx) - deriv(x^(2 + x) + 1); f(x) = x^2; //  \n /* \n \n \t */ \n // Compute "
			   "something \n integ(x^2, dx); fy(x) = {x^2 where x > 10, x^0.5 where 0 < x <= 10};",
			   &ioData);

	if (openFile("samples/algebra.ms", &ioData)) {
	}

	if (interactive) {
		if (openMem(4096, &ioData) != 0) {
			std::cerr << "Failed  to allocate interactive buffer" << std::endl;
			goto error;
		}
	} else {
	}

	if (createMathSolverLexer(&lexer, &ioData) != 0) {
		std::cerr << "Failed to Init" << std::endl;
		goto error;
	}

	if (debug) {
		lexerDebugPrint(lexer);
	}

	/*  Parser. */
	if (createSolverParser(&parser, lexer) != 0) {
		std::cerr << "Failed to Init" << std::endl;
		goto error;
	}

	if (interactive) {

		bool interactive_active = true;
		while (interactive_active) {
			const char *terminate = "\0";

			for (std::string input_string; std::getline(std::cin, input_string);) {
				
				if (input_string.find("exit") != std::string::npos) {
					interactive_active = false;
				} else if (input_string.length() > 0) {

					/*	Reset buffer, write string.	*/
					ioData.seek(&ioData, 0, SEEK_SET);
					ioData.write(&ioData, input_string.length(), input_string.c_str());
					ioData.write(&ioData, 1, terminate);

					/*	Parse data.	*/
					if (debug) {
						lexerDebugPrint(lexer);
					}
				}
			}
		}
	} else {
		/*	Read directly from IO file and parse.	*/
	}

	/*  IR. */
	IRRoot irnode;
	createIR(&irnode, parser, &root);

	/*  */
	// buildIR(&irnode);

	/*  Semantic analysis.  */

	releaseSolverParser(parser);
	releaseSolverLexer(lexer);

	// TODO move the logic to the solve function and other functions.
	solve("x = { x | x <- [0..1]}; ");

error:

	return EXIT_SUCCESS;
}
