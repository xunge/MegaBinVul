#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

#define OUTLINE_MIN 0
#define OUTLINE_MAX 0
#define OUTLINE_COUNT_MASK 0x3
#define OUTLINE_CONTOUR_END 0x4
#define OUTLINE_LINE_SEGMENT 1
#define OUTLINE_QUADRATIC_SPLINE 2
#define OUTLINE_CUBIC_SPLINE 3

typedef struct ASS_Vector {
    int x;
    int y;
} ASS_Vector;

typedef struct ASS_Outline {
    ASS_Vector *points;
    size_t n_points;
    int *segments;
    size_t n_segments;
} ASS_Outline;

typedef struct RasterizerData {
    int n_first;
    size_t size[1];
    struct segment {
        int x_min;
        int y_min;
        int x_max;
        int y_max;
    } *linebuf[1];
    struct {
        int x_min;
        int y_min;
        int x_max;
        int y_max;
    } bbox;
} RasterizerData;

void rectangle_reset(void *bbox);
bool add_line(RasterizerData *rst, ASS_Vector p1, ASS_Vector p2);
bool add_quadratic(RasterizerData *rst, ASS_Vector p[3]);
bool add_cubic(RasterizerData *rst, ASS_Vector p[4]);
void rectangle_update(void *bbox, int x1, int y1, int x2, int y2);