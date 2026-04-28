#include <stdint.h>
#include <stdio.h>

typedef struct AVFilterLink {
    struct AVFilterContext *dst;
    int format;
    int h;
    int64_t frame_count;
    void *time_base;
} AVFilterLink;

typedef struct AVFrame {
    uint8_t *data[4];
    int format;
    int width;
    int height;
    int linesize[4];
    int64_t pts;
    int64_t pkt_pos;
    struct {
        int num;
        int den;
    } sample_aspect_ratio;
    int interlaced_frame;
    int top_field_first;
    int key_frame;
    int pict_type;
} AVFrame;

typedef struct AVFilterContext {
    struct AVFilterLink **outputs;
} AVFilterContext;

typedef struct AVPixFmtDescriptor {
    const char *name;
    int log2_chroma_h;
} AVPixFmtDescriptor;

#define FF_CEIL_RSHIFT(x, y) (-(-(x) >> (y)))
#define PRId64 "lld"
#define AV_LOG_INFO 0

uint32_t av_adler32_update(uint32_t adler, const uint8_t *buf, size_t len);
int64_t av_image_get_linesize(int format, int width, int plane);
const char *av_ts2str(int64_t ts);
const char *av_ts2timestr(int64_t ts, void *time_base);
int64_t av_frame_get_pkt_pos(const AVFrame *frame);
char av_get_picture_type_char(int pict_type);
int ff_filter_frame(AVFilterLink *outlink, AVFrame *frame);
const AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt);
void av_log(void *avcl, int level, const char *fmt, ...);