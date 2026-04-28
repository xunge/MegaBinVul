#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {
    PIXOPS_INTERP_NEAREST,
    PIXOPS_INTERP_TILES,
    PIXOPS_INTERP_BILINEAR,
    PIXOPS_INTERP_HYPER
} PixopsInterpType;

typedef struct {
    double *weights;
} PixopsFilterDim;

typedef struct {
    PixopsFilterDim x;
    PixopsFilterDim y;
} PixopsFilter;

#define gboolean bool
#define FALSE false
#define TRUE true
#define g_assert_not_reached() (assert(0))
#define g_free(ptr) (free(ptr))

static bool tile_make_weights(PixopsFilterDim *filter, double scale);
static bool bilinear_magnify_make_weights(PixopsFilterDim *filter, double scale);
static bool bilinear_box_make_weights(PixopsFilterDim *filter, double scale);