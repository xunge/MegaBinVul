#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#define JPC_TILE_INIT 0
#define JPC_MH 0
#define JAS_DBGLOG(level, msg)
#define JPC_CEILDIV(a, b) (((a) + (b) - 1) / (b))
#define JAS_MAX(a, b) ((a) > (b) ? (a) : (b))
#define JAS_MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int prec;
    int sgnd;
    int hsamp;
    int vsamp;
} jpc_sizcomp_t;

typedef struct {
    uint_fast32_t xoff;
    uint_fast32_t yoff;
    uint_fast32_t width;
    uint_fast32_t height;
    uint_fast32_t tilewidth;
    uint_fast32_t tileheight;
    uint_fast32_t tilexoff;
    uint_fast32_t tileyoff;
    uint_fast16_t numcomps;
    jpc_sizcomp_t *comps;
} jpc_siz_t;

typedef struct {
    jpc_siz_t siz;
} jpc_ms_parms_t;

typedef struct {
    jpc_ms_parms_t parms;
} jpc_ms_t;

typedef struct {
    int hstep;
    int vstep;
    int width;
    int height;
    int prec;
    int sgnd;
    int hsubstep;
    int vsubstep;
} jpc_dec_cmpt_t;

typedef struct {
    int rlvls;
    int numrlvls;
    void *data;
    int xstart;
    int ystart;
    int xend;
    int yend;
    int tsfb;
} jpc_dec_tcomp_t;

typedef struct {
    int realmode;
    int state;
    uint_fast32_t xstart;
    uint_fast32_t ystart;
    uint_fast32_t xend;
    uint_fast32_t yend;
    int numparts;
    int partno;
    void *pkthdrstream;
    size_t pkthdrstreampos;
    void *pptstab;
    void *cp;
    void *pi;
    jpc_dec_tcomp_t *tcomps;
} jpc_dec_tile_t;

typedef struct {
    void *cp;
} jpc_dec_cp_t;

typedef struct {
    uint_fast32_t xstart;
    uint_fast32_t ystart;
    uint_fast32_t xend;
    uint_fast32_t yend;
    uint_fast32_t tilewidth;
    uint_fast32_t tileheight;
    uint_fast32_t tilexoff;
    uint_fast32_t tileyoff;
    uint_fast16_t numcomps;
    jpc_dec_cmpt_t *cmpts;
    void *image;
    int numhtiles;
    int numvtiles;
    int numtiles;
    jpc_dec_tile_t *tiles;
    void *pkthdrstreams;
    int state;
    jpc_dec_cp_t *cp;
} jpc_dec_t;

static void *jas_alloc2(size_t num, size_t size) {
    return calloc(num, size);
}

static int jas_safe_size_mul(size_t a, size_t b, size_t *result) {
    if (a && b > SIZE_MAX / a) {
        return 0;
    }
    *result = a * b;
    return 1;
}

static jpc_dec_cp_t *jpc_dec_cp_create(int numcomps) {
    return calloc(1, sizeof(jpc_dec_cp_t));
}