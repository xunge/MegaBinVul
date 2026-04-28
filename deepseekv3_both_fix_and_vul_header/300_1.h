#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef float OPJ_FLOAT32;
typedef size_t OPJ_SIZE_T;
typedef unsigned char OPJ_BYTE;
typedef int OPJ_BOOL;
#define OPJ_TRUE 1
#define OPJ_FALSE 0
#define INLINE inline

typedef struct opj_tcd_t {
    struct opj_cp_t *cp;
    struct opj_tcd_image_t *tcd_image;
    struct opj_image_t *image;
    OPJ_BOOL m_is_decoder;
} opj_tcd_t;

typedef struct opj_tcd_image_t {
    struct opj_tcd_tile_t *tiles;
} opj_tcd_image_t;

typedef struct opj_cp_t {
    struct opj_tcp_t *tcps;
    OPJ_UINT32 tw;
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    struct {
        struct {
            OPJ_UINT32 m_reduce;
        } m_dec;
    } m_specific_param;
} opj_cp_t;

typedef struct opj_tcp_t {
    struct opj_tccp_t *tccps;
    OPJ_UINT32 numresolutions;
} opj_tcp_t;

typedef struct opj_tccp_t {
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 prcw[32];
    OPJ_UINT32 prch[32];
    OPJ_UINT32 qmfbid;
    struct opj_stepsize_t *stepsizes;
    OPJ_UINT32 cblkw;
    OPJ_UINT32 cblkh;
    OPJ_UINT32 numgbits;
} opj_tccp_t;

typedef struct opj_tcd_tile_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numcomps;
    struct opj_tcd_tilecomp_t *comps;
} opj_tcd_tile_t;

typedef struct opj_tcd_tilecomp_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 minimum_num_resolutions;
    OPJ_UINT32 data_size_needed;
    struct opj_tcd_resolution_t *resolutions;
    OPJ_UINT32 resolutions_size;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_resolution_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 pw;
    OPJ_UINT32 ph;
    OPJ_UINT32 numbands;
    struct opj_tcd_band_t *bands;
} opj_tcd_resolution_t;

typedef struct opj_tcd_band_t {
    OPJ_UINT32 bandno;
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_FLOAT32 stepsize;
    OPJ_INT32 numbps;
    struct opj_tcd_precinct_t *precincts;
    OPJ_UINT32 precincts_data_size;
} opj_tcd_band_t;

typedef struct opj_tcd_precinct_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 cw;
    OPJ_UINT32 ch;
    union {
        void *blocks;
        struct opj_tcd_cblk_enc_t *enc;
        struct opj_tcd_cblk_dec_t *dec;
    } cblks;
    OPJ_UINT32 block_size;
    struct opj_tgt_tree *incltree;
    struct opj_tgt_tree *imsbtree;
} opj_tcd_precinct_t;

typedef struct opj_tcd_cblk_enc_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
} opj_tcd_cblk_enc_t;

typedef struct opj_tcd_cblk_dec_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
} opj_tcd_cblk_dec_t;

typedef struct opj_stepsize_t {
    OPJ_UINT32 expn;
    OPJ_UINT32 mant;
} opj_stepsize_t;

typedef struct opj_image_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    struct opj_image_comp_t *comps;
} opj_image_t;

typedef struct opj_image_comp_t {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 prec;
    OPJ_UINT32 resno_decoded;
} opj_image_comp_t;

typedef struct opj_tgt_tree {
    // Implementation details not shown
} opj_tgt_tree;

static INLINE OPJ_UINT32 opj_dwt_getgain_real(OPJ_UINT32 orient) { return 0; }
static INLINE OPJ_UINT32 opj_dwt_getgain(OPJ_UINT32 orient) { return 0; }
static INLINE OPJ_INT32 opj_int_max(OPJ_INT32 a, OPJ_INT32 b) { return (a > b) ? a : b; }
static INLINE OPJ_INT32 opj_int_min(OPJ_INT32 a, OPJ_INT32 b) { return (a < b) ? a : b; }
static INLINE OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b) { return (a + b - 1) / b; }
static INLINE OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b) { return (a + (1 << b) - 1) >> b; }
static INLINE OPJ_INT32 opj_int_floordivpow2(OPJ_INT32 a, OPJ_INT32 b) { return a >> b; }
static INLINE OPJ_UINT32 opj_uint_min(OPJ_UINT32 a, OPJ_UINT32 b) { return (a < b) ? a : b; }
static OPJ_BOOL opj_alloc_tile_component_data(opj_tcd_tilecomp_t *tilec) { return OPJ_TRUE; }
static void* opj_malloc(OPJ_SIZE_T size) { return malloc(size); }
static void* opj_realloc(void* ptr, OPJ_SIZE_T size) { return realloc(ptr, size); }
static void opj_free(void* ptr) { free(ptr); }
static opj_tgt_tree* opj_tgt_create(OPJ_UINT32 numleafsh, OPJ_UINT32 numleafsv) { return NULL; }
static opj_tgt_tree* opj_tgt_init(opj_tgt_tree *tree, OPJ_UINT32 numleafsh, OPJ_UINT32 numleafsv) { return NULL; }
static OPJ_BOOL opj_tcd_code_block_enc_allocate(opj_tcd_cblk_enc_t* block) { return OPJ_TRUE; }
static OPJ_BOOL opj_tcd_code_block_enc_allocate_data(opj_tcd_cblk_enc_t* block) { return OPJ_TRUE; }
static OPJ_BOOL opj_tcd_code_block_dec_allocate(opj_tcd_cblk_dec_t* block) { return OPJ_TRUE; }