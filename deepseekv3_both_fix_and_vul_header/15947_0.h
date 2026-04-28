#include <stdio.h>
#include <stdlib.h>

typedef struct opj_image_comp {
    int dx;
    int dy;
    int w;
    int h;
    int prec;
    int sgnd;
    int *data;
} opj_image_comp_t;

typedef struct opj_image {
    int numcomps;
    opj_image_comp_t *comps;
    int color_space;
} opj_image_t;

#define OPJ_CLRSPC_SRGB 1