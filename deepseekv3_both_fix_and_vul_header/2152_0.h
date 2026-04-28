#include <stdint.h>
#include <stdlib.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct WmallChannel {
    int transient_counter;
} WmallChannel;

typedef struct WmallDecodeCtx {
    GetBitContext gb;
    int *transient;
    int *transient_pos;
    WmallChannel *channel;
    int samples_per_frame;
    int seekable_tile;
    int bits_per_sample;
    unsigned int *ave_sum;
    int movave_scaling;
    int do_inter_ch_decorr;
    int **channel_residues;
} WmallDecodeCtx;

static inline int get_bits1(GetBitContext *s);
static inline unsigned int get_bits(GetBitContext *s, int n);
static inline int get_sbits_long(GetBitContext *s, int n);
static inline int get_bits_left(GetBitContext *s);
static inline unsigned int get_bits_long(GetBitContext *s, int n);
static inline int av_log2(unsigned int v);
static inline int av_ceil_log2(int x);
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))