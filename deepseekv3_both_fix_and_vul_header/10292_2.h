#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define SEEK_SET 0

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct PicContext {
    GetByteContext g;
    int width;
    int height;
    int nb_planes;
} PicContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    int pict_type;
    int palette_has_changed;
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int pix_fmt;
} AVCodecContext;

#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2
#define AV_PIX_FMT_PAL8 0
#define AV_PICTURE_TYPE_I 1
#define AVPALETTE_SIZE 1024

static const uint32_t ff_cga_palette[16] = {0};
static const uint32_t ff_ega_palette[64] = {0};
static const int cga_mode45_index[4][4] = {{0}};

static inline void bytestream2_init(GetByteContext *g, const uint8_t *buf, int buf_size) {
    g->buffer = buf;
    g->buffer_start = buf;
    g->buffer_end = buf + buf_size;
}

static inline int bytestream2_get_bytes_left(const GetByteContext *g) {
    return g->buffer_end - g->buffer;
}

static inline uint16_t bytestream2_get_le16u(GetByteContext *g) {
    uint16_t val = g->buffer[0] | (g->buffer[1] << 8);
    g->buffer += 2;
    return val;
}

static inline void bytestream2_skip(GetByteContext *g, int size) {
    g->buffer += size;
}

static inline uint8_t bytestream2_get_byteu(GetByteContext *g) {
    return *g->buffer++;
}

static inline uint8_t bytestream2_get_byte(GetByteContext *g) {
    return *g->buffer++;
}

static inline uint8_t bytestream2_peek_byte(const GetByteContext *g) {
    return *g->buffer;
}

static inline uint16_t bytestream2_get_le16(GetByteContext *g) {
    return bytestream2_get_le16u(g);
}

static inline int bytestream2_tell(const GetByteContext *g) {
    return g->buffer - g->buffer_start;
}

static inline void bytestream2_seek(GetByteContext *g, int offset, int whence) {
    if (whence == SEEK_SET)
        g->buffer = g->buffer_start + offset;
}

static inline uint32_t bytestream2_get_be24(GetByteContext *g) {
    uint32_t val = (g->buffer[0] << 16) | (g->buffer[1] << 8) | g->buffer[2];
    g->buffer += 3;
    return val;
}

static inline int FFMIN(int a, int b) {
    return a < b ? a : b;
}

static inline int av_image_check_size(int width, int height, int log_offset, AVCodecContext *avctx) {
    return 0;
}

static inline int ff_set_dimensions(AVCodecContext *avctx, int width, int height) {
    avctx->width = width;
    avctx->height = height;
    return 0;
}

static inline int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame, int flags) {
    return 0;
}

static inline void avpriv_request_sample(AVCodecContext *avctx, const char *msg) {
}

static inline void picmemset_8bpp(PicContext *s, AVFrame *frame, int val, int run, int *x, int *y) {
}

static inline void picmemset(PicContext *s, AVFrame *frame, int val, int run, int *x, int *y, int *plane, int bits_per_plane) {
}