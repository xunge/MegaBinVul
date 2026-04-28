#include <stdint.h>
#include <stdlib.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVFilterContext {
    void *priv;
    struct AVFilterLink **outputs;
} AVFilterContext;

typedef struct AVFilterLink {
    AVFilterContext *dst;
    int format;
    int w;
    int h;
} AVFilterLink;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    AVRational sample_aspect_ratio;
} AVFrame;

typedef struct AVPixFmtDescriptor {
    int log2_chroma_w;
    int log2_chroma_h;
} AVPixFmtDescriptor;

typedef struct DelogoContext {
    int x;
    int y;
    int w;
    int h;
    int band;
    int show;
} DelogoContext;

#define FF_CEIL_RSHIFT(a,b) (-((-(a)) >> (b)))
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define AVERROR(e) (-(e))
#define ENOMEM 12

extern const AVPixFmtDescriptor *av_pix_fmt_desc_get(int format);
extern int av_frame_is_writable(const AVFrame *frame);
extern AVFrame *ff_get_video_buffer(AVFilterLink *link, int w, int h);
extern void av_frame_free(AVFrame **frame);
extern void av_frame_copy_props(AVFrame *dst, const AVFrame *src);
extern int ff_filter_frame(AVFilterLink *link, AVFrame *frame);
extern void apply_delogo(uint8_t *dst, int dst_linesize,
                        const uint8_t *src, int src_linesize,
                        int width, int height, AVRational sar,
                        int x, int y, int logo_w, int logo_h,
                        int band, int show, int direct);