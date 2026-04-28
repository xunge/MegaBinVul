#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>

#define MAX_PATH 256
#define MAX_SLICES 1024

typedef enum {
    CLRSPC_GRAY
} OPJ_COLOR_SPACE;

typedef struct {
    int x0, y0, z0;
    int w, h, l;
    int prec;
    int bpp;
    int sgnd;
    int bigendian;
    int dcoffset;
    int dx, dy, dz;
} opj_volume_cmptparm_t;

typedef struct {
    int prec;
    int bpp;
    int sgnd;
    int *data;
} opj_volume_comp_t;

typedef struct {
    int x0, y0, z0;
    int x1, y1, z1;
    OPJ_COLOR_SPACE color_space;
    opj_volume_comp_t *comps;
} opj_volume_t;

typedef struct {
    int volume_offset_x0;
    int volume_offset_y0;
    int volume_offset_z0;
    int subsampling_dx;
    int subsampling_dy;
    int subsampling_dz;
    int dcoffset;
} opj_cparameters_t;

opj_volume_t* opj_volume_create(int numcomps, opj_volume_cmptparm_t *cmptparm, OPJ_COLOR_SPACE color_space);
unsigned char readuchar(FILE *f);
unsigned short readushort(FILE *f, int bigendian);
unsigned int readuint(FILE *f, int bigendian);
int int_floorlog2(int a);