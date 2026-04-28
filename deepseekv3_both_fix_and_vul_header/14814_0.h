#include <stdlib.h>

typedef unsigned char guchar;
typedef int gboolean;
typedef enum {
    PIXOPS_INTERP_NEAREST
} PixopsInterpType;

typedef struct {
    int n;
    double *weights;
} PixopsFilterDimension;

typedef struct {
    PixopsFilterDimension x;
    PixopsFilterDimension y;
    double overall_alpha;
} PixopsFilter;

typedef void (*PixopsLineFunc)(guchar *, const guchar *, int, int, int, int, int, int, const PixopsFilter *, int);

void pixops_scale_nearest(guchar *, int, int, int, int, int, int, gboolean, const guchar *, int, int, int, int, gboolean, double, double);
int make_weights(PixopsFilter *, PixopsInterpType, double, double);
void pixops_process(guchar *, int, int, int, int, int, int, gboolean, const guchar *, int, int, int, int, gboolean, double, double, int, int, int, int, int, const PixopsFilter *, PixopsLineFunc, void (*)(guchar *, const guchar *, int, int, int, int, int, int, const PixopsFilter *, int));
void scale_line_22_33(guchar *, const guchar *, int, int, int, int, int, int, const PixopsFilter *, int);
void scale_line(guchar *, const guchar *, int, int, int, int, int, int, const PixopsFilter *, int);
void scale_pixel(guchar *, const guchar *, int, int, int, int, int, int, const PixopsFilter *, int);