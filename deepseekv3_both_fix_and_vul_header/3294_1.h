#include <stdint.h>
#include <math.h>

#define FF_DWT97 1

typedef struct Jpeg2000T1Context {
    int dummy;
} Jpeg2000T1Context;

typedef struct Jpeg2000DecoderContext {
    int ncomponents;
    int cdef[256];
    int cbps[256];
    int cdx[256];
    int cdy[256];
    int precision;
    int image_offset_x;
    int image_offset_y;
} Jpeg2000DecoderContext;

typedef struct Jpeg2000Tile {
    struct Jpeg2000Component *comp;
    struct Jpeg2000CodingStyle *codsty;
} Jpeg2000Tile;

typedef struct Jpeg2000Component {
    struct Jpeg2000ResLevel *reslevel;
    float *f_data;
    int32_t *i_data;
    int coord[2][2];
    struct {
        int dummy;
    } dwt;
} Jpeg2000Component;

typedef struct Jpeg2000CodingStyle {
    int nreslevels2decode;
    int transform;
    int mct;
} Jpeg2000CodingStyle;

typedef struct Jpeg2000ResLevel {
    struct Jpeg2000Band *band;
    int nbands;
    int num_precincts_x;
    int num_precincts_y;
} Jpeg2000ResLevel;

typedef struct Jpeg2000Band {
    struct Jpeg2000Prec *prec;
    int coord[2][2];
} Jpeg2000Band;

typedef struct Jpeg2000Prec {
    struct Jpeg2000Cblk *cblk;
    int nb_codeblocks_width;
    int nb_codeblocks_height;
} Jpeg2000Prec;

typedef struct Jpeg2000Cblk {
    int coord[2][2];
} Jpeg2000Cblk;

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
} AVFrame;

static inline int av_clip(int a, int amin, int amax) {
    if (a < amin) return amin;
    if (a > amax) return amax;
    return a;
}

static void decode_cblk(Jpeg2000DecoderContext *s, Jpeg2000CodingStyle *codsty, Jpeg2000T1Context *t1, Jpeg2000Cblk *cblk, int width, int height, int bandpos) {}
static void dequantization_float(int x, int y, Jpeg2000Cblk *cblk, Jpeg2000Component *comp, Jpeg2000T1Context *t1, Jpeg2000Band *band) {}
static void dequantization_int(int x, int y, Jpeg2000Cblk *cblk, Jpeg2000Component *comp, Jpeg2000T1Context *t1, Jpeg2000Band *band) {}
static void ff_dwt_decode(void *dwt, void *data) {}
static void mct_decode(Jpeg2000DecoderContext *s, Jpeg2000Tile *tile) {}