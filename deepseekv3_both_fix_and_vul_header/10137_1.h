#include <stdio.h>

typedef int jpc_fix_t;

typedef struct jpc_dec_cmpt {
    int prec;
    int sgnd;
    int hstep;
    int vstep;
} jpc_dec_cmpt_t;

typedef struct jpc_dec_ccp {
    int roishift;
} jpc_dec_ccp_t;

typedef struct jpc_dec_cp {
    int mctid;
    jpc_dec_ccp_t *ccps;
} jpc_dec_cp_t;

typedef struct jpc_dec_band {
    void *data;
    int roishift;
    int numbps;
    int absstepsize;
} jpc_dec_band_t;

typedef struct jpc_dec_rlvl {
    jpc_dec_band_t *bands;
    int numbands;
} jpc_dec_rlvl_t;

typedef struct jpc_dec_tcomp {
    jpc_dec_rlvl_t *rlvls;
    int numrlvls;
    void *data;
    void *tsfb;
    int xstart;
    int ystart;
} jpc_dec_tcomp_t;

typedef struct jpc_dec_tile {
    jpc_dec_cp_t *cp;
    jpc_dec_tcomp_t *tcomps;
    int realmode;
} jpc_dec_tile_t;

typedef struct jpc_dec {
    int numcomps;
    int xstart;
    int ystart;
    jpc_dec_cmpt_t *cmpts;
    void *image;
} jpc_dec_t;

#define JPC_FIX_FRACBITS 31
#define JPC_MCT_RCT 0
#define JPC_MCT_ICT 1
#define JPC_CEILDIV(a, b) (((a) + (b) - 1) / (b))

int jpc_dec_decodecblks(jpc_dec_t *dec, jpc_dec_tile_t *tile);
void jas_eprintf(const char *format, ...);
void jpc_undo_roi(void *data, int roishift, int shift, int numbps);
void jas_matrix_asl(void *data, int n);
void jpc_dequantize(void *data, int absstepsize);
void jpc_tsfb_synthesize(void *tsfb, void *data);
void jpc_irct(void *data1, void *data2, void *data3);
void jpc_iict(void *data1, void *data2, void *data3);
int jpc_fix_round(int v);
int jpc_fixtoint(int v);
int jas_matrix_numrows(void *data);
int jas_matrix_numcols(void *data);
int jas_matrix_get(void *data, int i, int j);
void jas_matrix_set(void *data, int i, int j, int v);
int *jas_matrix_getref(void *data, int i, int j);
void jas_matrix_clip(void *data, int mn, int mx);
int jas_image_writecmpt(void *image, int compno, int x, int y, int width, int height, void *data);