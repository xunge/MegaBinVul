#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef struct opj_dwt_t {
    OPJ_INT32* mem;
    OPJ_UINT32 mem_count;
    OPJ_INT32 sn;
    OPJ_INT32 dn;
    OPJ_INT32 cas;
} opj_dwt_t;

typedef struct opj_tcd_resolution_t {
    OPJ_UINT32 x0, x1, y0, y1;
} opj_tcd_resolution_t;

typedef struct opj_tcd_tilecomp_t {
    OPJ_UINT32 x0, x1, y0, y1;
    OPJ_INT32* data;
    opj_tcd_resolution_t* resolutions;
} opj_tcd_tilecomp_t;

typedef void (*DWT1DFN)(opj_dwt_t*);

static OPJ_UINT32 opj_dwt_max_resolution(const opj_tcd_resolution_t* tr, OPJ_UINT32 numres);
static void opj_dwt_interleave_h(opj_dwt_t* h, OPJ_INT32* tiledp);
static void opj_dwt_interleave_v(opj_dwt_t* v, OPJ_INT32* tiledp, OPJ_INT32 w);
static void* opj_aligned_malloc(size_t size);
static void opj_aligned_free(void* ptr);