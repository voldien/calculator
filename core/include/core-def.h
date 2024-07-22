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
#ifndef SOLVER_CORE_DEF_H_
#define SOLVER_CORE_DEF_H_ 1

/**
 * Macro for adding library
 * support.
 */
#ifndef CORE_SOLVER_EXTERN
	#ifndef TASH_SCH_STATIC
		#ifdef _WIN32
			#define TASH_SCH_EXTERN __declspec(dllimport)
		#elif defined(__GNUC__) && __GNUC__ >= 4
			#define TASH_SCH_EXTERN __attribute__((visibility("default")))
		#else
			#define TASH_SCH_EXTERN
		#endif
		#else
			#define TASH_SCH_EXTERN
	#endif
#endif

#endif