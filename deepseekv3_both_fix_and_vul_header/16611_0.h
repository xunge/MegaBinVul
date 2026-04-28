#include <string.h>

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

typedef struct {
    int height;
    int width;
} jpeg_sof_info;

typedef struct {
    void *data;
    size_t size;
    int width;
    int height;
} thumbnail_type;

typedef struct {
    thumbnail_type Thumbnail;
} image_info_type;

void raise_warning(const char *message);
unsigned short php_jpg_get16(const unsigned char *data);
void exif_process_SOFn(const unsigned char *data, int marker, jpeg_sof_info *info);