#include <stdint.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    int buffer_size;
    int index;
} GetByteContext;

typedef struct VmncContext {
    int bpp2;
    int bigendian;
    void *avctx;
} VmncContext;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)
#define HT_RAW (1 << 0)
#define HT_BKG (1 << 1)
#define HT_FG  (1 << 2)
#define HT_SUB (1 << 3)
#define HT_CLR (1 << 4)

static void paint_raw(uint8_t *dst, int bw, int bh, GetByteContext *gb, int bpp, int bigendian, int stride);
static void paint_rect(uint8_t *dst, int x, int y, int w, int h, int color, int bpp, int stride);
static int vmnc_get_pixel(GetByteContext *gb, int bpp, int bigendian);
static int bytestream2_get_byte(GetByteContext *gb);
static int bytestream2_get_bytes_left(GetByteContext *gb);