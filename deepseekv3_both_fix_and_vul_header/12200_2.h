#include <stddef.h>

#define OPENSSL_DH_MAX_MODULUS_BITS 10000
#define DH_MIN_MODULUS_BITS 512
#define DH_GENERATOR_2 2
#define MIN_STRENGTH 112
#define NID_undef 0
#define BN_RAND_TOP_ONE 0
#define BN_RAND_BOTTOM_ANY 0
#define FFC_PARAM_TYPE_DH 0

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;
typedef struct dh_st DH;
typedef struct dh_method DH_METHOD;
typedef struct engine_st ENGINE;

typedef struct {
    BIGNUM *p;
    BIGNUM *q;
    BIGNUM *g;
} DH_Params;

struct dh_st {
    DH_Params params;
    BIGNUM *pub_key;
    BIGNUM *priv_key;
    void *libctx;
    unsigned int length;
    int dirty_cnt;
};

#define ERR_LIB_DH 0
#define DH_R_MODULUS_TOO_LARGE 0
#define DH_R_Q_TOO_LARGE 0
#define DH_R_MODULUS_TOO_SMALL 0
#define ERR_R_BN_LIB 0

static void ERR_raise(int lib, int reason) {}
static BN_CTX *BN_CTX_new_ex(void *ctx) { return NULL; }
static BIGNUM *BN_secure_new() { return NULL; }
static BIGNUM *BN_new() { return NULL; }
static void BN_free(BIGNUM *a) {}
static void BN_CTX_free(BN_CTX *c) {}
static int BN_num_bits(const BIGNUM *a) { return 0; }
static int BN_priv_rand_ex(BIGNUM *rnd, int bits, int top, int bottom, int strength, BN_CTX *ctx) { return 0; }
static int BN_is_word(const BIGNUM *a, unsigned long w) { return 0; }
static int BN_is_bit_set(const BIGNUM *a, int n) { return 0; }
static int BN_clear_bit(BIGNUM *a, int n) { return 0; }
static int DH_get_nid(const DH *dh) { return 0; }
static int ossl_ifc_ffc_compute_security_bits(int bits) { return 0; }
static int ossl_ffc_generate_private_key(BN_CTX *ctx, DH_Params *params, int length, int strength, BIGNUM *priv_key) { return 0; }
static int ossl_ffc_params_simple_validate(void *libctx, DH_Params *params, int type, int *res) { return 0; }
static int ossl_dh_generate_public_key(BN_CTX *ctx, DH *dh, BIGNUM *priv_key, BIGNUM *pub_key) { return 0; }