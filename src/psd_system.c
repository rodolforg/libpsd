// created: 2007-01-27
#include <stdio.h>
#include <stdlib.h>
#include "libpsd.h"
#include "psd_system.h"


static size_t f_read(void* dst, size_t count, void* data);
static int f_seek(int64_t offset, int origin, void* data);
static int64_t f_get_size(void* data);
static void f_close(void* data);


void * psd_malloc(uint64_t size)
{
	if ((size_t)size != size) return NULL;
	return malloc((size_t)size);
}

void * psd_realloc(void * block, size_t size)
{
	return realloc(block, size);
}

void psd_free(void * block)
{
	free(block);
}

void psd_freeif(void * block)
{
	if (block != NULL)
		psd_free(block);
}

void psd_open_file(psd_char * file_name, psd_file_stream * stream)
{
	stream->data = fopen(file_name, "rb");
	if (stream->data == NULL)
		return;

	stream->read = &f_read;
	stream->seek = &f_seek;
	stream->close = &f_close;
}

int64_t psd_fsize(psd_file_stream * stream)
{
	return stream->get_size(stream->data);
}

size_t psd_fread(psd_uchar * buffer, size_t count, psd_file_stream * stream)
{
	return stream->read(buffer, count, stream->data);
}

int psd_fseek(int64_t offset, psd_file_stream * stream)
{
	return stream->seek(offset, SEEK_CUR, stream->data);
}

void psd_fclose(psd_file_stream * stream)
{
	stream->close(stream->data);
}


static size_t f_read(void* dst, size_t count, void* data)
{
	return fread(dst, 1, count, (FILE*)data);
}

static int f_seek(int64_t offset, int origin, void* data)
{
#if defined(_WIN32)
	return _fseeki64((FILE*)data, offset, origin);
#elif defined(__linux__)
	return fseeko((FILE*)data, offset, origin);
#else
	return fseek((FILE*)data, offset, origin);
#endif
}

static int64_t f_get_size(void* data)
{
	int64_t offset, size;
#if defined(_WIN32)
	offset = _ftelli64((FILE*)data);
#elif defined(__linux__)
	offset = ftello((FILE*)data);
#else
	offset = ftell((FILE*)data);
#endif
	size = f_seek(0, SEEK_END, data);
	f_seek(offset, SEEK_SET, data);
	return size;
}

static void f_close(void* data)
{
	fclose((FILE*)data);
}
