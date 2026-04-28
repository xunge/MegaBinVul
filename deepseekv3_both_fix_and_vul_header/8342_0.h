#include <stdint.h>

typedef int OPJ_BOOL;
typedef uint8_t OPJ_BYTE;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef int16_t OPJ_INT16;
typedef char OPJ_CHAR;

#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef struct opj_image_comp {
    uint32_t prec;
    OPJ_BOOL sgnd;
    uint32_t resno_decoded;
} opj_image_comp_t;

typedef struct opj_tcd_resolution {
    uint32_t x0, x1, y0, y1;
} opj_tcd_resolution_t;

typedef struct opj_tcd_tilecomp {
    uint32_t x0, x1;
    opj_tcd_resolution_t* resolutions;
    OPJ_INT32* data;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_tile {
    opj_tcd_tilecomp_t* comps;
} opj_tcd_tile_t;

typedef struct opj_tcd_image {
    opj_tcd_tile_t* tiles;
} opj_tcd_image_t;

typedef struct opj_image {
    opj_image_comp_t* comps;
    uint32_t numcomps;
} opj_image_t;

typedef struct opj_tcd {
    opj_tcd_image_t* tcd_image;
    opj_image_t* image;
} opj_tcd_t;

OPJ_UINT32 opj_tcd_get_decoded_tile_size(opj_tcd_t *p_tcd);