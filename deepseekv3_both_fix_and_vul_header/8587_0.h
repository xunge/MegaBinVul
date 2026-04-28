#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef enum {
    OPJ_CLRSPC_UNKNOWN = -1,
    OPJ_CLRSPC_UNSPECIFIED = 0,
    OPJ_CLRSPC_SRGB = 1,
    OPJ_CLRSPC_GRAY = 2,
    OPJ_CLRSPC_SYCC = 3
} OPJ_COLOR_SPACE;

typedef unsigned int OPJ_UINT32;
typedef int OPJ_INT32;

struct pnm_header {
    int ok;
    int format;
    int width;
    int height;
    int maxval;
    int depth;
    int gray;
    int graya;
    int rgb;
    int rgba;
    int bw;
};

typedef struct {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 prec;
    OPJ_UINT32 bpp;
    OPJ_UINT32 sgnd;
    OPJ_INT32 *data;
} opj_image_comp_t;

typedef struct {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numcomps;
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
    OPJ_UINT32 prec;
    OPJ_UINT32 bpp;
    OPJ_UINT32 sgnd;
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
} opj_image_cmptparm_t;

opj_image_t* opj_image_create(OPJ_UINT32 numcomps, opj_image_cmptparm_t *cmptparm, OPJ_COLOR_SPACE color_space);
void opj_image_destroy(opj_image_t *image);
int read_pnm_header(FILE *fp, struct pnm_header *header_info);
int has_prec(int maxval);