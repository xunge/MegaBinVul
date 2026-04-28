#include <stdlib.h>
#include <stdint.h>

#define av_cold

typedef struct AVCodecContext {
    void *priv_data;
} AVCodecContext;

typedef struct XPMDecContext {
    uint8_t *pixels;
    uint8_t *buf;
    int buf_size;
} XPMDecContext;

static inline void av_freep(void *arg) {
    free(*(void **)arg);
    *(void **)arg = NULL;
}