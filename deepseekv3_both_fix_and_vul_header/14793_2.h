#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

#define av_always_inline inline
#define MAX_THREADS 64
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define FF_THREAD_SLICE 1
#define HAVE_THREADS 1

#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct AVCodecContext {
    int width;
    int height;
    int coded_width;
    int coded_height;
    int active_thread_type;
    int thread_count;
} AVCodecContext;

typedef struct VP8ThreadData {
    int *filter_strength;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} VP8ThreadData;

typedef struct VP8Context {
    AVCodecContext *avctx;
    int mb_width;
    int mb_height;
    int mb_layout;
    int num_coeff_partitions;
    void *macroblocks_base;
    void *macroblocks;
    uint8_t *intra4x4_pred_mode_top;
    uint16_t *top_nnz;
    uint8_t *top_border;
    VP8ThreadData *thread_data;
} VP8Context;

void vp8_decode_flush_impl(AVCodecContext *avctx, int flag);
int ff_set_dimensions(AVCodecContext *avctx, int width, int height);
void free_buffers(VP8Context *s);
void *av_mallocz(size_t size);