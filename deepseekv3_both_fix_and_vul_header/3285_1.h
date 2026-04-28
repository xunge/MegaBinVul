#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define AVERROR(e) (-(e))
#define AVERROR_INVALIDDATA (-22)
#define ENOMEM 12
#define AV_LOG_ERROR 16
#define FF_DWT53 0
#define FF_DWT97 1
#define JPEG2000_QSTY_NONE 0
#define JPEG2000_QSTY_SI 1
#define JPEG2000_QSTY_SE 2
#define SHL(a, b) ((a) << (b))
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct AVCodecContext {
    void *codec;
} AVCodecContext;

typedef struct Jpeg2000Component {
    uint16_t coord[2][2];
    uint16_t coord_o[2][2];
    void *i_data;
    float *f_data;
    struct {
        void *dwt;
    } dwt;
    struct Jpeg2000ResLevel *reslevel;
} Jpeg2000Component;

typedef struct Jpeg2000CodingStyle {
    int nreslevels2decode;
    int transform;
    int nreslevels;
    uint8_t log2_prec_widths[32];
    uint8_t log2_prec_heights[32];
    uint8_t log2_cblk_width;
    uint8_t log2_cblk_height;
} Jpeg2000CodingStyle;

typedef struct Jpeg2000QuantStyle {
    int quantsty;
    uint16_t expn[32];
    uint16_t mant[32];
} Jpeg2000QuantStyle;

typedef struct Jpeg2000ResLevel {
    uint16_t coord[2][2];
    uint8_t log2_prec_width;
    uint8_t log2_prec_height;
    int nbands;
    int num_precincts_x;
    int num_precincts_y;
    struct Jpeg2000Band *band;
} Jpeg2000ResLevel;

typedef struct Jpeg2000Band {
    float f_stepsize;
    int i_stepsize;
    uint16_t coord[2][2];
    uint8_t log2_cblk_width;
    uint8_t log2_cblk_height;
    struct Jpeg2000Prec *prec;
} Jpeg2000Band;

typedef struct Jpeg2000Prec {
    uint16_t coord[2][2];
    int nb_codeblocks_width;
    int nb_codeblocks_height;
    void *cblkincl;
    void *zerobits;
    struct Jpeg2000Cblk *cblk;
} Jpeg2000Prec;

typedef struct Jpeg2000Cblk {
    uint16_t coord[2][2];
    int zero;
    int lblock;
    int length;
    int lengthinc;
    int npasses;
} Jpeg2000Cblk;

static const uint8_t lut_gain[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

extern int ff_jpeg2000_dwt_init(void*, uint16_t[2][2], int, int);
extern int ff_jpeg2000_ceildivpow2(int, int);
extern int ff_jpeg2000_ceildiv(int, int);
extern void* ff_jpeg2000_tag_tree_init(int, int);
extern void* av_malloc_array(size_t, size_t);
extern void* av_mallocz_array(size_t, size_t);
extern void av_log(AVCodecContext*, int, const char*, ...);
extern int av_codec_is_encoder(void*);