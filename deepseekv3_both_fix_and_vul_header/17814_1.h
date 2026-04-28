#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>

#define TAG "brush"

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef bool BOOL;

#define TRUE true
#define FALSE false

typedef struct _wStream wStream;

typedef struct {
    BYTE index;
    BYTE bpp;
    BYTE cx;
    BYTE cy;
    BYTE style;
    UINT32 length;
    BYTE* data;
} CACHE_BRUSH_ORDER;

enum {
    BMF_8BPP,
    BMF_16BPP,
    BMF_32BPP
};

static const BYTE BPP_BMF[] = {
    BMF_8BPP,  /* 8bpp */
    BMF_16BPP, /* 16bpp */
    BMF_32BPP  /* 32bpp */
};

BOOL Stream_EnsureRemainingCapacity(wStream* s, size_t size);
size_t update_approximate_cache_brush_order(const CACHE_BRUSH_ORDER* cache_brush, UINT16* flags);
void Stream_Write_UINT8(wStream* s, BYTE value);
void Stream_Write(wStream* s, const void* data, size_t size);
BOOL update_compress_brush(wStream* s, const BYTE* data, BYTE bpp);
void WLog_ERR(const char* tag, const char* format, ...);