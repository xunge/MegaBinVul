#include <stdint.h>

#define av_cold

typedef struct AVFilterContext {
    void *priv;
} AVFilterContext;

typedef struct AVFrame AVFrame;

typedef struct TileContext {
    AVFrame *out_ref;
    AVFrame *prev_out_ref;
} TileContext;

void av_frame_free(AVFrame **frame);