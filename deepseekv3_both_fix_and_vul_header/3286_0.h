#include <stdlib.h>

typedef struct Jpeg2000Prec {
    void *zerobits;
    void *cblkincl;
    void *cblk;
} Jpeg2000Prec;

typedef struct Jpeg2000Band {
    Jpeg2000Prec *prec;
    int nbands;
} Jpeg2000Band;

typedef struct Jpeg2000ResLevel {
    Jpeg2000Band *band;
    int nbands;
    int num_precincts_x;
    int num_precincts_y;
} Jpeg2000ResLevel;

typedef struct Jpeg2000Component {
    Jpeg2000ResLevel *reslevel;
    void *i_data;
    void *f_data;
    void *dwt;
} Jpeg2000Component;

typedef struct Jpeg2000CodingStyle {
    int nreslevels;
} Jpeg2000CodingStyle;

void av_freep(void **ptr);
void ff_dwt_destroy(void **ptr);