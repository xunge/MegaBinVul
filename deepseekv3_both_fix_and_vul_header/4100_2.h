#include <stdlib.h>
#include <string.h>

typedef unsigned long BN_ULONG;

typedef struct bignum_st {
    int top;
    int dmax;
    int neg;
    int flags;
    BN_ULONG *d;
} BIGNUM;

typedef struct bn_mont_ctx_st {
    BIGNUM RR;
    BIGNUM N;
    BN_ULONG n0[2];
} BN_MONT_CTX;

typedef struct bn_ctx_st BN_CTX;

#define BN_F_BN_MOD_EXP_MONT_CONSTTIME 0
#define BN_R_CALLED_WITH_EVEN_MODULUS 0
#define BN_FLG_STATIC_DATA 0
#define BN_BITS2 (sizeof(BN_ULONG) * 8)
#define BN_MASK2 (~(BN_ULONG)0)
#define MOD_EXP_CTIME_MIN_CACHE_LINE_WIDTH 64
#define MOD_EXP_CTIME_ALIGN(x) x
#define SPARC_T4_MONT 0
#define OPENSSL_BN_ASM_MONT5 0
#define RSAZ_ENABLED 0

#define SPARCV9_VIS3 1
#define SPARCV9_PREFER_FPU 2
#define CFR_MONTMUL 1
#define CFR_MONTSQR 2

void BNerr(int a, int b);
int BN_is_odd(const BIGNUM *a);
int BN_is_one(const BIGNUM *a);
void BN_zero(BIGNUM *a);
int BN_one(BIGNUM *a);
int BN_num_bits(const BIGNUM *a);
void BN_CTX_start(BN_CTX *ctx);
BN_MONT_CTX *BN_MONT_CTX_new(void);
int BN_MONT_CTX_set(BN_MONT_CTX *mont, const BIGNUM *mod, BN_CTX *ctx);
int BN_mod(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
int BN_to_montgomery(BIGNUM *r, const BIGNUM *a, BN_MONT_CTX *mont, BN_CTX *ctx);
int BN_mod_mul_montgomery(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, BN_MONT_CTX *mont, BN_CTX *ctx);
int BN_from_montgomery(BIGNUM *r, const BIGNUM *a, BN_MONT_CTX *mont, BN_CTX *ctx);
void BN_MONT_CTX_free(BN_MONT_CTX *mont);
void BN_CTX_end(BN_CTX *ctx);
void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
void OPENSSL_cleanse(void *ptr, size_t len);
int BN_is_bit_set(const BIGNUM *a, int n);
int bn_wexpand(BIGNUM *a, int words);
void bn_correct_top(BIGNUM *a);
void bn_check_top(const BIGNUM *a);
int BN_window_bits_for_ctime_exponent_size(int bits);
int BN_get_bits(const BIGNUM *a, int n);
int BN_copy(BIGNUM *a, const BIGNUM *b);
BIGNUM *BN_value_one(void);
int BN_ucmp(const BIGNUM *a, const BIGNUM *b);

#define MOD_EXP_CTIME_COPY_TO_PREBUF(b, top, buf, idx, window) 1
#define MOD_EXP_CTIME_COPY_FROM_PREBUF(b, top, buf, idx, window) 1

#if defined(SPARC_T4_MONT)
unsigned int OPENSSL_sparcv9cap_P[2];
#endif

#if defined(RSAZ_ENABLED)
int rsaz_avx2_eligible(void);
void RSAZ_1024_mod_exp_avx2(BN_ULONG *rr, const BN_ULONG *a, const BN_ULONG *p, const BN_ULONG *m, const BN_ULONG *RR, BN_ULONG k0);
void RSAZ_512_mod_exp(BN_ULONG *rr, const BN_ULONG *a, const BN_ULONG *p, const BN_ULONG *m, BN_ULONG k0, const BN_ULONG *RR);
#endif

int bn_get_bits(const BIGNUM *a, int n);
int bn_mul_mont(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp, const BN_ULONG *np, const BN_ULONG *n0, int num);