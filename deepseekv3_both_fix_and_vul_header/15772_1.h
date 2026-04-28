#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef int OPJ_BOOL;
typedef unsigned int OPJ_UINT32;
typedef int OPJ_INT32;

#define OPJ_TRUE 1
#define OPJ_FALSE 0

#define EVT_ERROR 0

typedef struct opj_image_comp_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 factor;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
} opj_image_comp_t;

typedef struct opj_image_t {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numcomps;
    opj_image_comp_t* comps;
} opj_image_t;

typedef struct opj_event_mgr_t {
    void (*opj_event_msg)(struct opj_event_mgr_t*, int, const char*, ...);
} opj_event_mgr_t;

OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b);
OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b);