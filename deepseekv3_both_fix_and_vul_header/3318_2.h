#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct AVSubtitle {
    int num_rects;
} AVSubtitle;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
    int64_t pts;
    int64_t duration;
} AVPacket;

typedef struct AVCodecContext {
    void *time_base;
} AVCodecContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVBPrint {
    char *str;
} AVBPrint;

#define AVERROR(e) (-(e))
#define AVERROR_INVALIDDATA AVERROR(EINVAL)
#define AVERROR_ENOMEM AVERROR(ENOMEM)
#define AV_RB16(p) (*(const uint16_t*)(p))
#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define AV_BPRINT_SIZE_UNLIMITED 0

static void av_bprint_init(AVBPrint *buf, int dummy, int size) {}
static int av_bprint_is_complete(AVBPrint *buf) { return 1; }
static void av_bprint_finalize(AVBPrint *buf, void *dummy) {}
static void ff_ass_add_rect(AVSubtitle *sub, const char *str, int ts_start, int duration, int dummy) {}
static void text_to_ass(AVBPrint *buf, const char *ptr, const char *end) {}

static int64_t av_rescale_q(int64_t a, void *b, AVRational c) { return 0; }