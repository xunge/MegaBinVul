#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define INLINE inline
#define BOOL bool
#define BYTE uint8_t
#define FALSE false
#define TRUE true
#define ORDER_FIELD_01 0x01
#define ORDER_FIELD_02 0x02
#define ORDER_FIELD_03 0x04
#define ORDER_FIELD_04 0x08
#define ORDER_FIELD_05 0x10
#define CACHED_BRUSH 0x80

typedef struct _wStream {
    size_t length;
    size_t position;
    uint8_t* buffer;
} wStream;

typedef struct _rdpBrush {
    uint8_t x;
    uint8_t y;
    uint8_t style;
    uint8_t hatch;
    uint8_t index;
    uint8_t bpp;
    uint8_t* data;
    uint8_t p8x8[8];
} rdpBrush;

static const uint8_t BMF_BPP[8] = {0, 1, 8, 15, 16, 24, 32, 0};

static INLINE size_t Stream_GetRemainingLength(wStream* s) {
    return s->length - s->position;
}

static INLINE void Stream_Read_UINT8(wStream* s, uint8_t v) {
    v = s->buffer[s->position++];
}