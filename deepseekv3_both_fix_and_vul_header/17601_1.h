#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint8_t UINT8;

typedef struct _wStream {
    size_t length;
    size_t position;
    BYTE* buffer;
} wStream;

typedef struct {
    UINT16 cacheEntry;
    UINT8 cacheId;
    UINT8 bpp;
    UINT16 width;
    UINT16 height;
    UINT16 cbColorTable;
    UINT16 cbBitsMask;
    UINT16 cbBitsColor;
    BYTE* bitsMask;
    BYTE* colorTable;
    BYTE* bitsColor;
} ICON_INFO;

static size_t Stream_GetRemainingLength(wStream* s) {
    return s->length - s->position;
}

static void Stream_Read_UINT16(wStream* s, UINT16* val) {
    *val = (s->buffer[s->position] << 8) | s->buffer[s->position + 1];
    s->position += 2;
}

static void Stream_Read_UINT8(wStream* s, UINT8* val) {
    *val = s->buffer[s->position++];
}

static void Stream_Read(wStream* s, void* dst, size_t size) {
    memcpy(dst, s->buffer + s->position, size);
    s->position += size;
}

#define TAG ""
#define WLog_ERR(tag, format, ...) fprintf(stderr, format, __VA_ARGS__)