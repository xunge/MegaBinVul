#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct opj_image_comp {
    int dx, dy;
    int w, h;
    int prec;
    int *data;
} opj_image_comp;

typedef struct opj_image {
    int numcomps;
    opj_image_comp *comps;
    int color_space;
} opj_image_t;

#define OPJ_CLRSPC_SRGB 1