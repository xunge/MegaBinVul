#include <math.h>
#include <assert.h>

#define M_PI 3.14159265358979323846
#define MAX_FULL_CIRCLES 1000

typedef enum {
    CAIRO_DIRECTION_FORWARD,
    CAIRO_DIRECTION_REVERSE
} cairo_direction_t;

typedef struct _cairo {
    int dummy;
} cairo_t;

typedef struct {
    double xx; double xy;
    double yx; double yy;
    double x0; double y0;
} cairo_matrix_t;

int cairo_status(cairo_t *cr);
void cairo_get_matrix(cairo_t *cr, cairo_matrix_t *matrix);
double cairo_get_tolerance(cairo_t *cr);
void cairo_line_to(cairo_t *cr, double x, double y);

static int _arc_segments_needed(double angle, double radius, const cairo_matrix_t *ctm, double tolerance);
static void _cairo_arc_segment(cairo_t *cr, double xc, double yc, double radius, double angle1, double angle2);