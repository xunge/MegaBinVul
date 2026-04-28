#include <stdint.h>
#include <stdlib.h>

typedef struct AVFilterLink AVFilterLink;
typedef struct AVFrame AVFrame;

typedef struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
} AVFilterContext;

struct AVFilterLink {
    AVFilterContext *dst;
    AVFilterLink **outputs;
    int w;
    int h;
};

struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
};

typedef struct GradFunContext {
    int radius;
    int chroma_w;
    int chroma_h;
    int chroma_r;
} GradFunContext;

int av_frame_is_writable(const AVFrame *frame);
void av_frame_free(AVFrame **frame);
int av_frame_copy_props(AVFrame *dst, const AVFrame *src);
void av_image_copy_plane(uint8_t *dst, int dst_linesize,
                         const uint8_t *src, int src_linesize,
                         int width, int height);
AVFrame *ff_get_video_buffer(AVFilterLink *link, int w, int h);
int ff_filter_frame(AVFilterLink *link, AVFrame *frame);

#define AVERROR(e) (-(e))
#define ENOMEM 12
#define FFMIN(a, b) ((a) > (b) ? (b) : (a))

static void filter(GradFunContext *s, uint8_t *dst, const uint8_t *src, int w, int h, int dst_linesize, int src_linesize, int r);