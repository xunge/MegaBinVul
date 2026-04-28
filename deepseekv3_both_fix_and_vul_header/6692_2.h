#include <stdint.h>
#include <math.h>
#include <stddef.h>

#define OPJ_BOOL int
#define OPJ_FALSE 0
#define OPJ_TRUE 1
#define OPJ_UINT32 uint32_t
#define OPJ_INT32 int32_t
#define OPJ_FLOAT32 float
#define OPJ_FLOAT64 double
#define OPJ_SIZE_T size_t
#define OPJ_RESTRICT restrict
#define T1_NMSEDEC_FRACBITS 13

typedef struct opj_t1_t {
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    OPJ_INT32* data;
    OPJ_UINT32 data_stride;
} opj_t1_t;

typedef struct opj_tcd_resolution_t {
    OPJ_UINT32 x0, y0, x1, y1;
    OPJ_UINT32 pw, ph;
    OPJ_UINT32 numbands;
    struct opj_tcd_band_t* bands;
} opj_tcd_resolution_t;

typedef struct opj_tcd_band_t {
    OPJ_UINT32 bandno;
    OPJ_UINT32 x0, y0, x1, y1;
    OPJ_FLOAT32 stepsize;
    OPJ_UINT32 cw, ch;
    struct opj_tcd_precinct_t* precincts;
} opj_tcd_band_t;

typedef struct opj_tcd_precinct_t {
    OPJ_UINT32 cw, ch;
    struct {
        struct opj_tcd_cblk_enc_t* enc;
    } cblks;
} opj_tcd_precinct_t;

typedef struct opj_tcd_cblk_enc_t {
    OPJ_UINT32 x0, y0, x1, y1;
} opj_tcd_cblk_enc_t;

typedef struct opj_tcd_tilecomp_t {
    OPJ_UINT32 x0, y0, x1, y1;
    OPJ_UINT32 numresolutions;
    OPJ_INT32* data;
    struct opj_tcd_resolution_t* resolutions;
} opj_tcd_tilecomp_t;

typedef struct opj_tcd_tile_t {
    OPJ_UINT32 numcomps;
    OPJ_FLOAT64 distotile;
    struct opj_tcd_tilecomp_t* comps;
} opj_tcd_tile_t;

typedef struct opj_tccp_t {
    OPJ_UINT32 qmfbid;
    OPJ_UINT32 cblksty;
} opj_tccp_t;

typedef struct opj_tcp_t {
    struct opj_tccp_t* tccps;
} opj_tcp_t;

OPJ_INT32 opj_int_fix_mul_t1(OPJ_INT32 a, OPJ_INT32 b);
OPJ_BOOL opj_tcd_is_band_empty(opj_tcd_band_t* band);
OPJ_BOOL opj_t1_allocate_buffers(opj_t1_t *t1, OPJ_UINT32 w, OPJ_UINT32 h);
void opj_t1_encode_cblk(opj_t1_t *t1, opj_tcd_cblk_enc_t* cblk, int bandno, int compno, int resno, int qmfbid, float stepsize, int cblksty, int numcomps, opj_tcd_tile_t *tile, const OPJ_FLOAT64 * mct_norms, OPJ_UINT32 mct_numcomps);