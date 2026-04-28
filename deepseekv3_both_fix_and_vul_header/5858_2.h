#include <math.h>
#include <stdlib.h>

#define SUBSAMPLE 256

typedef struct {
    int n;
    double offset;
    double *weights;
} PixopsFilterDimension;

static double linear_box_half(double a, double b)
{
    return (a > 0 ? a : 0) + (b > 0 ? b : 0);
}

#define g_new(type, size) ((type*)malloc(sizeof(type) * (size)))