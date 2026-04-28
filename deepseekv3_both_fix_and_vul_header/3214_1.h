#include <stdint.h>
#include <string.h>

typedef struct AVFilterLink {
    struct AVFilterContext *dst;
} AVFilterLink;

typedef struct AVFrame {
    int interlaced_frame;
    int top_field_first;
    int height;
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

typedef struct AVFilterContext {
    void *priv;
    AVFilterLink **outputs;
} AVFilterContext;

typedef struct FieldOrderContext {
    int dst_tff;
    int line_size[4];
} FieldOrderContext;

int ff_filter_frame(AVFilterLink *outlink, AVFrame *frame);
void av_dlog(void *avcl, const char *fmt, ...);