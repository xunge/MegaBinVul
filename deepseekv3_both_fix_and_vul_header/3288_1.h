#include <stdint.h>
#include <string.h>

#define AVERROR_INVALIDDATA 1
#define AVERROR_PATCHWELCOME 2
#define JPEG2000_MAX_RESLEVELS 33
#define JPEG2000_CSTY_PREC 0x01
#define CODEC_FLAG_BITEXACT 0x0001
#define FF_DWT97 0
#define FF_DWT97_INT 1
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24

typedef struct AVCodecContext {
    int flags;
} AVCodecContext;

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

static inline unsigned int bytestream2_get_bytes_left(GetByteContext *g)
{
    return g->buffer_end - g->buffer;
}

static inline uint8_t bytestream2_get_byteu(GetByteContext *g)
{
    return *g->buffer++;
}

static inline uint8_t bytestream2_get_byte(GetByteContext *g)
{
    return *g->buffer++;
}

static inline void av_log(void *avctx, int level, const char *fmt, ...) {}

static inline void avpriv_request_sample(void *avctx, const char *msg) {}

typedef struct Jpeg2000DecoderContext {
    GetByteContext g;
    AVCodecContext *avctx;
    int reduction_factor;
} Jpeg2000DecoderContext;

typedef struct Jpeg2000CodingStyle {
    int nreslevels;
    int nreslevels2decode;
    int log2_cblk_width;
    int log2_cblk_height;
    int cblk_style;
    int transform;
    int csty;
    uint8_t log2_prec_widths[JPEG2000_MAX_RESLEVELS];
    uint8_t log2_prec_heights[JPEG2000_MAX_RESLEVELS];
} Jpeg2000CodingStyle;