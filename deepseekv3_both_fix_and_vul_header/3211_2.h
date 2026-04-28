#include <stdint.h>
#include <stdlib.h>

typedef struct AVFilterLink AVFilterLink;
typedef struct AVFrame AVFrame;
typedef struct AVFilterContext AVFilterContext;
typedef struct AVDrawContext AVDrawContext;
typedef struct PadContext PadContext;

struct AVFilterLink {
    int w, h;
    AVFilterContext *dst;
    AVFilterLink **outputs;
};

struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int width, height;
};

struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
};

struct AVDrawContext {
    int hsub[4];
    int vsub[4];
    int pixelstep[4];
};

struct PadContext {
    int w, h;
    int x, y;
    int in_w, in_h;
    uint8_t color[4];
    AVDrawContext draw;
};

#define AV_LOG_DEBUG 0
#define ENOMEM 12
#define AVERROR(e) (-(e))
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

static int frame_needs_copy(struct PadContext *s, struct AVFrame *in);
static struct AVFrame *ff_get_video_buffer(struct AVFilterLink *output, int w, int h);
static void av_frame_free(struct AVFrame **frame);
static void av_frame_copy_props(struct AVFrame *dst, struct AVFrame *src);
static void ff_fill_rectangle(struct AVDrawContext *draw, uint8_t color[4], uint8_t **data, int *linesize, int x, int y, int w, int h);
static void ff_copy_rectangle2(struct AVDrawContext *draw, uint8_t **dst_data, int *dst_linesize, uint8_t **src_data, int *src_linesize, int dst_x, int dst_y, int src_x, int src_y, int w, int h);
static int ff_filter_frame(struct AVFilterLink *output, struct AVFrame *frame);
static void av_log(struct AVFilterContext *ctx, int level, const char *fmt, ...);