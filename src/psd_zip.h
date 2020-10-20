#ifndef __PSD_ZIP_H__
#define __PSD_ZIP_H__

#include "libpsd.h"
#include "psd_config.h"
#include "psd_types.h"

#ifdef PSD_INCLUDE_ZLIB

#ifdef __cplusplus
extern "C" {
#endif

psd_status psd_unzip_without_prediction(psd_uchar *src_buf, size_t src_len,
	psd_uchar *dst_buf, size_t dst_len);
psd_status psd_unzip_with_prediction(psd_uchar *src_buf, size_t src_len,
	psd_uchar *dst_buf, size_t dst_len,
	psd_int row_size, psd_int color_depth);

#ifdef __cplusplus
}
#endif

#endif // PSD_INCLUDE_ZLIB

#endif // __PSD_ZIP_H__
