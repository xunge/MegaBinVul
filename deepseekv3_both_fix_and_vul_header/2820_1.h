#include <stdint.h>
#include <math.h>

#define ALIGN
#define MAX_M 64
#define QUANTISE2INT(x) (int)(x)
#define QUANTISE2REAL(x) (x)
#define EPS 1e-10
#define LOG2_MIN_INF -1000.0f
#define HI_RES 1
#define SBR_LOW_POWER

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef float real_t;

static real_t log2_int_tab[] = {0};

static inline real_t pow2(real_t x) {
    return exp2f(x);
}

typedef struct {
    uint8_t L_E[2];
    uint8_t l_A[2];
    uint8_t prevEnvIsShort[2];
    uint8_t **t_E;
    uint8_t **t_Q;
    uint8_t N_L[4];
    uint8_t bs_limiter_bands;
    uint8_t **f_table_lim;
    uint8_t bs_limiter_gains;
    uint8_t kx;
    uint8_t **f_table_res;
    uint8_t **f;
    real_t ***E_curr;
    uint8_t **f_table_noise;
    uint8_t **bs_add_harmonic;
    uint8_t **bs_add_harmonic_prev;
    uint8_t *bs_add_harmonic_flag_prev;
} sbr_info;

typedef struct {
    real_t **G_lim_boost;
    real_t **Q_M_lim_boost;
    real_t **S_M_boost;
} sbr_hfadj_info;

static real_t find_log2_E(sbr_info *sbr, uint8_t res_band, uint8_t l, uint8_t ch);
static real_t find_log2_Q(sbr_info *sbr, uint8_t f_noise_band, uint8_t t_noise_band, uint8_t ch);
static real_t find_log2_Qplus1(sbr_info *sbr, uint8_t f_noise_band, uint8_t t_noise_band, uint8_t ch);
static uint8_t get_S_mapped(sbr_info *sbr, uint8_t ch, uint8_t l, uint8_t res_band2);