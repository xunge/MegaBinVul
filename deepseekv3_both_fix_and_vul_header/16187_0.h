#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

#define OUTLINE_MAX 1e9
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int x, y;
} ASS_Vector;

typedef struct {
    ASS_Vector *points;
    size_t n_points;
    size_t n_segments;
    int *segments;
} ASS_Outline;

void outline_clear(ASS_Outline *outline);
bool outline_alloc(ASS_Outline *outline, size_t n_points, size_t n_segments);
void outline_free(ASS_Outline *outline);