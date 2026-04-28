#include <string.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1

#define EXIFERR_CC
#define E_WARNING 0
#define E_NOTICE 0
#define EXIF_DEBUG

#define M_SOF0  0xC0
#define M_SOF1  0xC1
#define M_SOF2  0xC2
#define M_SOF3  0xC3
#define M_SOF5  0xC5
#define M_SOF6  0xC6
#define M_SOF7  0xC7
#define M_SOF9  0xC9
#define M_SOF10 0xCA
#define M_SOF11 0xCB
#define M_SOF13 0xCD
#define M_SOF14 0xCE
#define M_SOF15 0xCF
#define M_SOS   0xDA
#define M_EOI   0xD9

typedef unsigned char uchar;

typedef struct {
    int width;
    int height;
    void *data;
    size_t size;
} thumbnail_type;

typedef struct {
    int width;
    int height;
} jpeg_sof_info;

typedef struct {
    thumbnail_type Thumbnail;
} image_info_type;

void exif_error_docref(const char *docref, image_info_type *ImageInfo, int level, const char *format, ...);
void exif_process_SOFn(uchar *data, int marker, jpeg_sof_info *sof_info);
const char *exif_get_markername(int marker);
unsigned short php_jpg_get16(unsigned char *buf);