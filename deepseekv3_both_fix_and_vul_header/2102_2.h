#include <string.h>

#define SBR_SYNTHESIS_BUF_SIZE 2048

typedef struct DSPContext {
    void (*vector_fmul_add)(float *dst, const float *src0, const float *src1, const float *src2, int len);
} DSPContext;

typedef struct FFTContext {
    void (*imdct_half)(struct FFTContext *mdct, float *output, float *input);
} FFTContext;

static const float sbr_qmf_window_ds[640];
static const float sbr_qmf_window_us[640];
static const float zero64[64];