#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

#define SUBSAMPLE 256

typedef struct {
    int n;
    double *weights;
} PixopsFilterDimension;

typedef struct {
    PixopsFilterDimension x;
    PixopsFilterDimension y;
    double overall_alpha;
} PixopsFilter;

typedef size_t gsize;

extern void correct_total(int *pixel_weights, int n_x, int n_y, int total, double overall_alpha);
extern int *g_try_new(size_t size);
extern int *g_new(size_t size);

#define g_new(type, size) ((type*)g_new(size))
#define g_try_new(type, size) ((type*)g_try_new(size))