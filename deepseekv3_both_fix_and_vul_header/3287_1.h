#include <stdint.h>
#include <string.h>
#include <assert.h>

#define JPEG2000_MAX_CBLKW 1024
#define JPEG2000_MAX_CBLKH 1024
#define JPEG2000_CBLK_BYPASS 0x01
#define JPEG2000_CBLK_VSC    0x02
#define JPEG2000_CBLK_SEGSYM 0x04

typedef struct Jpeg2000DecoderContext Jpeg2000DecoderContext;
typedef struct Jpeg2000CodingStyle Jpeg2000CodingStyle;
typedef struct Jpeg2000T1Context Jpeg2000T1Context;
typedef struct Jpeg2000Cblk Jpeg2000Cblk;

struct Jpeg2000Cblk {
    int npasses;
    int nonzerobits;
    int length;
    uint8_t *data;
};

struct MqcCtx {
    uint8_t *data;
    uint32_t a;
    uint32_t c;
    uint32_t ct;
    uint8_t *bp;
    uint8_t *bpstart;
    uint8_t *bpend;
};

struct Jpeg2000T1Context {
    uint8_t **data;
    uint8_t **flags;
    struct MqcCtx mqc;
};

struct Jpeg2000CodingStyle {
    int cblk_style;
};

static inline void av_assert0(int expr) { assert(expr); }
static inline void ff_mqc_initdec(struct MqcCtx *mqc, uint8_t *data) {
    mqc->data = data;
    mqc->a = 0x8000;
    mqc->c = *data << 16;
    mqc->ct = 8;
    mqc->bp = data + 1;
    mqc->bpstart = data;
    mqc->bpend = data + (*data ? *data : 0xffff);
}