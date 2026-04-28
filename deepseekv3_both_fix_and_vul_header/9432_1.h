#include <stdint.h>
#include <stdlib.h>

#define AVERROR_INVALIDDATA (-1)
#define AVERROR(ENOMEM) (-2)
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1
#define FF_LZW_GIF 0

#define GCE_DISPOSAL_NONE 0
#define GCE_DISPOSAL_BACKGROUND 1
#define GCE_DISPOSAL_RESTORE 2

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int width, height;
} AVFrame;

typedef struct ByteStream2 {
    uint8_t *buffer;
    int bytes_left;
} ByteStream2;

typedef struct GifState {
    ByteStream2 gb;
    AVFrame *avctx;
    uint32_t *global_palette;
    uint32_t *local_palette;
    uint32_t bg_color;
    uint32_t trans_color;
    int screen_width;
    int screen_height;
    int has_global_palette;
    int transparent_color_index;
    int keyframe;
    int gce_disposal;
    int gce_prev_disposal;
    int gce_l, gce_t, gce_w, gce_h;
    uint32_t *stored_img;
    size_t stored_img_size;
    uint32_t stored_bg_color;
    void *lzw;
    uint8_t *idx_line;
} GifState;

static int bytestream2_get_bytes_left(ByteStream2 *s) { return s->bytes_left; }
static uint16_t bytestream2_get_le16u(ByteStream2 *s) { uint16_t v = s->buffer[0] | (s->buffer[1] << 8); s->buffer += 2; s->bytes_left -= 2; return v; }
static uint8_t bytestream2_get_byteu(ByteStream2 *s) { uint8_t v = *s->buffer++; s->bytes_left--; return v; }
static void av_dlog(void *avctx, const char *fmt, ...) {}
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void *av_fast_malloc(void *ptr, size_t *size, size_t min_size) { if (min_size > *size) { free(ptr); *size = min_size; return malloc(min_size); } return ptr; }