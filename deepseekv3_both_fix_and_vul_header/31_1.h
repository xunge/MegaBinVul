#include <stdint.h>
#include <stdlib.h>

#define AV_RL32(x) \
    ((uint32_t)((x)[0]) | ((uint32_t)((x)[1]) << 8) | \
     ((uint32_t)((x)[2]) << 16) | ((uint32_t)((x)[3]) << 24))
#define AV_WN32(p, v) \
    do { \
        ((uint8_t*)(p))[0] = (v); \
        ((uint8_t*)(p))[1] = (v) >> 8; \
        ((uint8_t*)(p))[2] = (v) >> 16; \
        ((uint8_t*)(p))[3] = (v) >> 24; \
    } while (0)
#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

enum AVPixelFormat {
    AV_PIX_FMT_RGB32,
    AV_PIX_FMT_RGB24,
    AV_PIX_FMT_YUV422P,
    AV_PIX_FMT_YUV420P
};

enum {
    FRAME_SOLID_RGBA,
    FRAME_ARITH_RGBA,
    FRAME_ARITH_RGB24,
    FRAME_U_RGB24,
    FRAME_ARITH_YUY2,
    FRAME_ARITH_YV12
};

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int key_frame;
    int width;
    int height;
    int pix_fmt;
} AVFrame;

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int pix_fmt;
} AVCodecContext;

typedef struct ThreadFrame {
    AVFrame *f;
} ThreadFrame;

typedef struct LagarithContext {
    void *priv_data;
    uint32_t rgb_stride;
    uint8_t *rgb_planes;
    size_t rgb_planes_allocated;
} LagarithContext;

#define AV_LOG_ERROR 16
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AVERROR_INVALIDDATA (-1)

int ff_thread_get_buffer(AVCodecContext *avctx, ThreadFrame *frame, int flags);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
void av_fast_malloc(void *ptr, unsigned int *size, size_t min_size);
int lag_decode_arith_plane(LagarithContext *l, uint8_t *dst,
                           int width, int height, int stride,
                           const uint8_t *src, int src_size);