#include <stdint.h>
#include <string.h>

#define SUBFRAME_SIZE 40
#define RES_PREV_DATA_SIZE 10
#define ANALYZED_FRAC_DELAYS 7
#define SHORT_INT_FILT_LEN 33
#define LONG_INT_FILT_LEN 129
#define FRAC_BITS 15
#define MIN_LT_FILT_FACTOR_A 16384

typedef struct AudioDSPContext {
    int (*scalarproduct_int16)(const int16_t *v1, const int16_t *v2, int len);
} AudioDSPContext;

extern const int16_t ff_g729_interp_filt_short[];
extern const int16_t ff_g729_interp_filt_long[];

void ff_acelp_interpolate(int16_t *out, const int16_t *in, const int16_t *filter,
                         int precision, int frac_pos, int filter_length, int length);
void ff_acelp_weighted_vector_sum(int16_t *out, const int16_t *in_a, const int16_t *in_b,
                                 int16_t weight_a, int16_t weight_b, int16_t rounder,
                                 int shift, int length);

static inline int av_log2(unsigned int v);
static inline int FFABS(int x);
static inline int FFMAX(int a, int b);
static inline int FFMAX3(int a, int b, int c);
static inline int MULL(int a, int b, int shift);