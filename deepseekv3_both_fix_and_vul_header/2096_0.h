#include <stdint.h>
#include <math.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct tonal_component {
    int pos;
    int numCoefs;
    float coef[8];
} tonal_component;

#define AVERROR_INVALIDDATA (-1)
#define SAMPLES_PER_FRAME 1024
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))

extern const float ff_atrac_sf_table[64];
extern const float iMaxQuant[8];

static int get_bits(GetBitContext *gb, int n);
static int get_bits1(GetBitContext *gb);
static void readQuantSpectralCoeffs(GetBitContext *gb, int quant_step_index, int coding_mode, int *mantissa, int coded_values);