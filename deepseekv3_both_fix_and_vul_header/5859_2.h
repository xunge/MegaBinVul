#include <math.h>
#include <stdlib.h>

#define SUBSAMPLE 256

typedef struct {
    int n;
    int offset;
    double *weights;
} PixopsFilterDimension;

static inline double MIN(double a, double b) {
    return a < b ? a : b;
}

#define g_new(type, size) ((type*)malloc(sizeof(type) * (size)))