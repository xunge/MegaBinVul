#include <stdint.h>
#include <string.h>

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
} AVFrame;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)

static int ff_get_buffer(AVCodecContext *avctx, AVFrame *pic, int flags) {
    return 0;
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}