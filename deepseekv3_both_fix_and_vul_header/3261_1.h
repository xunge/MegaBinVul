#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

typedef struct AVCodecContext {
    int sample_fmt;
} AVCodecContext;

typedef struct ALACContext {
    int max_samples_per_frame;
    int channels;
    int sample_size;
    AVCodecContext *avctx;
    int32_t *predict_error_buffer[2];
    int32_t *output_samples_buffer[2];
    int32_t *extra_bits_buffer[2];
    int direct_output;
} ALACContext;

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))
#define FF_ALLOC_OR_GOTO(ctx, ptr, size, label) \
    do { \
        ptr = malloc(size); \
        if (!ptr) goto label; \
    } while (0)

int alac_decode_close(AVCodecContext *avctx);
#define AVERROR(e) (-(e))
#define ENOMEM 12

int av_sample_fmt_is_planar(int sample_fmt);