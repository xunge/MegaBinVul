#include <stdint.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct IDCTDSPContext {
    uint8_t idct_permutation[64];
} IDCTDSPContext;

typedef struct MpegEncContext {
    int intra_matrix[64];
    int chroma_intra_matrix[64];
    IDCTDSPContext idsp;
} MpegEncContext;

extern const uint8_t ff_zigzag_direct[64];

#define AVERROR_INVALIDDATA (-1)

static inline int get_bits1(GetBitContext *gb);
static inline int get_bits(GetBitContext *gb, int n);
static inline int get_bits_left(GetBitContext *gb);
static void next_start_code_studio(GetBitContext *gb);