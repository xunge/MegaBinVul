#include <stdio.h>
#include <string.h>

typedef struct gs_matrix_s {
    float xx, xy, yx, yy, tx, ty;
} gs_matrix;

typedef struct gx_device_vector_s gx_device_vector;

typedef struct xps_pie_s {
    char *file_name;
    char *icc_name;
    int width;
    int height;
    gs_matrix mat;
} xps_pie;

typedef struct gx_device_xps_s {
    gx_device_vector *vdev;
    xps_pie *xps_pie;
} gx_device_xps;

extern void write_str_to_current_page(gx_device_xps *xps, const char *str);