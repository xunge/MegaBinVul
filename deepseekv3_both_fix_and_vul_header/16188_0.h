#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int x;
    int y;
} ASS_Vector;

typedef struct {
    ASS_Vector *points;
    size_t n_points;
    int *segments;
    size_t n_segments;
} ASS_Outline;

typedef struct {
    short x;
    short y;
    char tag;
} FT_Vector;

typedef struct {
    int n_points;
    int n_contours;
    FT_Vector *points;
    char *tags;
    short *contours;
} FT_Outline;

#define FT_CURVE_TAG(t) ((t) & 0x03)
#define FT_CURVE_TAG_ON      1
#define FT_CURVE_TAG_CONIC   0
#define FT_CURVE_TAG_CUBIC   2

#define OUTLINE_LINE_SEGMENT 0
#define OUTLINE_QUADRATIC_SPLINE 1
#define OUTLINE_CUBIC_SPLINE 2
#define OUTLINE_CONTOUR_END 4

void outline_clear(ASS_Outline *outline);
bool outline_alloc(ASS_Outline *outline, size_t points, size_t segments);
void outline_free(ASS_Outline *outline);