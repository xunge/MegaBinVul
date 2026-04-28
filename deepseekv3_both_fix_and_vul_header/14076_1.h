#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef enum {
    OPJ_CLRSPC_UNKNOWN = -1,
    OPJ_CLRSPC_UNSPECIFIED = 0,
    OPJ_CLRSPC_SRGB = 1,
    OPJ_CLRSPC_GRAY = 2,
    OPJ_CLRSPC_SYCC = 3,
    OPJ_CLRSPC_EYCC = 4,
    OPJ_CLRSPC_CMYK = 5
} OPJ_COLOR_SPACE;

typedef int OPJ_BOOL;
#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef unsigned int OPJ_UINT32;
typedef unsigned long long OPJ_UINT64;

typedef struct {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    int prec;
    int bpp;
    int sgnd;
    int *data;
} opj_image_comp_t;

typedef struct {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    int numcomps;
    OPJ_COLOR_SPACE color_space;
    opj_image_comp_t *comps;
} opj_image_t;

typedef struct {
    int subsampling_dx;
    int subsampling_dy;
    int image_offset_x0;
    int image_offset_y0;
} opj_cparameters_t;

typedef struct {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    int prec;
    int bpp;
    int sgnd;
} opj_image_cmptparm_t;

opj_image_t* opj_image_create(OPJ_UINT32 numcomps, opj_image_cmptparm_t *cmptparm, OPJ_COLOR_SPACE color_space);
void opj_image_destroy(opj_image_t *image);
int tga_readheader(FILE *f, unsigned int *pixel_bit_depth, unsigned int *image_width, unsigned int *image_height, int *flip_image);