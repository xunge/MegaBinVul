#include <stdio.h>
#include <stdlib.h>

typedef int OPJ_BOOL;

typedef struct {
    int dx;
    int dy;
    int w;
    int h;
    int prec;
    int sgnd;
    int *data;
} opj_image_comp_t;

typedef struct {
    int numcomps;
    int x1;
    int y1;
    opj_image_comp_t *comps;
} opj_image_t;