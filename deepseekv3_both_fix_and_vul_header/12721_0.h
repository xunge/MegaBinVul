#include <stdint.h>

#define NUM_PLANES 3
#define INDEX_ORD 0
#define INDEX_DIR 1
#define INDEX_SRC 2
#define INDEX_DST 3
#define DIR_X 0

#define INDX2D(r, c, w) ((r) * (w) + (c))
#define GINDX(size, g) ((g) - (size)/2)

typedef struct AVFilterContext {
    void *priv;
} AVFilterContext;

typedef struct AVFrame {
    uint8_t *data[NUM_PLANES];
    int linesize[NUM_PLANES];
} AVFrame;

typedef struct ColorConstancyContext {
    int filtersize;
    double *gauss[3];
    int planeheight[NUM_PLANES];
    int planewidth[NUM_PLANES];
} ColorConstancyContext;

typedef struct ThreadData {
    AVFrame *in;
    int *meta_data;
    double *data[2][NUM_PLANES];
} ThreadData;

#define GAUSS(src, r, c, stride, h, w, val) \
    ((r) >= 0 && (r) < (h) && (c) >= 0 && (c) < (w) ? (src)[INDX2D((r), (c), (stride))] * (val) : 0)