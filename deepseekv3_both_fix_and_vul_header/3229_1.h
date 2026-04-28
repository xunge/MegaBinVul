#include <stdint.h>
#include <stdlib.h>

typedef struct AVCodecContext {
    int width;
    int height;
} AVCodecContext;

typedef struct GetByteContext {
    unsigned char *buffer;
    int index;
} GetByteContext;

typedef struct SANMVideoContext {
    AVCodecContext *avctx;
    int width;
    int height;
    GetByteContext gb;
} SANMVideoContext;

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define AVERROR_INVALIDDATA (-1)
#define AVERROR(ENOMEM) (-2)
#define AVERROR_PATCHWELCOME (-3)
#define AV_LOG_ERROR 1

static inline uint16_t bytestream2_get_le16u(GetByteContext *gb) {
    uint16_t val = gb->buffer[gb->index] | (gb->buffer[gb->index + 1] << 8);
    gb->index += 2;
    return val;
}

static inline void bytestream2_skip(GetByteContext *gb, int n) {
    gb->index += n;
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static void av_log_ask_for_sample(AVCodecContext *avctx, const char *fmt, ...) {}
static void av_dlog(AVCodecContext *avctx, const char *fmt, ...) {}
static int av_image_check_size(int width, int height, int log_offset, AVCodecContext *avctx) { return 0; }
static void avcodec_set_dimensions(AVCodecContext *avctx, int width, int height) {}
static int init_sizes(SANMVideoContext *ctx, int width, int height) { return 0; }
static int init_buffers(SANMVideoContext *ctx) { return 0; }
static int old_codec1(SANMVideoContext *ctx, int top, int left, int w, int h) { return 0; }
static int old_codec37(SANMVideoContext *ctx, int top, int left, int w, int h) { return 0; }
static int old_codec47(SANMVideoContext *ctx, int top, int left, int w, int h) { return 0; }