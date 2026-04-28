#include <stdint.h>
#include <string.h>

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct AVCodecContext {
    int height;
} AVCodecContext;

typedef struct CinepakContext {
    AVFrame *frame;
    AVCodecContext *avctx;
    int palette_video;
} CinepakContext;

typedef struct cvid_strip {
    int x1, x2, y1, y2;
    uint8_t *v1_codebook[256];
    uint8_t *v4_codebook[256];
} cvid_strip;

#define AVERROR_INVALIDDATA (-1)
#define AV_RB32(x) (*(const uint32_t*)(x))