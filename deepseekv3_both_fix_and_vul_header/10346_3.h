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
    int type;
    struct segment *next;
    struct gs_fixed_point pt;
};

struct curve_segment {
    int type;
    struct segment *next;
    struct gs_fixed_point pt;
    struct gs_fixed_point p1;
    struct gs_fixed_point p2;
};

struct subpath {
    int type;
    struct segment *next;
    struct gs_fixed_point pt;
};

struct gx_path {
    struct subpath *first_subpath;
};

struct gx_edgebuffer {
    int base;
    int height;
    int xmin;
    int xmax;
    int *index;
    int *table;
};

struct gx_device;

typedef struct gx_device gx_device;
typedef struct gx_path gx_path;
typedef struct gs_fixed_rect gs_fixed_rect;
typedef struct gx_edgebuffer gx_edgebuffer;
typedef struct subpath subpath;
typedef struct segment segment;
typedef struct curve_segment curve_segment;

#define fixed_half 0
#define s_start 0
#define s_dash 1
#define s_curve 2
#define s_gap 3
#define s_line 4
#define s_line_close 5

int make_bbox(gx_path *path, const gs_fixed_rect *clip, gs_fixed_rect *ibox, fixed flatness);
int make_table(gx_device *pdev, gx_path *path, gs_fixed_rect *ibox, int *scanlines, int **index, int **table);
void mark_curve(fixed sx, fixed sy, fixed c1x, fixed c1y, fixed c2x, fixed c2y, fixed ex, fixed ey, fixed base, int scanlines, int *table, int *index, int k);
void mark_line(fixed sx, fixed sy, fixed ex, fixed ey, fixed base, int scanlines, int *table, int *index);
int gx_curve_log2_samples(fixed sx, fixed sy, const curve_segment *pcur, fixed fixed_flat);
int intcmp(const void *a, const void *b);