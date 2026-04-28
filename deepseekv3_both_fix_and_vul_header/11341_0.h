#include <stdio.h>
#include <stdlib.h>

typedef unsigned char OPJ_UINT8;

typedef struct {
    int prec;
    int dx;
    int dy;
    int w;
    int h;
    int *data;
    int sgnd;
} opj_image_comp_t;

typedef struct {
    int numcomps;
    opj_image_comp_t *comps;
} opj_image_t;