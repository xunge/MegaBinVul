#include <stdlib.h>
#include <assert.h>

typedef int fixed;

typedef struct gx_point {
    fixed x;
    fixed y;
} gx_point;

typedef struct gs_fixed_rect {
    gx_point p;
    gx_point q;
} gs_fixed_rect;

typedef struct gx_edgebuffer {
    int base;
    int height;
    int xmin;
    int xmax;
    int *index;
    int *table;
} gx_edgebuffer;

typedef struct segment {
    int type;
    gx_point pt;
    struct segment *next;
} segment;

typedef struct subpath {
    segment *first_subpath;
} subpath;

typedef struct gx_path {
    subpath *first_subpath;
} gx_path;

typedef struct curve_segment {
    segment seg;
    gx_point p1;
    gx_point p2;
} curve_segment;

typedef struct gx_device {
    // Minimal device structure definition
    int dummy;
} gx_device;

enum {
    s_start,
    s_line,
    s_line_close,
    s_curve,
    s_gap,
    s_dash
};

static const fixed fixed_half = 1;

int make_bbox(gx_path *path, const gs_fixed_rect *clip, gs_fixed_rect *ibox, fixed fixed_half);
int make_table_tr(gx_device *pdev, gx_path *path, gs_fixed_rect *ibox, int *scanlines, int **index, int **table);
void mark_curve_tr(fixed sx, fixed sy, fixed p1x, fixed p1y, fixed p2x, fixed p2y, fixed ex, fixed ey, fixed base_y, int scanlines, int *table, int *index, int *id, int k);
void mark_line_tr(fixed sx, fixed sy, fixed ex, fixed ey, fixed base_y, int scanlines, int *table, int *index, int id);
int gx_curve_log2_samples(fixed sx, fixed sy, const curve_segment *pcur, fixed fixed_flat);
int intcmp_tr(const void *a, const void *b);