#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVFrame {
    int width;
    int height;
    int format;
    uint8_t *data[8];
    int linesize[8];
} AVFrame;

typedef struct AVCodecContext {
    void *priv_data;
    int frame_number;
} AVCodecContext;

typedef struct PNGEncContext {
    uint8_t *bytestream;
    uint8_t *bytestream_end;
    uint32_t sequence_number;
    int bits_per_pixel;
    AVFrame *last_frame;
    AVFrame *prev_frame;
} PNGEncContext;

typedef struct APNGFctlChunk {
    uint32_t width;
    uint32_t height;
    uint32_t x_offset;
    uint32_t y_offset;
    uint8_t dispose_op;
    uint8_t blend_op;
} APNGFctlChunk;

#define APNG_BLEND_OP_SOURCE 0
#define APNG_BLEND_OP_OVER 1
#define APNG_DISPOSE_OP_NONE 0
#define APNG_DISPOSE_OP_BACKGROUND 1
#define APNG_DISPOSE_OP_PREVIOUS 2

#define AVERROR(e) (-(e))
#define ENOMEM 12

static AVFrame *av_frame_alloc(void) { return calloc(1, sizeof(AVFrame)); }
static void av_frame_free(AVFrame **frame) { free(*frame); *frame = NULL; }
static int av_frame_get_buffer(AVFrame *frame, int align) { return 0; }
static void av_frame_copy(AVFrame *dst, const AVFrame *src) {}
static void *av_malloc(size_t size) { return malloc(size); }
static void av_freep(void *ptr) { free(*(void**)ptr); *(void**)ptr = NULL; }
static int encode_frame(AVCodecContext *avctx, const AVFrame *frame) { return 0; }
static int apng_do_inverse_blend(AVFrame *frame, const AVFrame *src, APNGFctlChunk *fctl, uint8_t bpp) { return 0; }