#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUBSAMPLE 256
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define FALSE false
#define TRUE true

typedef bool gboolean;

typedef struct {
    int n;
    int offset;
    double *weights;
} PixopsFilterDimension;

static void* g_try_malloc_n(size_t size, size_t n) {
    return calloc(n, size);
}