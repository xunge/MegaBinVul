#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define OPJ_TRUE 1
#define OPJ_FALSE 0

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef float OPJ_FLOAT32;

typedef struct {
    OPJ_FLOAT32 f[4];
} opj_v4_t;

typedef struct {
    opj_v4_t* wavelet;
    OPJ_INT32 sn;
    OPJ_INT32 dn;
    OPJ_INT32 cas;
} opj_v4dwt_t;

typedef struct {
    OPJ_UINT32 x0, y0, x1, y1;
} opj_tcd_resolution_t;

typedef struct {
    OPJ_UINT32 x0, y0, x1, y1;
    void* data;
    opj_tcd_resolution_t* resolutions;
} opj_tcd_tilecomp_t;

void* opj_aligned_malloc(size_t size);
void opj_aligned_free(void* ptr);
OPJ_UINT32 opj_dwt_max_resolution(opj_tcd_resolution_t* res, OPJ_UINT32 numres);
void opj_v4dwt_interleave_h(opj_v4dwt_t* h, OPJ_FLOAT32* aj, OPJ_INT32 w, OPJ_INT32 bufsize);
void opj_v4dwt_decode(opj_v4dwt_t* h);
void opj_v4dwt_interleave_v(opj_v4dwt_t* v, OPJ_FLOAT32* aj, OPJ_INT32 w, OPJ_INT32 j);