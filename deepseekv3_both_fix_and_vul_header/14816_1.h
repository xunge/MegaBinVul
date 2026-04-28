#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUBSAMPLE 256

typedef struct {
    int n;
    double offset;
    double *weights;
} PixopsFilterDimension;

static double linear_box_half(double a, double b);

#define gboolean bool
#define g_malloc_n(size, n) calloc((n), (size))
#define FALSE false
#define TRUE true