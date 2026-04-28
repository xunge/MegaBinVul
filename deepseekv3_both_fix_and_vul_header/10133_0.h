#include <stdlib.h>
#include <stdint.h>

typedef struct jpc_dec_t jpc_dec_t;
typedef struct jpc_ms_t jpc_ms_t;
typedef struct jpc_siz_t jpc_siz_t;
typedef struct jpc_dec_tile_t jpc_dec_tile_t;
typedef struct jpc_dec_tcomp_t jpc_dec_tcomp_t;
typedef struct jpc_dec_cmpt_t jpc_dec_cmpt_t;

struct jpc_dec_cmpt_t {
    int prec;
    int sgnd;
    int hstep;
    int vstep;
    int width;
    int height;
    int hsubstep;
    int vsubstep;
};

struct jpc_dec_tcomp_t {
    int numrlvls;
    int xstart;
    int ystart;
    int xend;
    int yend;
    void *rlvls;
    void *data;
    void *tsfb;
};

struct jpc_dec_tile_t {
    int realmode;
    int state;
    int xstart;
    int ystart;
    int xend;
    int yend;
    int numparts;
    int partno;
    void *pkthdrstream;
    size_t pkthdrstreampos;
    void *pptstab;
    void *cp;
    void *pi;
    jpc_dec_tcomp_t *tcomps;
};

struct jpc_siz_t {
    uint32_t xoff;
    uint32_t yoff;
    uint32_t width;
    uint32_t height;
    uint32_t tilewidth;
    uint32_t tileheight;
    uint32_t tilexoff;
    uint32_t tileyoff;
    uint16_t numcomps;
    struct {
        uint8_t prec;
        uint8_t sgnd;
        uint8_t hsamp;
        uint8_t vsamp;
    } *comps;
};

struct jpc_ms_t {
    struct {
        jpc_siz_t siz;
    } parms;
};

struct jpc_dec_t {
    uint32_t xstart;
    uint32_t ystart;
    uint32_t xend;
    uint32_t yend;
    uint32_t tilewidth;
    uint32_t tileheight;
    uint32_t tilexoff;
    uint32_t tileyoff;
    uint16_t numcomps;
    void *cp;
    jpc_dec_cmpt_t *cmpts;
    void *image;
    int numhtiles;
    int numvtiles;
    int numtiles;
    jpc_dec_tile_t *tiles;
    int state;
    void *pkthdrstreams;
};

#define JPC_TILE_INIT 0
#define JPC_MH 0
#define JAS_MAX(a, b) ((a) > (b) ? (a) : (b))
#define JAS_MIN(a, b) ((a) < (b) ? (a) : (b))
#define JPC_CEILDIV(a, b) (((a) + (b) - 1) / (b))

void *jpc_dec_cp_create(int numcomps);
void *jas_alloc2(size_t num, size_t size);