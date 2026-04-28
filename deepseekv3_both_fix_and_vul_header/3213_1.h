#include <stdint.h>
#include <stdlib.h>

typedef struct AVFilterLink {
    int w;
    int h;
    struct AVFilterContext *dst;
    struct AVFilterLink **outputs;
} AVFilterLink;

typedef struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
} AVFilterContext;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int height;
} AVFrame;

typedef struct BoxBlurContext {
    int hsub;
    int vsub;
    int radius[4];
    int power[4];
    uint8_t *temp;
} BoxBlurContext;

#define FF_CEIL_RSHIFT(x, y) (((x) + (1 << (y)) - 1) >> (y))
#define AVERROR(e) (-(e))
#define ENOMEM 12

AVFrame *ff_get_video_buffer(AVFilterLink *outlink, int w, int h);
void av_frame_free(AVFrame **frame);
void av_frame_copy_props(AVFrame *dst, const AVFrame *src);
int ff_filter_frame(AVFilterLink *outlink, AVFrame *frame);

void hblur(uint8_t *dst, int dst_linesize,
           const uint8_t *src, int src_linesize,
           int w, int h, int radius, int power,
           uint8_t *temp);

void vblur(uint8_t *dst, int dst_linesize,
           const uint8_t *src, int src_linesize,
           int w, int h, int radius, int power,
           uint8_t *temp);