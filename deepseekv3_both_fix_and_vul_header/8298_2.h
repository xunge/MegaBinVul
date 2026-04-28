#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef int64_t OPJ_INT64;
typedef uint64_t OPJ_UINT64;
typedef uint8_t OPJ_BYTE;
typedef float OPJ_FLOAT32;
typedef size_t OPJ_SIZE_T;
typedef int OPJ_BOOL;

#define OPJ_TRUE 1
#define OPJ_FALSE 0
#define INLINE inline
#define EVT_ERROR 1
#define EVT_WARNING 2

typedef struct opj_tcd_cblk_enc_t {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
} opj_tcd_cblk_enc_t;

typedef struct opj_tcd_cblk_dec_t {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
} opj_tcd_cblk_dec_t;

typedef union opj_tcd_cblk_t {
    opj_tcd_cblk_enc_t *enc;
    opj_tcd_cblk_dec_t *dec;
    void *blocks;
} opj_tcd_cblk_t;

typedef struct opj_tgt_tree_t {
    OPJ_UINT32 w;
    OPJ_UINT32 h;
} opj_tgt_tree_t;

typedef struct opj_tcd_precinct_t {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 cw;
    OPJ_UINT32 ch;
    OPJ_UINT32 block_size;
    opj_tcd_cblk_t cblks;
    opj_tgt_tree_t *incltree;
    opj_tgt_tree_t *imsbtree;
} opj_tcd_precinct_t;

typedef struct opj_stepsize_t {
    OPJ_UINT32 mant;
    OPJ_UINT32 expn;
} opj_stepsize_t;

typedef struct opj_tcd_band_t {
    OPJ_UINT32 bandno;
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_FLOAT32 stepsize;
    OPJ_INT32 numbps;
    OPJ_UINT32 precincts_data_size;
    opj_tcd_precinct_t *precincts;
} opj_tcd_band_t;

typedef struct opj_tcd_resolution_t {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 pw;
    OPJ_UINT32 ph;
    OPJ_UINT32 numbands;
    opj_tcd_band_t *bands;
} opj_tcd_resolution_t;

typedef struct opj_image_comp_t {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 prec;
    OPJ_UINT32 resno_decoded;
} opj_image_comp_t;

typedef struct opj_tcd_tilecomp_t {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 minimum_num_resolutions;
    OPJ_UINT32 data_size_needed;
    OPJ_UINT32 resolutions_size;
    opj_tcd_resolution_t *resolutions;
} opj_tcd_tilecomp_t;

typedef struct opj_tccp_t {
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 prcw[32];
    OPJ_UINT32 prch[32];
    OPJ_UINT32 cblkw;
    OPJ_UINT32 cblkh;
    OPJ_UINT32 qmfbid;
    OPJ_UINT32 numgbits;
    opj_stepsize_t *stepsizes;
} opj_tccp_t;

typedef struct opj_tcp_t {
    opj_tccp_t *tccps;
} opj_tcp_t;

typedef struct opj_dec_specific_param_t {
    OPJ_UINT32 m_reduce;
} opj_dec_specific_param_t;

typedef struct opj_specific_param_t {
    opj_dec_specific_param_t m_dec;
} opj_specific_param_t;

typedef struct opj_cp_t {
    OPJ_UINT32 tw;
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    opj_tcp_t *tcps;
    opj_specific_param_t m_specific_param;
} opj_cp_t;

typedef struct opj_tcd_tile_t {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 numcomps;
    opj_tcd_tilecomp_t *comps;
} opj_tcd_tile_t;

typedef struct opj_image_t {
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    opj_image_comp_t *comps;
} opj_image_t;

typedef struct opj_tcd_image_t {
    opj_tcd_tile_t *tiles;
} opj_tcd_image_t;

typedef struct opj_event_mgr_t {
    void (*opj_event_msg)(struct opj_event_mgr_t*, int, const char*);
} opj_event_mgr_t;

typedef struct opj_tcd_t {
    opj_cp_t *cp;
    opj_tcd_image_t *tcd_image;
    opj_image_t *image;
    OPJ_BOOL m_is_decoder;
} opj_tcd_t;

static INLINE OPJ_UINT32 opj_uint_adds(OPJ_UINT32 a, OPJ_UINT32 b) {
    OPJ_UINT64 sum = (OPJ_UINT64)a + (OPJ_UINT64)b;
    return (OPJ_UINT32)(sum > 0xFFFFFFFFU ? 0xFFFFFFFFU : sum);
}

static INLINE OPJ_UINT32 opj_uint_max(OPJ_UINT32 a, OPJ_UINT32 b) {
    return (a > b) ? a : b;
}

static INLINE OPJ_UINT32 opj_uint_min(OPJ_UINT32 a, OPJ_UINT32 b) {
    return (a < b) ? a : b;
}

static INLINE OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b) {
    return (a + b - 1) / b;
}

static INLINE OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b) {
    return (a + (1 << b) - 1) >> b;
}

static INLINE OPJ_INT32 opj_int_floordivpow2(OPJ_INT32 a, OPJ_INT32 b) {
    return a >> b;
}

static INLINE OPJ_INT32 opj_int_max(OPJ_INT32 a, OPJ_INT32 b) {
    return (a > b) ? a : b;
}

static INLINE OPJ_INT32 opj_int_min(OPJ_INT32 a, OPJ_INT32 b) {
    return (a < b) ? a : b;
}

static INLINE OPJ_INT64 opj_int64_ceildivpow2(OPJ_INT64 a, OPJ_INT32 b) {
    return (a + ((OPJ_INT64)1 << b) - 1) >> b;
}

static INLINE OPJ_UINT32 opj_dwt_getgain(OPJ_UINT32 orient) {
    return 0;
}

static INLINE OPJ_UINT32 opj_dwt_getgain_real(OPJ_UINT32 orient) {
    return 0;
}

static INLINE void* opj_malloc(size_t size) {
    return malloc(size);
}

static INLINE void* opj_realloc(void* ptr, size_t size) {
    return realloc(ptr, size);
}

static INLINE void opj_free(void* ptr) {
    free(ptr);
}

static INLINE void opj_event_msg(opj_event_mgr_t* manager, int severity, const char* msg) {
    (void)manager;
    (void)severity;
    (void)msg;
}

static INLINE opj_tgt_tree_t* opj_tgt_create(OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager) {
    (void)w;
    (void)h;
    (void)manager;
    return NULL;
}

static INLINE opj_tgt_tree_t* opj_tgt_init(opj_tgt_tree_t* tree, OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager) {
    (void)w;
    (void)h;
    (void)manager;
    return tree;
}

static INLINE OPJ_BOOL opj_alloc_tile_component_data(opj_tcd_tilecomp_t* tilec) {
    (void)tilec;
    return OPJ_TRUE;
}

static INLINE OPJ_BOOL opj_tcd_code_block_enc_allocate(opj_tcd_cblk_enc_t* cblk) {
    (void)cblk;
    return OPJ_TRUE;
}

static INLINE OPJ_BOOL opj_tcd_code_block_enc_allocate_data(opj_tcd_cblk_enc_t* cblk) {
    (void)cblk;
    return OPJ_TRUE;
}

static INLINE OPJ_BOOL opj_tcd_code_block_dec_allocate(opj_tcd_cblk_dec_t* cblk) {
    (void)cblk;
    return OPJ_TRUE;
}