#include <stdint.h>
#include <stdlib.h>

typedef struct AVFilterLink AVFilterLink;
typedef struct AVFrame AVFrame;
typedef struct AVPixFmtDescriptor AVPixFmtDescriptor;

typedef struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
} AVFilterContext;

typedef struct AVFilterLink {
    AVFilterContext *dst;
    int w, h;
    AVFilterLink **outputs;
} AVFilterLink;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct AVPixFmtDescriptor {
    int flags;
    int log2_chroma_w;
    int log2_chroma_h;
} AVPixFmtDescriptor;

typedef struct VignetteContext {
    int eval_mode;
    float *fmap;
    int fmap_linesize;
    const AVPixFmtDescriptor *desc;
} VignetteContext;

enum {
    EVAL_MODE_FRAME,
    AV_PIX_FMT_FLAG_RGB
};

static inline uint8_t av_clip_uint8(int a) {
    if (a&(~0xFF)) return (-a)>>31;
    else return a;
}

#define FF_CEIL_RSHIFT(a,b) (-((-a) >> b))
#define AVERROR(e) (-(e))
#define ENOMEM 12