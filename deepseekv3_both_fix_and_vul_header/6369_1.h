#include <stdint.h>
#include <stdlib.h>

typedef struct AVFilterLink {
    struct AVFilterContext *dst;
    int w;
    int h;
    struct AVFilterLink **outputs;
} AVFilterLink;

typedef struct AVFilterContext {
    struct AVFilterLink **outputs;
    void *priv;
    struct AVFilterInternal *internal;
} AVFilterContext;

typedef struct AVFilterInternal {
    int (*execute)(AVFilterContext *ctx, int (*func)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs), void *arg, void *ret, int nb_jobs);
} AVFilterInternal;

typedef struct AVFrame AVFrame;

typedef struct LenscorrectionCtx {
    int width;
    int height;
    int nb_planes;
    int hsub;
    int vsub;
    float cx;
    float cy;
    float k1;
    float k2;
    int **correction;
} LenscorrectionCtx;

typedef struct ThreadData {
    AVFrame *in;
    AVFrame *out;
    int w;
    int h;
    int xcenter;
    int ycenter;
    int plane;
    int *correction;
} ThreadData;

#define AVERROR(e) (-(e))
#define ENOMEM 12
#define FFMIN(a, b) ((a) > (b) ? (b) : (a))

AVFrame *ff_get_video_buffer(AVFilterLink *link, int w, int h);
void av_frame_free(AVFrame **frame);
void av_frame_copy_props(AVFrame *dst, const AVFrame *src);
void *av_malloc_array(size_t nmemb, size_t size);
int ff_filter_frame(AVFilterLink *link, AVFrame *frame);
int ff_filter_get_nb_threads(AVFilterContext *ctx);
int filter_slice(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);