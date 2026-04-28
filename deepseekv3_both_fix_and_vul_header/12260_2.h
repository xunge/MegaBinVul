#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int OPJ_BOOL;
typedef unsigned int OPJ_UINT32;
typedef int OPJ_INT32;
typedef long long OPJ_INT64;
typedef float OPJ_FLOAT32;
typedef size_t OPJ_SIZE_T;
typedef unsigned char OPJ_BYTE;

#define INLINE inline
#define OPJ_TRUE 1
#define OPJ_FALSE 0
#define EVT_ERROR 1
#define EVT_WARNING 2
#define EVT_INFO 3

typedef struct opj_event_mgr {
    void (*opj_event_msg)(struct opj_event_mgr*, int, const char*);
} opj_event_mgr_t;

typedef struct opj_image_comp {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 prec;
    OPJ_UINT32 resno_decoded;
} opj_image_comp_t;

typedef struct opj_image {
    OPJ_UINT32 x0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y0;
    OPJ_UINT32 y1;
    opj_image_comp_t* comps;
} opj_image_t;

typedef struct opj_stepsize {
    OPJ_UINT32 expn;
    OPJ_UINT32 mant;
} opj_stepsize_t;

typedef struct opj_tccp {
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 cblkw;
    OPJ_UINT32 cblkh;
    OPJ_UINT32 qmfbid;
    OPJ_UINT32 numgbits;
    OPJ_UINT32* prcw;
    OPJ_UINT32* prch;
    opj_stepsize_t* stepsizes;
} opj_tccp_t;

typedef struct opj_tcp {
    opj_tccp_t* tccps;
} opj_tcp_t;

typedef struct opj_cp {
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    OPJ_UINT32 tw;
    OPJ_UINT32 th;
    struct {
        struct {
            OPJ_UINT32 m_reduce;
        } m_dec;
    } m_specific_param;
    opj_tcp_t* tcps;
} opj_cp_t;

typedef struct opj_tcd_resolution {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 pw;
    OPJ_UINT32 ph;
    OPJ_UINT32 numbands;
    struct opj_tcd_band* bands;
} opj_tcd_resolution_t;

typedef struct opj_tcd_band {
    OPJ_UINT32 bandno;
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_FLOAT32 stepsize;
    OPJ_INT32 numbps;
    struct opj_tcd_precinct* precincts;
    OPJ_UINT32 precincts_data_size;
} opj_tcd_band_t;

typedef struct opj_tcd_cblk_enc {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
} opj_tcd_cblk_enc_t;

typedef struct opj_tcd_cblk_dec {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
} opj_tcd_cblk_dec_t;

typedef union opj_tcd_cblk {
    opj_tcd_cblk_enc_t* enc;
    opj_tcd_cblk_dec_t* dec;
    void* blocks;
} opj_tcd_cblk_t;

typedef struct opj_tcd_precinct {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 cw;
    OPJ_UINT32 ch;
    opj_tcd_cblk_t cblks;
    OPJ_UINT32 block_size;
    void* incltree;
    void* imsbtree;
} opj_tcd_precinct_t;

typedef struct opj_tcd_tilecomp {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 minimum_num_resolutions;
    OPJ_UINT32 data_size_needed;
    opj_tcd_resolution_t* resolutions;
    OPJ_UINT32 resolutions_size;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_tile {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numcomps;
    opj_tcd_tilecomp_t* comps;
} opj_tcd_tile_t;

typedef struct opj_tcd_image {
    opj_tcd_tile_t* tiles;
} opj_tcd_image_t;

typedef struct opj_tcd {
    OPJ_BOOL m_is_decoder;
    opj_cp_t* cp;
    opj_image_t* image;
    opj_tcd_image_t* tcd_image;
} opj_tcd_t;

static OPJ_UINT32 opj_dwt_getgain(OPJ_UINT32 bandno);
static OPJ_UINT32 opj_dwt_getgain_real(OPJ_UINT32 bandno);
static OPJ_UINT32 opj_uint_adds(OPJ_UINT32 a, OPJ_UINT32 b);
static OPJ_UINT32 opj_uint_min(OPJ_UINT32 a, OPJ_UINT32 b);
static OPJ_UINT32 opj_uint_max(OPJ_UINT32 a, OPJ_UINT32 b);
static OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b);
static OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b);
static OPJ_INT32 opj_int_floordivpow2(OPJ_INT32 a, OPJ_INT32 b);
static OPJ_INT32 opj_int64_ceildivpow2(OPJ_INT64 a, OPJ_INT32 b);
static OPJ_INT32 opj_int_max(OPJ_INT32 a, OPJ_INT32 b);
static OPJ_INT32 opj_int_min(OPJ_INT32 a, OPJ_INT32 b);
static void* opj_malloc(OPJ_SIZE_T size);
static void* opj_realloc(void* ptr, OPJ_SIZE_T size);
static void opj_free(void* ptr);
static OPJ_BOOL opj_alloc_tile_component_data(opj_tcd_tilecomp_t* tilec);
static OPJ_BOOL opj_tcd_code_block_enc_allocate(opj_tcd_cblk_enc_t* cblk);
static OPJ_BOOL opj_tcd_code_block_enc_allocate_data(opj_tcd_cblk_enc_t* cblk);
static OPJ_BOOL opj_tcd_code_block_dec_allocate(opj_tcd_cblk_dec_t* cblk);
static void* opj_tgt_create(OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager);
static void* opj_tgt_init(void* tgt, OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager);

static void opj_event_msg(opj_event_mgr_t* manager, int event_type, const char* msg) {
    if (manager && manager->opj_event_msg) {
        manager->opj_event_msg(manager, event_type, msg);
    }
}