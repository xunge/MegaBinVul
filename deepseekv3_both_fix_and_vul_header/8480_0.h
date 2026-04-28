#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef int16_t OPJ_INT16;

#define OPJ_J2K_MAXRLVLS 33
#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef struct opj_image_comp {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
} opj_image_comp_t;

typedef struct opj_tccp {
    OPJ_UINT32 numresolutions;
} opj_tccp_t;

typedef struct opj_tcp {
    OPJ_UINT32 numlayers;
    OPJ_UINT32 numpocs;
    opj_tccp_t *tccps;
    int POC;
} opj_tcp_t;

typedef struct opj_cp {
    OPJ_UINT32 tw;
    OPJ_UINT32 th;
    opj_tcp_t *tcps;
} opj_cp_t;

typedef struct opj_image {
    OPJ_UINT32 numcomps;
    opj_image_comp_t *comps;
} opj_image_t;

typedef struct opj_pi_resolution {
    OPJ_UINT32 pdx;
    OPJ_UINT32 pdy;
    OPJ_UINT32 pw;
    OPJ_UINT32 ph;
} opj_pi_resolution_t;

typedef struct opj_pi_comp {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 numresolutions;
    opj_pi_resolution_t *resolutions;
} opj_pi_comp_t;

typedef struct opj_pi_iterator {
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tx1;
    OPJ_UINT32 ty1;
    OPJ_UINT32 step_p;
    OPJ_UINT32 step_c;
    OPJ_UINT32 step_r;
    OPJ_UINT32 step_l;
    OPJ_UINT32 numcomps;
    OPJ_INT16 *include;
    opj_pi_comp_t *comps;
} opj_pi_iterator_t;

void *opj_malloc(size_t size);
void *opj_calloc(size_t num, size_t size);
void opj_free(void *ptr);
opj_pi_iterator_t *opj_pi_create(opj_image_t *image, opj_cp_t *cp, OPJ_UINT32 tile_no);
void opj_pi_destroy(opj_pi_iterator_t *pi, OPJ_UINT32 bound);
void opj_get_all_encoding_parameters(opj_image_t *image, opj_cp_t *cp, OPJ_UINT32 tile_no, 
                                    OPJ_INT32 *tx0, OPJ_INT32 *tx1, OPJ_INT32 *ty0, OPJ_INT32 *ty1, 
                                    OPJ_UINT32 *dx_min, OPJ_UINT32 *dy_min, OPJ_UINT32 *max_prec, 
                                    OPJ_UINT32 *max_res, OPJ_UINT32 **tmp);
void opj_pi_update_decode_poc(opj_pi_iterator_t *pi, opj_tcp_t *tcp, OPJ_UINT32 max_prec, OPJ_UINT32 max_res);
void opj_pi_update_decode_not_poc(opj_pi_iterator_t *pi, opj_tcp_t *tcp, OPJ_UINT32 max_prec, OPJ_UINT32 max_res);