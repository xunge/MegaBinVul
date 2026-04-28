#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define JPC_MAXBANDS 32
#define JPC_MCT_ICT 1
#define JPC_COX_INS 1
#define JPC_PREC 31
#define JPC_QCX_GETEXPN(x) ((x) >> 11)
#define JPC_NOMINALGAIN(qmfbid, numrlvls, rlvlno, orient) \
    ((qmfbid) == JPC_COX_INS ? 0 : \
    ((numrlvls) - 1 - (rlvlno)) * 2 + ((orient) == 0 ? 0 : 1))

typedef struct jpc_dec_t jpc_dec_t;
typedef struct jpc_dec_tile_t jpc_dec_tile_t;
typedef struct jpc_dec_tcomp_t jpc_dec_tcomp_t;
typedef struct jpc_dec_rlvl_t jpc_dec_rlvl_t;
typedef struct jpc_dec_band_t jpc_dec_band_t;
typedef struct jpc_dec_prc_t jpc_dec_prc_t;
typedef struct jpc_tsfb_band_t jpc_tsfb_band_t;
typedef struct jpc_dec_ccp_t jpc_dec_ccp_t;
typedef struct jpc_dec_cblk_t jpc_dec_cblk_t;
typedef struct jpc_dec_cp_t jpc_dec_cp_t;
typedef struct jpc_pchg_t jpc_pchg_t;
typedef struct jpc_dec_cmpt_t jpc_dec_cmpt_t;
typedef struct jpc_tagtree_t jpc_tagtree_t;
typedef struct jpc_pi_t jpc_pi_t;
typedef struct jpc_seg_t jpc_seg_t;
typedef struct jpc_seq2d_t jpc_seq2d_t;
typedef struct jpc_tsfb_t jpc_tsfb_t;

struct jpc_dec_t {
    int numcomps;
    jpc_dec_cmpt_t *cmpts;
};

struct jpc_dec_tile_t {
    jpc_dec_cp_t *cp;
    int realmode;
    uint_fast32_t xstart;
    uint_fast32_t ystart;
    uint_fast32_t xend;
    uint_fast32_t yend;
    jpc_dec_tcomp_t *tcomps;
    jpc_pi_t *pi;
};

struct jpc_dec_tcomp_t {
    int numrlvls;
    jpc_dec_rlvl_t *rlvls;
    jpc_seq2d_t *data;
    jpc_tsfb_t *tsfb;
    uint_fast32_t xstart;
    uint_fast32_t ystart;
    uint_fast32_t xend;
    uint_fast32_t yend;
};

struct jpc_dec_rlvl_t {
    jpc_dec_band_t *bands;
    uint_fast32_t xstart;
    uint_fast32_t ystart;
    uint_fast32_t xend;
    uint_fast32_t yend;
    int prcwidthexpn;
    int prcheightexpn;
    int numhprcs;
    int numvprcs;
    int numprcs;
    int cbgwidthexpn;
    int cbgheightexpn;
    int cblkwidthexpn;
    int cblkheightexpn;
    int numbands;
};

struct jpc_dec_band_t {
    int orient;
    uint_fast16_t stepsize;
    int analgain;
    uint_fast32_t absstepsize;
    int numbps;
    int roishift;
    jpc_seq2d_t *data;
    jpc_dec_prc_t *prcs;
};

struct jpc_dec_prc_t {
    uint_fast32_t xstart;
    uint_fast32_t ystart;
    uint_fast32_t xend;
    uint_fast32_t yend;
    int numhcblks;
    int numvcblks;
    int numcblks;
    jpc_tagtree_t *incltagtree;
    jpc_tagtree_t *numimsbstagtree;
    jpc_dec_cblk_t *cblks;
};

struct jpc_tsfb_band_t {
    int orient;
    uint_fast32_t xstart;
    uint_fast32_t ystart;
    uint_fast32_t xend;
    uint_fast32_t yend;
    uint_fast32_t locxstart;
    uint_fast32_t locystart;
    uint_fast32_t locxend;
    uint_fast32_t locyend;
};

struct jpc_dec_ccp_t {
    int qmfbid;
    int numrlvls;
    uint_fast16_t *stepsizes;
    int numguardbits;
    int roishift;
    int *prcwidthexpns;
    int *prcheightexpns;
    int cblkwidthexpn;
    int cblkheightexpn;
};

struct jpc_dec_cblk_t {
    int firstpassno;
    void *mqdec;
    void *nulldec;
    int flags;
    int numpasses;
    struct {
        jpc_seg_t *head;
        jpc_seg_t *tail;
    } segs;
    jpc_seg_t *curseg;
    int numimsbs;
    int numlenbits;
    jpc_seq2d_t *data;
};

struct jpc_dec_cp_t {
    int mctid;
    jpc_dec_ccp_t *ccps;
    void *pchglist;
};

struct jpc_dec_cmpt_t {
    int hstep;
    int vstep;
    int prec;
};

#define JPC_CEILDIV(x, y) (((x) + (y) - 1) / (y))
#define JPC_CEILDIVPOW2(x, y) (((x) + (1 << (y)) - 1) >> (y))
#define JPC_FLOORDIVPOW2(x, y) ((x) >> (y))
#define JAS_CAST(type, x) ((type)(x))
#define JAS_MIN(x, y) ((x) < (y) ? (x) : (y))
#define JAS_MAX(x, y) ((x) > (y) ? (x) : (y))

void *jas_alloc2(size_t num_elements, size_t element_size);
jpc_seq2d_t *jas_seq2d_create(uint_fast32_t xstart, uint_fast32_t ystart, uint_fast32_t xend, uint_fast32_t yend);
void jas_seq2d_bindsub(jpc_seq2d_t *dst, jpc_seq2d_t *src, uint_fast32_t xstart, uint_fast32_t ystart, uint_fast32_t xend, uint_fast32_t yend);
void jas_seq2d_setshift(jpc_seq2d_t *seq, uint_fast32_t xstart, uint_fast32_t ystart);
uint_fast32_t jas_seq2d_xstart(jpc_seq2d_t *seq);
uint_fast32_t jas_seq2d_ystart(jpc_seq2d_t *seq);
uint_fast32_t jas_seq2d_xend(jpc_seq2d_t *seq);
uint_fast32_t jas_seq2d_yend(jpc_seq2d_t *seq);
jpc_tsfb_t *jpc_cod_gettsfb(int qmfbid, int numrlvls);
void jpc_tsfb_getbands(jpc_tsfb_t *tsfb, uint_fast32_t xstart, uint_fast32_t ystart, uint_fast32_t xend, uint_fast32_t yend, jpc_tsfb_band_t *bands);
jpc_tagtree_t *jpc_tagtree_create(int numleafsh, int numleafsv);
jpc_pi_t *jpc_dec_pi_create(jpc_dec_t *dec, jpc_dec_tile_t *tile);
int jpc_pchglist_numpchgs(void *pchglist);
jpc_pchg_t *jpc_pchglist_get(void *pchglist, int pchgno);
jpc_pchg_t *jpc_pchg_copy(jpc_pchg_t *pchg);
void jpc_pi_addpchg(jpc_pi_t *pi, jpc_pchg_t *pchg);
void jpc_pi_init(jpc_pi_t *pi);
uint_fast32_t jpc_calcabsstepsize(uint_fast16_t stepsize, int prec);