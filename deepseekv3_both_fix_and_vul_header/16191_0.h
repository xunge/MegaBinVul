#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define OUTLINE_MAX INT32_MAX
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int x;
    int y;
} ASS_Vector;

typedef struct {
    ASS_Vector *points;
    size_t n_points;
    uint8_t *segments;
    size_t n_segments;
} ASS_Outline;

void outline_clear(ASS_Outline *outline);
bool outline_alloc(ASS_Outline *outline, size_t n_points, size_t n_segments);
void outline_free(ASS_Outline *outline);