#include <stdint.h>

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
    void (*log_callback)(void*, int, const char*, ...);
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[3];
    int linesize[3];
} AVFrame;

#define AV_LOG_ERROR 0
#define AVERROR_INVALIDDATA (-1)
#define AV_PIX_FMT_YUV444P 0

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}

static int ff_get_buffer(AVCodecContext *avctx, AVFrame *pic, int flags) { return 0; }