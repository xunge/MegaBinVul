#include <stdint.h>
#include <string.h>

#define AV_LOG_ERROR 16
#define AV_PIX_FMT_YUV410P 6
#define AVERROR_INVALIDDATA -1

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[3];
    int linesize[3];
} AVFrame;

static inline void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}

static inline int ff_get_buffer(AVCodecContext *avctx, AVFrame *pic, int flags) { return 0; }

#define AV_COPY32(d, s) memcpy(d, s, 4)