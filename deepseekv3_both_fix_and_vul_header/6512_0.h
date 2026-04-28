#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int w;
    int h;
    int prec;
    int sgnd;
    int *data;
} opj_image_comp_t;

typedef struct {
    int numcomps;
    opj_image_comp_t *comps;
} opj_image_t;

const char* opj_version(void);
int are_comps_similar(opj_image_t *image);