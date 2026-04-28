#include <stdint.h>
#include <stdlib.h>

typedef struct SANMVideoContext SANMVideoContext;
typedef struct AVCodecContext AVCodecContext;

struct SANMVideoContext {
    AVCodecContext *avctx;
    int width;
    int height;
    struct {
        unsigned char *buffer;
        int index;
    } gb;
};

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define AVERROR(e) (-(e))
#define AV_LOG_ERROR 0
#define AV_LOG_ASK_FOR_SAMPLE 0
#define ENOMEM 1
#define AVERROR_INVALIDDATA 2
#define AVERROR_PATCHWELCOME 3

static uint16_t bytestream2_get_le16u(void *p) { return 0; }
static void bytestream2_skip(void *p, int n) {}
static int av_image_check_size(int w, int h, int flags, void *ctx) { return 0; }
static void avcodec_set_dimensions(void *ctx, int w, int h) {}
static void av_log(void *ctx, int level, const char *fmt, ...) {}
static void av_dlog(void *ctx, const char *fmt, ...) {}
static void av_log_ask_for_sample(void *ctx, const char *fmt, ...) {}
static int init_sizes(SANMVideoContext *ctx, int w, int h) { return 0; }
static int init_buffers(SANMVideoContext *ctx) { return 0; }
static int old_codec1(SANMVideoContext *ctx, int top, int left, int w, int h) { return 0; }
static int old_codec37(SANMVideoContext *ctx, int top, int left, int w, int h) { return 0; }
static int old_codec47(SANMVideoContext *ctx, int top, int left, int w, int h) { return 0; }