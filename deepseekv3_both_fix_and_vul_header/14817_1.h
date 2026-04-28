#include <math.h>
#include <stdlib.h>

#define SUBSAMPLE 256
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct {
    int n;
    int offset;
    double *weights;
} PixopsFilterDimension;