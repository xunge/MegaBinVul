#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef int OPJ_BOOL;
typedef unsigned int OPJ_UINT32;
typedef int OPJ_INT32;
typedef long long OPJ_INT64;
typedef float OPJ_FLOAT32;
typedef size_t OPJ_SIZE_T;
typedef unsigned char OPJ_BYTE;

#define INLINE inline
#define EVT_ERROR 0
#define OPJ_FALSE 0
#define OPJ_TRUE 1
#define SIZE_MAX ((size_t)-1)

typedef struct opj_tcd_t {
    struct opj_cp_t *cp;
    struct opj_image_t *image;
    struct opj_tcd_image_t *tcd_image;
} opj_tcd_t;

typedef struct opj_cp_t {
    OPJ_UINT32 tx0, ty0, tdx, tdy;
    OPJ_UINT32 tw;
    struct opj_tcp_t *tcps;
    struct {
        struct {
            OPJ_UINT32 m_reduce;
        } m_dec;
    } m_specific_param;
} opj_cp_t;

typedef struct opj_tcp_t {
    struct opj_tccp_t *tccps;
} opj_tcp_t;

typedef struct opj_tccp_t {
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 prcw[32], prch[32];
    OPJ_UINT32 cblkw, cblkh;
    OPJ_UINT32 qmfbid;
    OPJ_UINT32 numgbits;
    struct opj_stepsize_t *stepsizes;
} opj_tccp_t;

typedef struct opj_stepsize_t {
    OPJ_UINT32 mant;
    OPJ_UINT32 expn;
} opj_stepsize_t;

typedef struct opj_tcd_image_t {
    struct opj_tcd_tile_t *tiles;
} opj_tcd_image_t;

typedef struct opj_tcd_tile_t {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 numcomps;
    struct opj_tcd_tilecomp_t *comps;
} opj_tcd_tile_t;

typedef struct opj_tcd_tilecomp_t {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 compno;
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 minimum_num_resolutions;
    OPJ_SIZE_T data_size_needed;
    void *data_win;
    OPJ_INT32 win_x0, win_y0, win_x1, win_y1;
    struct opj_tcd_resolution_t *resolutions;
    OPJ_UINT32 resolutions_size;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_resolution_t {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 pw, ph;
    OPJ_UINT32 numbands;
    struct opj_tcd_band_t *bands;
} opj_tcd_resolution_t;

typedef struct opj_tcd_band_t {
    OPJ_UINT32 bandno;
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_FLOAT32 stepsize;
    OPJ_INT32 numbps;
    struct opj_tcd_precinct_t *precincts;
    OPJ_UINT32 precincts_data_size;
} opj_tcd_band_t;

typedef struct opj_tcd_precinct_t {
    OPJ_INT32 x0, y0, x1, y1;
    OPJ_UINT32 cw, ch;
    union {
        struct opj_tcd_cblk_enc_t *enc;
        struct opj_tcd_cblk_dec_t *dec;
        void *blocks;
    } cblks;
    OPJ_UINT32 block_size;
    void *incltree;
    void *imsbtree;
} opj_tcd_precinct_t;

typedef struct opj_tcd_cblk_enc_t {
    OPJ_INT32 x0, y0, x1, y1;
} opj_tcd_cblk_enc_t;

typedef struct opj_tcd_cblk_dec_t {
    OPJ_INT32 x0, y0, x1, y1;
} opj_tcd_cblk_dec_t;

typedef struct opj_image_t {
    OPJ_INT32 x0, y0, x1, y1;
    struct opj_image_comp_t *comps;
} opj_image_t;

typedef struct opj_image_comp_t {
    OPJ_UINT32 dx, dy;
    OPJ_UINT32 prec;
    OPJ_UINT32 resno_decoded;
} opj_image_comp_t;

typedef struct opj_event_mgr_t {
    void (*opj_event_msg)(struct opj_event_mgr_t*, int, const char*);
} opj_event_mgr_t;

static INLINE OPJ_UINT32 opj_dwt_getgain(OPJ_UINT32 bandno) { return 0; }
static INLINE OPJ_UINT32 opj_dwt_getgain_real(OPJ_UINT32 bandno) { return 0; }
static INLINE OPJ_UINT32 opj_uint_max(OPJ_UINT32 a, OPJ_UINT32 b) { return a > b ? a : b; }
static INLINE OPJ_UINT32 opj_uint_min(OPJ_UINT32 a, OPJ_UINT32 b) { return a < b ? a : b; }
static INLINE OPJ_UINT32 opj_uint_adds(OPJ_UINT32 a, OPJ_UINT32 b) { return a + b; }
static INLINE OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b) { return (a + b - 1) / b; }
static INLINE OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b) { return (a + (1 << b) - 1) >> b; }
static INLINE OPJ_INT32 opj_int_floordivpow2(OPJ_INT32 a, OPJ_INT32 b) { return a >> b; }
static INLINE OPJ_INT32 opj_int_max(OPJ_INT32 a, OPJ_INT32 b) { return a > b ? a : b; }
static INLINE OPJ_INT32 opj_int_min(OPJ_INT32 a, OPJ_INT32 b) { return a < b ? a : b; }
static INLINE OPJ_INT32 opj_int64_ceildivpow2(OPJ_INT64 a, OPJ_INT32 b) { return (OPJ_INT32)((a + ((OPJ_INT64)1 << b) - 1) >> b); }
static INLINE OPJ_BOOL opj_tcd_is_band_empty(struct opj_tcd_band_t *band) { return OPJ_FALSE; }
static void* opj_malloc(size_t size) { return malloc(size); }
static void* opj_realloc(void *ptr, size_t size) { return realloc(ptr, size); }
static void opj_free(void *ptr) { free(ptr); }
static void opj_image_data_free(void *ptr) { free(ptr); }
static void opj_event_msg(opj_event_mgr_t* manager, int event_type, const char *msg) {}
static void* opj_tgt_create(OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager) { return NULL; }
static void* opj_tgt_init(void *tgt, OPJ_UINT32 w, OPJ_UINT32 h, opj_event_mgr_t* manager) { return NULL; }
static OPJ_BOOL opj_tcd_code_block_enc_allocate(opj_tcd_cblk_enc_t* cblk) { return OPJ_TRUE; }
static OPJ_BOOL opj_tcd_code_block_enc_allocate_data(opj_tcd_cblk_enc_t* cblk) { return OPJ_TRUE; }
static OPJ_BOOL opj_tcd_code_block_dec_allocate(opj_tcd_cblk_dec_t* cblk) { return OPJ_TRUE; }