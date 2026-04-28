#include <stdint.h>
#include <string.h>

#define AVERROR_INVALIDDATA -1
#define AVERROR(EINVAL) -2
#define AVERROR_PATCHWELCOME -3
#define JPEG2000_MAX_RESLEVELS 33
#define JPEG2000_CSTY_PREC 0x01
#define FF_DWT97 1
#define FF_DWT97_INT 2
#define CODEC_FLAG_BITEXACT 0x0001
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct Jpeg2000DecoderContext {
    struct AVCodecContext *avctx;
    int reduction_factor;
    GetByteContext g;
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

struct AVCodecContext {
    int flags;
};

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

void av_log(struct AVCodecContext *avctx, int level, const char *fmt, ...);
void avpriv_request_sample(struct AVCodecContext *avctx, const char *msg);