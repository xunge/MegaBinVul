#include <stdint.h>
#include <stddef.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef struct {
    OPJ_UINT32 compno0, compno1;
    OPJ_UINT32 layno0, layno1;
    OPJ_UINT32 resno0, resno1;
    OPJ_UINT32 tx0, tx1;
    OPJ_UINT32 ty0, ty1;
} opj_poc_t;

typedef struct {
    OPJ_UINT32 pdx, pdy;
    OPJ_UINT32 pw, ph;
} opj_pi_resolution_t;

typedef struct {
    OPJ_UINT32 dx, dy;
    OPJ_UINT32 numresolutions;
    opj_pi_resolution_t *resolutions;
} opj_pi_comp_t;

typedef struct {
    OPJ_UINT32 tx0, ty0, tx1, ty1;
    OPJ_UINT32 dx, dy;
    OPJ_UINT32 x, y;
    OPJ_UINT32 compno, resno, precno, layno;
    OPJ_UINT32 step_c, step_r, step_l, step_p;
    OPJ_BOOL tp_on;
    OPJ_BOOL first;
    OPJ_UINT32 *include;
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