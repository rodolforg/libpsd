#ifndef __PSD_SYSTEM_H__
#define __PSD_SYSTEM_H__

#include <assert.h>
#include "psd_types.h"

#ifdef __cplusplus
extern "C" {
#endif


#if 1
#define psd_assert(x)			assert(x)
#else
#define psd_assert(x)			do {} while(0)
// or
// #define psd_assert(x)		return psd_status_unkown_error
#endif


void * psd_malloc(uint64_t size);
void * psd_realloc(void * block, size_t size);
void psd_free(void * block);
void psd_freeif(void * block);
void psd_open_file(psd_char * file_name, psd_file_stream * stream);
int64_t psd_fsize(psd_file_stream * stream);
size_t psd_fread(psd_uchar * buffer, size_t count, psd_file_stream * stream);
int psd_fseek(int64_t length, psd_file_stream * stream);
void psd_fclose(psd_file_stream * stream);


#ifdef __cplusplus
}
#endif

#endif
