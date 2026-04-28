#include <stdint.h>
#include <stdbool.h>

#define INLINE inline
#define BOOL bool
#define TRUE true
#define FALSE false
#define BYTE uint8_t
#define ORDER_FIELD_01 0x01
#define ORDER_FIELD_02 0x02
#define ORDER_FIELD_03 0x04
#define ORDER_FIELD_04 0x08
#define ORDER_FIELD_05 0x10
#define CACHED_BRUSH 0x80

typedef struct _wStream {
    void* dummy;
} wStream;

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t style;
    uint8_t hatch;
    uint8_t bpp;
    uint8_t index;
    BYTE* data;
    void* p8x8;
} rdpBrush;

static const uint8_t BMF_BPP[8] = {0, 1, 8, 16, 24, 32, 0, 0};

static INLINE void Stream_Write_UINT8(wStream* s, uint8_t value) {
    (void)s;
    (void)value;
}

static INLINE uint8_t get_bmf_bpp(uint8_t style, BOOL* rc) {
    *rc = TRUE;
    return BMF_BPP[style & 0x07];
}