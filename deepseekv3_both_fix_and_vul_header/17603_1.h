#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct _wStream {
    size_t length;
    size_t position;
    uint8_t* buffer;
} wStream;

typedef struct _rdpUpdate rdpUpdate;

#define WINPR_UNUSED(x) (void)(x)

#define BITMAP_COMPRESSION 0x0001
#define NO_BITMAP_COMPRESSION_HDR 0x0400

typedef struct {
    uint16_t destLeft;
    uint16_t destTop;
    uint16_t destRight;
    uint16_t destBottom;
    uint16_t width;
    uint16_t height;
    uint16_t bitsPerPixel;
    uint16_t flags;
    uint16_t bitmapLength;
    uint16_t cbCompFirstRowSize;
    uint16_t cbCompMainBodySize;
    uint16_t cbScanWidth;
    uint16_t cbUncompressedSize;
    BOOL compressed;
    uint8_t* bitmapDataStream;
} BITMAP_DATA;

static size_t Stream_GetRemainingLength(wStream* s) {
    return s->length - s->position;
}

static void Stream_Read_UINT16(wStream* s, uint16_t* value) {
    *value = (s->buffer[s->position] << 8) | s->buffer[s->position + 1];
    s->position += 2;
}

static uint8_t* Stream_Pointer(wStream* s) {
    return &s->buffer[s->position];
}

static void Stream_Seek(wStream* s, size_t offset) {
    s->position += offset;
}