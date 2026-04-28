#include <stdint.h>
#include <stdlib.h>

#define av_cold
#define AVERROR_PATCHWELCOME (-1)
#define AV_PIX_FMT_YUV444P 2

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    int width, height;
    int format;
    void *priv_data;
} AVFrame;

typedef struct AVCodecContext {
    int width, height;
    int pix_fmt;
    void *priv_data;
} AVCodecContext;

typedef struct RoqContext {
    AVCodecContext *avctx;
    int width, height;
    AVFrame frames[2];
    AVFrame *last_frame;
    AVFrame *current_frame;
} RoqContext;

static void avcodec_get_frame_defaults(AVFrame *frame) {
    memset(frame, 0, sizeof(AVFrame));
}

static void av_log_ask_for_sample(AVCodecContext *avctx, const char *msg) {
    (void)avctx;
    (void)msg;
}