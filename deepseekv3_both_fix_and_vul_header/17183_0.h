#include <math.h>

typedef struct {
    double x;
    double y;
} gs_point;

typedef struct {
    /* Define matrix structure members as needed */
    /* This is a placeholder - actual implementation may vary */
    double xx, xy, yx, yy, tx, ty;
} gs_matrix;

#define gs_error_undefinedresult (-1)

int gs_distance_transform_inverse(double dx, double dy, const gs_matrix *pmat, gs_point *pdist);