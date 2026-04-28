#include <stdint.h>
#include <stdlib.h>

typedef struct AVFilterContext AVFilterContext;

typedef struct AVFilterLink {
    struct AVFilterContext *dst;
    int format;
    int w;
    int h;
} AVFilterLink;

typedef struct AVFilterContext {
    void *priv;
} AVFilterContext;

typedef struct AVPixFmtDescriptor {
    int log2_chroma_w;
    int log2_chroma_h;
} AVPixFmtDescriptor;

typedef struct FieldMatchContext {
    float scthresh_flt;
    int64_t scthresh;
    int hsub;
    int vsub;
    int tpitchy;
    int tpitchuv;
    uint8_t *map_data[4];
    int map_linesize[4];
    uint8_t *cmask_data[4];
    int cmask_linesize[4];
    uint8_t *tbuffer;
    int *c_array;
    int blockx;
    int blocky;
} FieldMatchContext;

#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))

int av_image_alloc(uint8_t *pointers[4], int linesizes[4],
                   int w, int h, int pix_fmt, int align);
void *av_malloc(size_t size);
const AVPixFmtDescriptor *av_pix_fmt_desc_get(int pix_fmt);

#define AVERROR(e) (-(e))
#define ENOMEM 12