#include <stddef.h>
#include <stdlib.h>

#define SUBSAMPLE 2

typedef struct {
    int n;
    double *weights;
} PixopsFilterDimension;

typedef struct {
    PixopsFilterDimension x;
    PixopsFilterDimension y;
    double overall_alpha;
} PixopsFilter;

void correct_total(int *pixel_weights, int n_x, int n_y, int total, double overall_alpha);

static int *g_try_new(size_t count) {
    return malloc(sizeof(int) * count);
}

typedef size_t gsize;

#define g_try_new(type, count) g_try_new(count)