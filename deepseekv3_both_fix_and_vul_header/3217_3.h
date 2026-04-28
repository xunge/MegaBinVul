#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct AVFilterContext AVFilterContext;
typedef struct AVFilterLink AVFilterLink;
typedef struct AVFrame AVFrame;
typedef struct KerndeintContext KerndeintContext;

struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
};

struct AVFilterLink {
    AVFilterContext *dst;
    AVFilterLink **outputs;
    int w;
    int h;
    int format;
};

struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int interlaced_frame;
};

struct KerndeintContext {
    int frame;
    int thresh;
    int order;
    int map;
    int sharp;
    int twoway;
    int is_packed_rgb;
    int vsub;
    int *tmp_bwidth;
    int *tmp_linesize;
    uint8_t **tmp_data;
};

#define FF_CEIL_RSHIFT(x, y) (((x) + (1 << (y)) - 1) >> (y))
#define AV_PIX_FMT_YUYV422 1
#define AVERROR(e) (-(e))
#define ENOMEM 12

static inline int av_clip(int a, int amin, int amax) { return a < amin ? amin : (a > amax ? amax : a); }
static inline void AV_WB32(void *p, uint32_t v) { *(uint32_t*)p = v; }

static AVFrame *ff_get_video_buffer(AVFilterLink *link, int w, int h) { return NULL; }
static void av_frame_free(AVFrame **frame) {}
static void av_frame_copy_props(AVFrame *dst, const AVFrame *src) {}
static int ff_filter_frame(AVFilterLink *outlink, AVFrame *outpic) { return 0; }
static void av_image_copy_plane(uint8_t *dst, int dst_linesize, const uint8_t *src, int src_linesize, int width, int height) {}