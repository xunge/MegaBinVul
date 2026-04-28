#include <stdint.h>
#include <assert.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

typedef struct opj_image_comp {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
} opj_image_comp_t;

typedef struct opj_tccp {
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 *prcw;
    OPJ_UINT32 *prch;
} opj_tccp_t;

typedef struct opj_tcp {
    opj_tccp_t *tccps;
} opj_tcp_t;

typedef struct opj_cp {
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    OPJ_UINT32 tw;
    OPJ_UINT32 th;
    opj_tcp_t *tcps;
} opj_cp_t;

typedef struct opj_image {
    OPJ_UINT32 x0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y0;
    OPJ_UINT32 y1;
    OPJ_UINT32 numcomps;
    opj_image_comp_t *comps;
} opj_image_t;

static OPJ_INT32 opj_int_max(OPJ_INT32 a, OPJ_INT32 b) { return (a > b) ? a : b; }
static OPJ_INT32 opj_int_min(OPJ_INT32 a, OPJ_INT32 b) { return (a < b) ? a : b; }
static OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b) { return (a + b - 1) / b; }
static OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b) { return (a + (1 << b) - 1) >> b; }
static OPJ_INT32 opj_int_floordivpow2(OPJ_INT32 a, OPJ_INT32 b) { return a >> b; }