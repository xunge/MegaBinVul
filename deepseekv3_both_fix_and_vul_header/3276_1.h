#include <stdint.h>

typedef struct AVCodecContext {
    int width;
    int height;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct RpzaContext {
    AVCodecContext *avctx;
    AVFrame frame;
    const uint8_t *buf;
    int size;
} RpzaContext;

#define AV_LOG_ERROR 16
#define AV_RB16(x) (((x)[0] << 8) | (x)[1])
#define AV_RB32(x) (((x)[0] << 24) | ((x)[1] << 16) | ((x)[2] << 8) | (x)[3])

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);

#define ADVANCE_BLOCK() \
    pixel_ptr += 4; \
    if (pixel_ptr >= width) { \
        pixel_ptr = 0; \
        row_ptr += stride * 4; \
    }