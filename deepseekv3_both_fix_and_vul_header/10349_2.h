#include <stdlib.h>
#include <assert.h>

typedef int fixed;

typedef struct {
    fixed x, y;
} gs_fixed_point;

typedef struct {
    gs_fixed_point p, q;
} gs_fixed_rect;

typedef enum {
    DIRN_UNSET,
    s_start,
    s_dash,
    s_curve,
    s_gap,
    s_line,
    s_line_close
} segment_type;

typedef struct segment {
    struct segment *next;
    segment_type type;
    gs_fixed_point pt;
} segment;

typedef struct curve_segment {
    struct segment header;
    gs_fixed_point p1, p2;
} curve_segment;

typedef struct subpath {
    struct segment header;
} subpath;

typedef struct gx_path {
    subpath *first_subpath;
} gx_path;

typedef struct gx_edgebuffer {
    int *index;
    int *table;
    fixed base;
    int height;
    fixed xmin;
    fixed xmax;
} gx_edgebuffer;

typedef struct gx_device {
    // minimal device definition
} gx_device;

typedef struct {
    int scanlines;
    int *index;
    int *table;
    fixed base;
    fixed left;
    fixed right;
    int lid;
    int rid;
    fixed y;
    int d;
    int first;
    int saved;
} cursor_tr;

int make_bbox(gx_path *path, const gs_fixed_rect *clip, gs_fixed_rect *ibox, int flag);
int make_table_tr_app(gx_device *pdev, gx_path *path, gs_fixed_rect *ibox, int *scanlines, int **index, int **table);
void mark_curve_tr_app(cursor_tr *cr, fixed sx, fixed sy, fixed p1x, fixed p1y, fixed p2x, fixed p2y, fixed ex, fixed ey, int k, int *id);
void mark_line_tr_app(cursor_tr *cr, fixed sx, fixed sy, fixed ex, fixed ey, int id);
void cursor_flush_tr(cursor_tr *cr, fixed ex, int id);
int gx_curve_log2_samples(fixed sx, fixed sy, const curve_segment *pcur, fixed fixed_flat);
int edgecmp_tr(const void *a, const void *b);