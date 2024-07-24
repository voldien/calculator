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
#ifndef _IO_H_
#define _IO_H_ 1
#include <stddef.h>

#ifdef __cplusplus /*	C++ Environment	*/
extern "C" {
#endif

/**
 * Seek modes.
 */
#define IO_SEEK_CUR 0
#define IO_SEEK_SET 1
#define IO_SEEK_END 2

/**
 *	IO callback functions.
 */
struct io_t;
typedef long int (*IO_open)(struct io_t *io, const char *path);
typedef long int (*IO_close)(struct io_t *io);
typedef long int (*IO_read)(struct io_t *io, long int nbytes, void *pbuf);
typedef long int (*IO_write)(struct io_t *io, long int nbytes, const void *pbuf);
typedef long int (*IO_seek)(struct io_t *io, long int nbytes, const long int ref);
typedef long int (*IO_tell)(struct io_t *io);
typedef long int (*IO_peak)(struct io_t *io, long int nbytes, void *pbuf);
typedef long int (*IO_eof)(struct io_t *io);

/**
 *	IO callback functions.
 */
typedef struct io_t {
	IO_open open;	/**/
	IO_close close; /**/
	IO_read read;	/**/
	IO_write write; /**/
	IO_seek seek;	/**/
	IO_tell tell;	/**/
	IO_peak peak;	/**/
	IO_eof eof;		/**/
	/*  Internal object.    */
	void *_data; /**/
} IO;

extern int openFile(const char *path, IO *io);
extern int openString(const char *text, IO *io);
extern int openMem(size_t nBytes, IO *io);
extern void releaseIO(IO *io);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif