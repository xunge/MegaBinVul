#include <stdint.h>

typedef struct GetByteContext {
    const uint8_t *buffer, *buffer_end, *buffer_start;
} GetByteContext;

typedef struct AVCodecContext {
    int width, height;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
} AVFrame;

typedef struct MmContext {
    GetByteContext gb;
    AVCodecContext *avctx;
    AVFrame frame;
} MmContext;

#define AVERROR_INVALIDDATA (-1)