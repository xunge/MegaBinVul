#include <stdint.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    int width;
    int height;
    AVRational time_base;
} AVCodecContext;

typedef struct AVFrame AVFrame;

typedef struct CmvContext {
    AVCodecContext *avctx;
    AVFrame *last_frame;
    AVFrame *last2_frame;
    int width;
    int height;
    uint32_t palette[256];
} CmvContext;

#define AV_LOG_WARNING 24
#define AVERROR_INVALIDDATA (-1)
#define AVPALETTE_COUNT 256

static inline uint16_t AV_RL16(const uint8_t *p) {
    return p[0] | (p[1] << 8);
}

static inline uint32_t AV_RB24(const uint8_t *p) {
    return (p[0] << 16) | (p[1] << 8) | p[2];
}

void av_log(void *avcl, int level, const char *fmt, ...);
void av_frame_unref(AVFrame *frame);
int ff_set_dimensions(AVCodecContext *s, int width, int height);