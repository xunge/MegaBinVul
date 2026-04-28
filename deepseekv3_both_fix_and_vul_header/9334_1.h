#include <stdint.h>
#include <stdlib.h>

typedef struct AVFrame AVFrame;

typedef struct AVCodecContext {
    void *priv_data;
} AVCodecContext;

typedef struct GIFContext {
    uint8_t *lzw;
    uint8_t *buf;
    int buf_size;
    AVFrame *last_frame;
    uint8_t *tmpl;
} GIFContext;

void av_freep(void *ptr);
void av_frame_free(AVFrame **frame);