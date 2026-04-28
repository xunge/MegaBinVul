#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdint.h>

typedef unsigned short ushort;

typedef struct {
    int type;
    int height;
    int width;
    int colors;
    int bits;
    size_t data_size;
    unsigned char data[1];
} libraw_processed_image_t;

struct tiff_hdr {
    uint16_t tiff_magic;
    uint16_t tiff_ver;
    uint32_t tiff_ifd;
    uint16_t pad1;
    uint16_t pad2;
    uint16_t pad3;
    uint16_t pad4;
    uint16_t pad5;
    uint16_t pad6;
    uint16_t pad7;
    uint16_t pad8;
    uint16_t pad9;
    uint16_t pad10;
    uint16_t pad11;
    uint16_t pad12;
    uint16_t pad13;
    uint16_t pad14;
    uint16_t pad15;
    uint16_t pad16;
};

void tiff_head(struct tiff_hdr *th, int);

#define LIBRAW_NO_THUMBNAIL 1
#define LIBRAW_OUT_OF_ORDER_CALL 2
#define LIBRAW_UNSUPPORTED_THUMBNAIL 3
#define LIBRAW_IMAGE_BITMAP 4
#define LIBRAW_IMAGE_JPEG 5
#define LIBRAW_THUMBNAIL_BITMAP 6
#define LIBRAW_THUMBNAIL_JPEG 7
#define LIBRAW_TOO_BIG 8
#define LIBRAW_MAX_THUMBNAIL_MB 128

struct {
    const char *thumb;
    int tformat;
    int theight;
    int twidth;
    size_t tlength;
} T;

struct {
    struct {
        size_t tlength;
    } thumbnail;
} imgdata;

struct {
    int toffset;
} ID;

typedef int (*load_raw_func)(void*);
load_raw_func load_raw;

struct LibRaw {
    static int broadcom_load_raw(void*);
    libraw_processed_image_t* dcraw_make_mem_thumb(int*);
};

#define INT64(x) ((int64_t)(x))