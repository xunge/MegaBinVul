#include <stdint.h>
#include <string.h>

typedef struct AVFilterLink AVFilterLink;
typedef struct AVFrame AVFrame;
typedef struct AVFilterContext AVFilterContext;
typedef struct FlipContext FlipContext;
typedef struct AVPixFmtDescriptor AVPixFmtDescriptor;

struct AVFilterLink {
    struct AVFilterContext *dst;
    int w, h;
    int format;
};

struct AVFilterContext {
    void *priv;
    struct AVFilterLink **outputs;
};

struct FlipContext {
    int hsub, vsub;
    int max_step[4];
};

struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
};

struct AVPixFmtDescriptor {
    int flags;
};

#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AVPALETTE_SIZE (256 * 4)
#define AV_PIX_FMT_FLAG_PAL (1 << 0)
#define FF_CEIL_RSHIFT(x, y) (-((-(x)) >> (y)))

#define AV_RB24(x)  ((((const uint8_t*)(x))[0] << 16) | \
                     (((const uint8_t*)(x))[1] <<  8) | \
                     ((const uint8_t*)(x))[2])
#define AV_WB24(p, d) do { \
        ((uint8_t*)(p))[0] = (d) >> 16; \
        ((uint8_t*)(p))[1] = (d) >>  8; \
        ((uint8_t*)(p))[2] = (d);       \
    } while (0)

static void av_frame_free(struct AVFrame **frame) { }
static struct AVFrame *ff_get_video_buffer(struct AVFilterLink *link, int w, int h) { return 0; }
static void av_frame_copy_props(struct AVFrame *dst, const struct AVFrame *src) { }
static const struct AVPixFmtDescriptor *av_pix_fmt_desc_get(int format) { return 0; }
static int ff_filter_frame(struct AVFilterLink *outlink, struct AVFrame *out) { return 0; }