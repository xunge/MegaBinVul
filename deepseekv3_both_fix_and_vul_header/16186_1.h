#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define OUTLINE_MAX 10000

typedef struct {
    int x;
    int y;
} ASS_Vector;

typedef struct {
    ASS_Vector *points;
    size_t n_points;
    size_t max_points;
} ASS_Outline;

#define ASS_REALLOC_ARRAY(ptr, size) \
    ((ptr) = realloc((ptr), (size) * sizeof(*(ptr)))) != NULL

bool outline_add_segment(ASS_Outline *outline, char segment);