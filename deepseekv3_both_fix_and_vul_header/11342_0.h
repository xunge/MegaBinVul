#include <stdio.h>
#include <stdlib.h>

typedef int OPJ_BOOL;
#define OPJ_TRUE 1

typedef struct {
    int dx;
    int dy;
    int prec;
    int w;
    int h;
    int sgnd;
    int *data;
} opj_image_comp_t;

typedef struct {
    int numcomps;
    opj_image_comp_t *comps;
} opj_image_t;

int tga_writeheader(FILE *fdest, int bpp, int width, int height, OPJ_BOOL flip);