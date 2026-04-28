#include <stdint.h>
#include <stddef.h>

typedef struct AVPacket {
    int64_t pts;
} AVPacket;

typedef struct AVFrame {
    uint8_t *base[4];
    uint8_t *data[4];
    int linesize[4];
    void *opaque;
    int type;
    uint8_t **extended_data;
    int64_t pkt_pts;
} AVFrame;

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
    AVPacket *pkt;
    void *opaque;
} AVCodecContext;

typedef struct FrameBuffer {
    uint8_t *base[4];
    uint8_t *data[4];
    int linesize[4];
    int w, h;
    int pix_fmt;
    int refcount;
    struct FrameBuffer *next;
} FrameBuffer;

typedef struct InputStream {
    FrameBuffer *buffer_pool;
    int dr1;
} InputStream;

#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))
#define FF_BUFFER_TYPE_USER 1
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))

static void av_freep(void *ptr);
static void av_free(void *ptr);
static int alloc_buffer(AVCodecContext *s, InputStream *ist, FrameBuffer **buf);