#include <stdlib.h>
#include <assert.h>

typedef int fixed;

struct gs_fixed_point {
    fixed x;
    fixed y;
};

struct gs_fixed_rect {
    struct gs_fixed_point p;
    struct gs_fixed_point q;
};

struct segment {
    struct gs_fixed_point pt;
    struct segment *next;
    int type;
};

struct curve_segment {
    struct segment seg;
    struct gs_fixed_point p1;
    struct gs_fixed_point p2;
};

struct subpath {
    struct segment seg;
};

struct gx_path {
    struct subpath *first_subpath;
};

struct gx_device {
    // 设备结构体，具体内容根据实际需求定义
};

struct gx_edgebuffer {
    int *index;
    int *table;
    fixed base;
    int height;
    fixed xmin;
    fixed xmax;
};

struct cursor {
    int scanlines;
    int *index;
    int *table;
    fixed base;
    fixed left;
    fixed right;
    fixed y;
    int d;
    int first;
    int saved;
};

enum {
    DIRN_UNSET,
    s_start,
    s_dash,
    s_curve,
    s_gap,
    s_line,
    s_line_close
};

typedef struct gx_device gx_device;
typedef struct gx_path gx_path;
typedef struct gs_fixed_rect gs_fixed_rect;
typedef struct gx_edgebuffer gx_edgebuffer;
typedef struct cursor cursor;
typedef struct subpath subpath;
typedef struct segment segment;
typedef struct curve_segment curve_segment;

int make_bbox(struct gx_path *path, const struct gs_fixed_rect *clip, struct gs_fixed_rect *ibox, int flag);
int make_table_app(struct gx_device *pdev, struct gx_path *path, struct gs_fixed_rect *ibox, int *scanlines, int **index, int **table);
void mark_curve_app(struct cursor *cr, fixed sx, fixed sy, fixed p1x, fixed p1y, fixed p2x, fixed p2y, fixed ex, fixed ey, int k);
void mark_line_app(struct cursor *cr, fixed sx, fixed sy, fixed ex, fixed ey);
void cursor_flush(struct cursor *cr, fixed ex);
int gx_curve_log2_samples(fixed sx, fixed sy, const struct curve_segment *pcur, fixed fixed_flat);
int edgecmp(const void *a, const void *b);