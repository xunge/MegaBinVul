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
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct KgvContext {
    uint16_t *cur;
    uint16_t *prev;
    AVFrame pic;
} KgvContext;

#define AV_RL16(x) ((x)[0] | ((x)[1] << 8))
#define AV_RL24(x) ((x)[0] | ((x)[1] << 8) | ((x)[2] << 16))
#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)
#define AV_LOG_DEBUG 0

static void *av_realloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}

static int av_image_check_size(int w, int h, int flags, AVCodecContext *avctx) {
    return 0;
}

static void avcodec_set_dimensions(AVCodecContext *avctx, int width, int height) {
    avctx->width = width;
    avctx->height = height;
}

static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}