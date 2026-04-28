#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int32_t OPJ_INT32;
typedef int64_t OPJ_INT64;
typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;
typedef size_t OPJ_SIZE_T;
typedef unsigned char OPJ_BYTE;
typedef int OPJ_BOOL;

#define OPJ_TRUE 1
#define OPJ_FALSE 0
#define INLINE inline
#define EVT_ERROR 0
#define EVT_WARNING 1

typedef struct opj_event_mgr opj_event_mgr_t;

typedef struct opj_tcd {
    struct opj_cp *cp;
    struct opj_image *image;
    struct opj_tcd_image *tcd_image;
    OPJ_BOOL m_is_decoder;
} opj_tcd_t;

typedef struct opj_cp {
    OPJ_UINT32 tx0, ty0;
    OPJ_UINT32 tdx, tdy;
    OPJ_UINT32 tw;
    struct opj_tcp *tcps;
    struct {
        struct {
            OPJ_UINT32 m_reduce;
        } m_dec;
    } m_specific_param;
} opj_cp_t;

typedef struct opj_tcp {
    struct opj_tccp *tccps;
} opj_tcp_t;

typedef struct opj_tccp {
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 qmfbid;
    OPJ_UINT32 cblkw;
    OPJ_UINT32 cblkh;
    OPJ_UINT32 numgbits;
    OPJ_UINT32 *prcw;
    OPJ_UINT32 *prch;
    struct opj_stepsize *stepsizes;
} opj_tccp_t;

typedef struct opj_stepsize {
    OPJ_INT32 expn;
    OPJ_UINT32 mant;
} opj_stepsize_t;

typedef struct opj_image {
    OPJ_INT32 x0, y0, x1, y1;
    struct opj_image_comp *comps;
} opj_image_t;

typedef struct opj_image_comp {
    OPJ_UINT32 dx, dy;
    OPJ_UINT32 prec;
    OPJ_UINT32 resno_decoded;
} opj_image_comp_t;

typedef struct opj_tcd_image {
    struct opj_tcd_tile *tiles;
} opj_tcd_image_t;

typedef struct opj_tcd_tile {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 numcomps;
    struct opj_tcd_tilecomp *comps;
} opj_tcd_tile_t;

typedef struct opj_tcd_tilecomp {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 minimum_num_resolutions;
    OPJ_UINT32 data_size_needed;
    OPJ_UINT32 resolutions_size;
    struct opj_tcd_resolution *resolutions;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_resolution {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 pw, ph;
    OPJ_UINT32 numbands;
    struct opj_tcd_band *bands;
} opj_tcd_resolution_t;

typedef struct opj_tcd_band {
    OPJ_UINT32 bandno;
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_FLOAT32 stepsize;
    OPJ_INT32 numbps;
    OPJ_UINT32 precincts_data_size;
    struct opj_tcd_precinct *precincts;
} opj_tcd_band_t;

typedef struct opj_tcd_precinct {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 cw, ch;
    OPJ_UINT32 block_size;
    union {
        struct opj_tcd_cblk_enc *enc;
        struct opj_tcd_cblk_dec *dec;
        void *blocks;
    } cblks;
    struct opj_tgt_tree *incltree;
    struct opj_tgt_tree *imsbtree;
} opj_tcd_precinct_t;

typedef struct opj_tcd_cblk_enc {
    OPJ_INT32 x0, y0, x1, y1;
} opj_tcd_cblk_enc_t;

typedef struct opj_tcd_cblk_dec {
    OPJ_INT32 x0, y0, x1, y1;
} opj_tcd_cblk_dec_t;

typedef struct opj_tgt_tree opj_tgt_tree_t;

static INLINE OPJ_UINT32 opj_uint_adds(OPJ_UINT32 a, OPJ_UINT32 b) { return a + b; }
static INLINE OPJ_UINT32 opj_uint_max(OPJ_UINT32 a, OPJ_UINT32 b) { return (a > b) ? a : b; }
static INLINE OPJ_UINT32 opj_uint_min(OPJ_UINT32 a, OPJ_UINT32 b) { return (a < b) ? a : b; }
static INLINE OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b) { return (a + b - 1) / b; }
static INLINE OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b) { return (a + (1 << b) - 1) >> b; }
static INLINE OPJ_INT32 opj_int_floordivpow2(OPJ_INT32 a, OPJ_INT32 b) { return a >> b; }
static INLINE OPJ_INT32 opj_int_max(OPJ_INT32 a, OPJ_INT32 b) { return (a > b) ? a : b; }
static INLINE OPJ_INT32 opj_int_min(OPJ_INT32 a, OPJ_INT32 b) { return (a < b) ? a : b; }
static INLINE OPJ_INT32 opj_int64_ceildivpow2(OPJ_INT64 a, OPJ_INT32 b) { return (OPJ_INT32)((a + ((OPJ_INT64)1 << b) - 1) >> b); }

static INLINE OPJ_UINT32 opj_dwt_getgain(OPJ_UINT32 orient) { return 0; }
static INLINE OPJ_UINT32 opj_dwt_getgain_real(OPJ_UINT32 orient) { return 0; }

static INLINE void* opj_malloc(size_t size) { return malloc(size); }
static INLINE void* opj_realloc(void* ptr, size_t size) { return realloc(ptr, size); }
static INLINE void opj_free(void* ptr) { free(ptr); }

static INLINE void opj_event_msg(opj_event_mgr_t* manager, int level, const char* msg) {}

static INLINE OPJ_BOOL opj_alloc_tile_component_data(opj_tcd_tilecomp_t* tilec) { return OPJ_TRUE; }
static INLINE OPJ_BOOL opj_tcd_code_block_enc_allocate(opj_tcd_cblk_enc_t* cblk) { return OPJ_TRUE; }
static INLINE OPJ_BOOL opj_tcd_code_block_enc_allocate_data(opj_tcd_cblk_enc_t* cblk) { return OPJ_TRUE; }
static INLINE OPJ_BOOL opj_tcd_code_block_dec_allocate(opj_tcd_cblk_dec_t* cblk) { return OPJ_TRUE; }

static INLINE opj_tgt_tree_t* opj_tgt_create(OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager) { return NULL; }
static INLINE opj_tgt_tree_t* opj_tgt_init(opj_tgt_tree_t* tree, OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager) { return NULL; }