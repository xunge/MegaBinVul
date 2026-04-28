#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int x;
    int y;
} ASS_Vector;

typedef struct {
    ASS_Vector *points;
    size_t n_points;
    size_t max_points;
    int *segments;
    size_t n_segments;
    size_t max_segments;
} ASS_Outline;

typedef struct {
    ASS_Outline *result[2];
    int contour_first[2];
    int xbord;
    int ybord;
    double xscale;
    double yscale;
    int eps;
    bool contour_start;
    double merge_cos;
    double split_cos;
    double min_len;
    double err_q;
    double err_c;
    double err_a;
    ASS_Vector last_point;
} StrokerState;

#define OUTLINE_MIN (-32768)
#define OUTLINE_MAX (32767)
#define OUTLINE_COUNT_MASK 0x0F
#define OUTLINE_CONTOUR_END 0x10
#define OUTLINE_LINE_SEGMENT 1
#define OUTLINE_QUADRATIC_SPLINE 2
#define OUTLINE_CUBIC_SPLINE 3

void outline_alloc(ASS_Outline *outline, size_t n_points, size_t n_segments);
bool add_line(StrokerState *str, ASS_Vector end, int dir);
bool add_quadratic(StrokerState *str, ASS_Vector control, ASS_Vector end, int dir);
bool add_cubic(StrokerState *str, ASS_Vector control1, ASS_Vector control2, ASS_Vector end, int dir);
bool close_contour(StrokerState *str, int dir);