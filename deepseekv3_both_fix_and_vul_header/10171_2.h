#include <stdint.h>

typedef struct TIFF {
    void* tif_data;
    void* tif_clientdata;
} TIFF;

typedef struct OJPEGState {
    int decoder_ok;
    int libjpeg_jpeg_query_style;
} OJPEGState;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef int32_t tmsize_t;

extern void TIFFErrorExt(void*, const char*, const char*);
extern int OJPEGDecodeRaw(TIFF*, uint8*, tmsize_t);
extern int OJPEGDecodeScanlines(TIFF*, uint8*, tmsize_t);