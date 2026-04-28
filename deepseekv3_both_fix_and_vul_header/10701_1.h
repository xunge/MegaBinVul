#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct XPMDecContext {
    uint8_t *buf;
    int buf_size;
    uint32_t *pixels;
    int pixels_size;
} XPMDecContext;

typedef struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
    void *priv_data;
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[8];
    int linesize[8];
    int key_frame;
    int pict_type;
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

#define AV_PIX_FMT_BGRA 0
#define AV_LOG_ERROR 0
#define AV_PICTURE_TYPE_I 0
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
#define AVERROR_INVALIDDATA (-EINVAL)

static int mod_strcspn(const char *s, const char *reject) { return 0; }
static int ascii2index(const uint8_t *index, int cpp) { return 0; }
static uint32_t color_string_to_rgba(const char *ptr, int len) { return 0; }
static int ff_set_dimensions(AVCodecContext *avctx, int width, int height) { return 0; }
static int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame, int flags) { return 0; }
static void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size) {}
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}