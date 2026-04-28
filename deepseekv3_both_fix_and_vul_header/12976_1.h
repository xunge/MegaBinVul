#include <stdint.h>
#include <string.h>

#define AV_COPY16(d, s) memcpy(d, s, 16)

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)
#define AV_PIX_FMT_YUV420P 0

static int ff_get_buffer(AVCodecContext *avctx, AVFrame *pic, int flags) {
    return 0;
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}