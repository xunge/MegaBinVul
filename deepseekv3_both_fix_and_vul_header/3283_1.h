#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVCodecContext {
    int width;
    int height;
    void *priv_data;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int flags;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct FlashSVContext {
    int block_width;
    int block_height;
    int image_width;
    int image_height;
    int block_size;
    int ver;
    int is_keyframe;
    uint8_t *tmpblock;
    uint8_t *deflate_block;
    int deflate_block_size;
    uint8_t *keyframe;
    uint8_t *keyframedata;
    void *blocks;
    AVFrame frame;
    int color_depth;
    int zlibprime_curr;
    int zlibprime_prev;
    int diff_start;
    int diff_height;
} FlashSVContext;

#define AV_PKT_FLAG_KEY 0x0001
#define AVERROR_PATCHWELCOME (-1)
#define AVERROR_INVALIDDATA (-2)
#define AVERROR(ENOMEM) (-3)
#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 1

static void init_get_bits(GetBitContext *gb, const uint8_t *buffer, int bit_size) {
    gb->buffer = buffer;
    gb->index = 0;
    gb->size_in_bits = bit_size;
}

static unsigned int get_bits(GetBitContext *gb, int n) {
    unsigned int ret = 0;
    while (n--) {
        ret = (ret << 1) | ((gb->buffer[gb->index >> 3] >> (7 - (gb->index & 7))) & 1);
        gb->index++;
    }
    return ret;
}

static unsigned int get_bits1(GetBitContext *gb) {
    return get_bits(gb, 1);
}

static void skip_bits(GetBitContext *gb, int n) {
    gb->index += n;
}

static int get_bits_left(GetBitContext *gb) {
    return gb->size_in_bits - gb->index;
}

static int get_bits_count(GetBitContext *gb) {
    return gb->index;
}

static void av_freep(void *ptr) {
    free(*(void**)ptr);
    *(void**)ptr = NULL;
}

static void *av_realloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}

static void *av_mallocz(size_t size) {
    void *ptr = malloc(size);
    if (ptr) memset(ptr, 0, size);
    return ptr;
}

static void *av_malloc(size_t size) {
    return malloc(size);
}

static void avpriv_request_sample(AVCodecContext *avctx, const char *msg) {
    (void)avctx;
    (void)msg;
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {
    (void)avctx;
    (void)level;
    (void)fmt;
}

static int av_frame_ref(void *dst, const AVFrame *src) {
    *(AVFrame*)dst = *src;
    return 0;
}

static void av_frame_unref(AVFrame *frame) {
    (void)frame;
}

static int ff_reget_buffer(AVCodecContext *avctx, AVFrame *frame) {
    (void)avctx;
    (void)frame;
    return 0;
}

static void avcodec_set_dimensions(AVCodecContext *avctx, int width, int height) {
    avctx->width = width;
    avctx->height = height;
}

static int flashsv_decode_block(AVCodecContext *avctx, AVPacket *avpkt, GetBitContext *gb, int size, int width, int height, int x_pos, int y_pos, int blk_idx) {
    (void)avctx;
    (void)avpkt;
    (void)gb;
    (void)size;
    (void)width;
    (void)height;
    (void)x_pos;
    (void)y_pos;
    (void)blk_idx;
    return 0;
}

static int calc_deflate_block_size(int size) {
    return size;
}

#define av_dlog av_log