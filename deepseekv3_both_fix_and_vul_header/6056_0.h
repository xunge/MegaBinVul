#include <math.h>

typedef struct _VipsPoint {
    int width;
    int height;
} VipsPoint;

typedef struct _VipsEye {
    VipsPoint point;
    double factor;
} VipsEye;

#define VIPS_PI 3.14159265358979323846