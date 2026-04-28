#include <stdint.h>
#include <stddef.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef struct {
    OPJ_UINT32 pdx;
    OPJ_UINT32 pdy;
    OPJ_UINT32 pw;
    OPJ_UINT32 ph;
} opj_pi_resolution_t;

typedef struct {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 numresolutions;
    opj_pi_resolution_t *resolutions;
} opj_pi_comp_t;

typedef struct {
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tx1;
    OPJ_UINT32 ty1;
    OPJ_UINT32 layno0;
    OPJ_UINT32 layno1;
    OPJ_UINT32 resno0;
    OPJ_UINT32 resno1;
    OPJ_UINT32 compno0;
    OPJ_UINT32 compno1;
} opj_poc_t;

typedef struct {
    OPJ_UINT32 first;
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 resno;
    OPJ_UINT32 y;
    OPJ_UINT32 x;
    OPJ_UINT32 compno;
    OPJ_UINT32 precno;
    OPJ_UINT32 layno;
    OPJ_UINT32 step_l;
    OPJ_UINT32 step_r;
    OPJ_UINT32 step_c;
    OPJ_UINT32 step_p;
    OPJ_UINT32 numcomps;
    OPJ_UINT32 tp_on;
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tx1;
    OPJ_UINT32 ty1;
    OPJ_BOOL *include;
    opj_pi_comp_t *comps;
    opj_poc_t poc;
} opj_pi_iterator_t;

static OPJ_UINT32 opj_uint_min(OPJ_UINT32 a, OPJ_UINT32 b) {
    return a < b ? a : b;
}

static OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b) {
    return (a + b - 1) / b;
}

static OPJ_INT32 opj_int_floordivpow2(OPJ_INT32 a, OPJ_INT32 b) {
    return a >> b;
}