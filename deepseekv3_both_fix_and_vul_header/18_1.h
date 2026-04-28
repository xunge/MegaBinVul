#include <stdint.h>

typedef struct AVCodecContext {
    int width;
    int height;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct ByteIOContext {
    uint8_t *buffer;
    uint8_t *buffer_end;
    uint8_t *buffer_start;
    int eof_reached;
} ByteIOContext;

typedef struct RpzaContext {
    AVCodecContext *avctx;
    AVFrame *frame;
    ByteIOContext gb;
} RpzaContext;

#define bytestream2_peek_byte(ctx) ((ctx)->buffer < (ctx)->buffer_end ? *(ctx)->buffer : 0)
#define bytestream2_get_byte(ctx) ((ctx)->buffer < (ctx)->buffer_end ? *(ctx)->buffer++ : 0)
#define bytestream2_get_be16(ctx) (bytestream2_get_byte(ctx) << 8 | bytestream2_get_byte(ctx))
#define bytestream2_get_be32(ctx) (bytestream2_get_byte(ctx) << 24 | bytestream2_get_byte(ctx) << 16 | \
                                 bytestream2_get_byte(ctx) << 8 | bytestream2_get_byte(ctx))
#define bytestream2_get_bytes_left(ctx) ((ctx)->buffer_end - (ctx)->buffer)
#define bytestream2_get_byteu(ctx) (*(ctx)->buffer++)
#define bytestream2_get_be16u(ctx) (bytestream2_get_byteu(ctx) << 8 | bytestream2_get_byteu(ctx))

#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1
static inline void av_log(void *avctx, int level, const char *fmt, ...) {}

#define ADVANCE_BLOCK() \
    pixel_ptr += 4; \
    if (pixel_ptr >= width) { \
        pixel_ptr = 0; \
        row_ptr += stride * 4; \
    }