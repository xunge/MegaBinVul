#include <stdlib.h>

#define av_cold

typedef struct AVCodecContext {
    void *priv_data;
} AVCodecContext;

typedef struct ShortenContext {
    int channels;
    int nwrap;
    int **decoded;
    int **decoded_base;
    int **offset;
    void *bitstream;
    void *coeffs;
} ShortenContext;

static inline void av_freep(void *arg) {
    free(*(void**)arg);
    *(void**)arg = NULL;
}