#include <stddef.h>
#include <limits.h>

typedef unsigned long BN_ULONG;

typedef struct bignum_st {
    int top;
    BN_ULONG *d;
} BIGNUM;

typedef struct bn_ctx_st BN_CTX;

typedef struct ec_group_st {
    struct {
        int top;
    } field;
    BIGNUM b;
    BIGNUM *poly;
    struct {
        int (*field_sqr)(const struct ec_group_st *, BIGNUM *, const BIGNUM *, BN_CTX *);
    } *meth;
} EC_GROUP;

typedef struct ec_point_st {
    BIGNUM X;
    BIGNUM Y;
    BIGNUM Z;
    int Z_is_one;
} EC_POINT;

#define BN_TBIT ((BN_ULONG)1 << (sizeof(BN_ULONG) * CHAR_BIT - 1))
#define EC_F_EC_GF2M_MONTGOMERY_POINT_MULTIPLY 0
#define EC_R_INVALID_ARGUMENT 0

static int BN_is_zero(const BIGNUM *a) { return 0; }
static int BN_one(BIGNUM *a) { return 0; }
static int BN_GF2m_mod_arr(BIGNUM *r, const BIGNUM *a, const BIGNUM *p) { return 0; }
static int BN_GF2m_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b) { return 0; }
static void BN_set_negative(BIGNUM *a, int b) {}
static void BN_consttime_swap(int swap, BIGNUM *a, BIGNUM *b, int nwords) {}
static int bn_wexpand(BIGNUM *a, int words) { return 0; }
static void BN_CTX_start(BN_CTX *ctx) {}
static BIGNUM *BN_CTX_get(BN_CTX *ctx) { return NULL; }
static void BN_CTX_end(BN_CTX *ctx) {}
static void ECerr(int lib, int reason) {}
static int EC_POINT_is_at_infinity(const EC_GROUP *group, const EC_POINT *point) { return 0; }
static int EC_POINT_set_to_infinity(const EC_GROUP *group, EC_POINT *point) { return 0; }
static int gf2m_Madd(const EC_GROUP *group, const BIGNUM *x, BIGNUM *x1, BIGNUM *z1, BIGNUM *x2, BIGNUM *z2, BN_CTX *ctx) { return 0; }
static int gf2m_Mdouble(const EC_GROUP *group, BIGNUM *x, BIGNUM *z, BN_CTX *ctx) { return 0; }
static int gf2m_Mxy(const EC_GROUP *group, const BIGNUM *x, const BIGNUM *y, BIGNUM *x1, BIGNUM *z1, BIGNUM *x2, BIGNUM *z2, BN_CTX *ctx) { return 0; }