#include <stdint.h>

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA 1

#define PNG_IHDR 1
#define PNG_IDAT 2
#define PNG_PLTE 4

enum {
    PNG_COLOR_TYPE_PALETTE,
    PNG_COLOR_TYPE_GRAY,
    PNG_COLOR_TYPE_RGB
};

typedef struct AVCodecContext {
    void *log_ctx;
} AVCodecContext;

typedef struct PNGDecContext {
    unsigned int state;
    int color_type;
    int bit_depth;
    int has_trns;
    uint32_t *palette;
    uint8_t *transparent_color_be;
    struct {
        uint8_t *buffer;
        int index;
    } gb;
} PNGDecContext;

typedef struct {
    uint8_t *buffer;
    int index;
} GetByteContext;

#define bytestream2_get_byte(gb) ((gb)->buffer[(gb)->index++])
#define bytestream2_get_be16(gb) ((gb)->buffer[(gb)->index++] << 8 | (gb)->buffer[(gb)->index++])
#define bytestream2_skip(gb, n) ((gb)->index += (n))

static inline unsigned av_mod_uintp2(unsigned a, unsigned p)
{
    return a & ((1 << p) - 1);
}

#define AV_WB16(p, d) do { \
        ((uint8_t*)(p))[0] = (d) >> 8; \
        ((uint8_t*)(p))[1] = (d); \
    } while (0)