#include "core/io/io.h"
#include <assert.h>
#include <cstring.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

static long int file_open(struct io_t *io, const char *path) {
	FILE *file;
	file = fopen(path, "rb");
	io->_data = file;
	if (!io->_data) {
		return 0;
	}
}

static long int file_close(struct io_t *io) {
	FILE *file = io->_data;
	fclose(file);
	io->_data = NULL;
}

static long int file_read(struct io_t *io, long int nbytes, void *pbuf) {
	FILE *file = io->_data;
	long int nread = fread(pbuf, 1, nbytes, file);
	return nread;
}

static long int file_write(struct io_t *io, long int nbytes, const void *pbuf) {
	FILE *file = io->_data;
	long int nwrite = fwrite(pbuf, 1, nbytes, file);
	return nwrite;
}

static long int file_seek(struct io_t *io, long int nbytes, const long int ref) {
	FILE *file = io->_data;
	long int mode;
	switch (ref) {
	case IO_SEEK_CUR:
		mode = SEEK_CUR;
		break;
	case IO_SEEK_END:
		mode = SEEK_END;
		break;
	case IO_SEEK_SET:
		mode = SEEK_SET;
		break;
	default:
		assert(0);
	}
	if (fseek(file, nbytes, mode) == 0) {
		return io->tell(io);
	}
	return -1;
}

static long int file_tell(struct io_t *io) {
	FILE *file = io->_data;
	long int pos = ftell(file);
	return pos;
}

long int file_peak(struct io_t *io, long int nbytes, void *pbuf) {
	FILE *file = io->_data;
	long int pos = io->tell(io);
	long int npeek = io->read(io, nbytes, pbuf);
	io->seek(io, pos, IO_SEEK_SET);
	return npeek;
}

int file_eof(struct io_t *io) {
	FILE *file = io->_data;
	int status = feof(file);
	return status != 0;
}

int openFile(const char *path, IO *io) {

	io->open = file_open;
	io->close = file_close;
	io->read = file_read;
	io->write = file_write;
	io->seek = file_seek;
	io->tell = file_tell;
	io->peak = file_peak;
	io->eof = file_eof;

	io->open(io, path);
}

typedef struct io_internal_string {
	CString string;
	int pos;
} IOInternalString;

static long int string_open(struct io_t *io, const char *path) { return 1; }

static long int string_close(struct io_t *io) {
	IOInternalString *ios = io->_data;
	deleteString(&ios->string);
	free(io->_data);
}

static long int string_read(struct io_t *io, long int nbytes, void *pbuf) {
	IOInternalString *ios = io->_data;
	int cur = io->tell(io);
	memcpy(pbuf, &ios->string.text[cur], nbytes);
	ios->pos += nbytes;
	/*	TODO check if possible.	*/
	return nbytes;
}

static long int string_write(struct io_t *io, long int nbytes, const void *pbuf) {
	IOInternalString *ios = io->_data;
	int cur = io->tell(io);
	memcpy(&ios->string.text[cur], pbuf, nbytes);
	ios->pos += nbytes;
	return nbytes;
}

static long int string_seek(struct io_t *io, long int nbytes, const long int ref) {
	IOInternalString *ios = io->_data;
	int cur = io->tell(io);
	long int mode;
	switch (ref) {
	case IO_SEEK_CUR:
		ios->pos = cur + nbytes;
		break;
	case IO_SEEK_END:
		assert(0);
		break;
	case IO_SEEK_SET:
		ios->pos = nbytes;
		break;
	default:
		assert(0);
	}
	return ios->pos;
}

static long int string_tell(struct io_t *io) {
	IOInternalString *ios = io->_data;
	return ios->pos;
}

long int string_peak(struct io_t *io, long int nbytes, void *pbuf) {
	IOInternalString *ios = io->_data;
	int cur = io->tell(io);
	memcpy(pbuf, &ios->string.text[cur], nbytes);
}

long int string_eof(struct io_t *io) {
	IOInternalString *ios = io->_data;
	return io->tell(io) > ios->string.len;
}

int openString(const char *text, IO *io) {
	io->open = string_open;
	io->close = string_close;
	io->read = string_read;
	io->write = string_write;
	io->seek = string_seek;
	io->tell = string_tell;
	io->peak = string_peak;
	io->eof = string_eof;

	io->_data = malloc(sizeof(IOInternalString));
	IOInternalString *ios = io->_data;
	initString(&ios->string);
	setString(&ios->string, text);
}

void releaseIO(IO *io) {
	io->close(io);
	free(io->_data);
}
