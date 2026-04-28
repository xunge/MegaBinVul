#include <stdlib.h>

typedef struct jpc_tsfb_t {
    int numlvls;
} jpc_tsfb_t;

typedef struct jas_seq2d_t {
    int xstart;
    int ystart;
    int width;
    int height;
    int rowstep;
} jas_seq2d_t;

int jpc_tsfb_synthesize2(jpc_tsfb_t *tsfb, void *ref, int xstart, int ystart, int width, int height, int rowstep, int numlvls);
void *jas_seq2d_getref(jas_seq2d_t *a, int x, int y);
int jas_seq2d_xstart(jas_seq2d_t *a);
int jas_seq2d_ystart(jas_seq2d_t *a);
int jas_seq2d_width(jas_seq2d_t *a);
int jas_seq2d_height(jas_seq2d_t *a);
int jas_seq2d_rowstep(jas_seq2d_t *a);