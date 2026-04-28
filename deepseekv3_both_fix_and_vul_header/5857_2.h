#include <math.h>
#include <stdlib.h>

#define SUBSAMPLE 256
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int n;
    int offset;
    double *weights;
} PixopsFilterDimension;

#define g_new(type, count) ((type*)malloc(sizeof(type) * (count)))