#include <stdint.h>

typedef uint32_t OPJ_UINT32;

typedef struct opj_image_comp_t {
    OPJ_UINT32 prec;
} opj_image_comp_t;

typedef struct opj_tcd_resolution_t {
    OPJ_UINT32 x0, x1, y0, y1;
} opj_tcd_resolution_t;

typedef struct opj_tcd_tilecomp_t {
    opj_tcd_resolution_t* resolutions;
    OPJ_UINT32 minimum_num_resolutions;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_tile_t {
    opj_tcd_tilecomp_t* comps;
} opj_tcd_tile_t;

typedef struct opj_tcd_image_t {
    opj_tcd_tile_t* tiles;
} opj_tcd_image_t;

typedef struct opj_image_t {
    opj_image_comp_t* comps;
    OPJ_UINT32 numcomps;
} opj_image_t;

typedef struct opj_tcd_t {
    opj_tcd_image_t* tcd_image;
    opj_image_t* image;
} opj_tcd_t;