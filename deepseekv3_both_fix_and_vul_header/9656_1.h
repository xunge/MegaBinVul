#include <stdlib.h>
#include <math.h>

typedef long TPos;

typedef struct FT_Vector_ {
    TPos x;
    TPos y;
} FT_Vector;

struct TRaster_ {
    TPos x;
    TPos y;
    int cubic_level;
    int conic_level;
    int max_ey;
    FT_Vector* bez_stack;
    int* lev_stack;
};

static struct TRaster_ ras;

#define DOWNSCALE(x) ((x) >> 1)
#define UPSCALE(x) ((x) << 1)
#define TRUNC(x) ((int)(x))

#define RAS_ARG_
#define RAS_VAR_
#define RAS_VARS_

static void gray_render_line(RAS_ARG_ TPos to_x, TPos to_y);
static void gray_split_cubic(FT_Vector* arc);