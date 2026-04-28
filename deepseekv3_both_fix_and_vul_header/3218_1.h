#include <stdint.h>
#include <stdlib.h>

typedef struct AVFilterLink {
    int w;
    int h;
    struct AVFilterContext *dst;
    struct AVFilterLink **outputs;
} AVFilterLink;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int height;
    int width;
} AVFrame;

typedef struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
} AVFilterContext;

typedef struct LutContext {
    int is_rgb;
    int step;
    int vsub;
    int hsub;
    uint8_t *lut[4];
} LutContext;

#define FF_CEIL_RSHIFT(a,b) (-((-(a)) >> (b)))
#define AVERROR(e) (-(e))
#define ENOMEM 12

AVFrame *ff_get_video_buffer(AVFilterLink *link, int w, int h);
void av_frame_free(AVFrame **frame);
int av_frame_is_writable(const AVFrame *frame);
void av_frame_copy_props(AVFrame *dst, const AVFrame *src);
int ff_filter_frame(AVFilterLink *link, AVFrame *frame);