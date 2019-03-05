#ifndef __PSD_TYPES_H__
#define __PSD_TYPES_H__

#include <stddef.h>
#include <stdint.h>


typedef unsigned char			psd_bool;
#define psd_true				1
#define psd_false				0


typedef char					psd_char;
typedef unsigned char			psd_uchar;
typedef int16_t					psd_short;
typedef uint16_t				psd_ushort;
typedef int32_t					psd_int;
typedef uint32_t				psd_uint;
typedef float					psd_float;
typedef double					psd_double;


typedef unsigned char			psd_color_component;
typedef uint32_t				psd_argb_color;


#endif
