#include <stdint.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct WmallDecodeCtx {
    GetBitContext gb;
    int acfilter_order;
    int acfilter_scaling;
    int acfilter_coeffs[20];
} WmallDecodeCtx;

static inline unsigned int get_bits(GetBitContext *gb, int n);