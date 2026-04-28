#include <stdint.h>
#include <assert.h>

typedef struct jpc_pi_t jpc_pi_t;
typedef struct jpc_pirlvl_t jpc_pirlvl_t;
typedef struct jpc_pchg_t jpc_pchg_t;
typedef struct jpc_picomp_t jpc_picomp_t;

struct jpc_pchg_t {
    unsigned compnoend;
    int compnostart;
    unsigned rlvlnostart;
    unsigned rlvlnoend;
    unsigned lyrnoend;
};

struct jpc_pirlvl_t {
    int prcwidthexpn;
    int prcheightexpn;
    int numprcs;
    int numhprcs;
    int *prclyrnos;
};

struct jpc_picomp_t {
    int hsamp;
    int vsamp;
    int numrlvls;
    jpc_pirlvl_t *pirlvls;
};

struct jpc_pi_t {
    jpc_pchg_t *pchg;
    int prgvolfirst;
    int compno;
    jpc_picomp_t *picomp;
    jpc_picomp_t *picomps;
    int numcomps;
    int xstep;
    int ystep;
    int ystart;
    int yend;
    int xstart;
    int xend;
    int rlvlno;
    jpc_pirlvl_t *pirlvl;
    int x;
    int y;
    int prcno;
    int numlyrs;
    int lyrno;
};

#define JAS_CAST(type, val) ((type)(val))
#define JPC_CEILDIV(x, y) (((x) + (y) - 1) / (y))
#define JPC_FLOORDIVPOW2(x, y) ((x) >> (y))
#define JPC_MIN(x, y) ((x) < (y) ? (x) : (y))