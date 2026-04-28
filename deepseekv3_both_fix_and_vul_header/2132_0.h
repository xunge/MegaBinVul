#include <stdint.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
} GetBitContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    AVRational time_base;
    int width;
    int height;
} AVCodecContext;

typedef struct MpegEncContext {
    GetBitContext gb;
    int width;
    int height;
    int low_delay;
    AVCodecContext *avctx;
} MpegEncContext;

typedef struct AVSContext {
    MpegEncContext s;
    int profile;
    int level;
    int aspect_ratio;
    int mb_width;
    int mb_height;
    int top_qp;
} AVSContext;

struct {
    int num;
    int den;
} avpriv_frame_rate_tab[16];

static inline unsigned int get_bits(GetBitContext *s, int n);
static inline void skip_bits(GetBitContext *s, int n);
static inline unsigned int get_bits1(GetBitContext *s);
static inline void skip_bits1(GetBitContext *s);
static void ff_cavs_init_top_lines(AVSContext *h);