#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int OPJ_UINT32;
typedef enum {
    OPJ_CLRSPC_GRAY,
    OPJ_CLRSPC_SRGB,
    OPJ_CLRSPC_CMYK,
    OPJ_CLRSPC_EYCC,
    OPJ_CLRSPC_CUSTOM
} OPJ_COLOR_SPACE;

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
    int *data;
} opj_image_comp_t;

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
} opj_image_cmptparm_t;

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
    int image_offset_x0;
    int image_offset_y0;
    int subsampling_dx;
    int subsampling_dy;
} opj_cparameters_t;

extern opj_image_t* opj_image_create(OPJ_UINT32 numcomps, opj_image_cmptparm_t *cmptparm, OPJ_COLOR_SPACE color_space);
extern int readuchar(FILE *f);
extern unsigned short readushort(FILE *f, int bigendian);
extern unsigned int readuint(FILE *f, int bigendian);
extern int int_floorlog2(int a);