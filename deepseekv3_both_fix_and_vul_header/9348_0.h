#include <assert.h>
#include <stdint.h>

typedef uint32_t OPJ_UINT32;

typedef struct opj_poc {
    OPJ_UINT32 resno0;
    OPJ_UINT32 compno0;
    OPJ_UINT32 layno0;
    OPJ_UINT32 precno0;
    OPJ_UINT32 resno1;
    OPJ_UINT32 compno1;
    OPJ_UINT32 layno1;
    OPJ_UINT32 precno1;
    int prg;
} opj_poc_t;

typedef struct opj_pi_iterator {
    opj_poc_t poc;
    int first;
} opj_pi_iterator_t;

typedef struct opj_tcp {
    opj_poc_t *pocs;
    OPJ_UINT32 numpocs;
    OPJ_UINT32 numlayers;
} opj_tcp_t;

static OPJ_UINT32 opj_uint_min(OPJ_UINT32 a, OPJ_UINT32 b) {
    return a < b ? a : b;
}