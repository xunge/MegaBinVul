#include <stdlib.h>
#include <string.h>

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;
typedef struct ec_key_st EC_KEY;
typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;
typedef struct ec_method_st EC_METHOD;

#define OPENSSL_FIPS
#define OPENSSL_NO_EC2M
#define OPENSSL_NO_SHA512
#define ECDSA_F_ECDSA_SIGN_SETUP 0
#define ERR_R_PASSED_NULL_PARAMETER 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_EC_LIB 0
#define ERR_R_BN_LIB 0
#define ECDSA_R_RANDOM_NUMBER_GENERATION_FAILED 0
#define NID_X9_62_prime_field 0

#define BN_FLG_CONSTTIME 0

static void ECDSAerr(int a, int b) {}
static void BN_clear_free(BIGNUM *a) {}
static void BN_free(BIGNUM *a) {}
static void BN_CTX_free(BN_CTX *a) {}
static void EC_POINT_free(EC_POINT *a) {}
static int BN_is_zero(BIGNUM *a) { return 0; }
static int BN_num_bits(BIGNUM *a) { return 0; }
static int BN_set_word(BIGNUM *a, unsigned long b) { return 0; }
static int BN_set_flags(BIGNUM *a, int b) { return 0; }
static BIGNUM *BN_new() { return NULL; }
static BN_CTX *BN_CTX_new() { return NULL; }
static EC_POINT *EC_POINT_new(const EC_GROUP *a) { return NULL; }
static const EC_GROUP *EC_KEY_get0_group(const EC_KEY *a) { return NULL; }
static const BIGNUM *EC_KEY_get0_private_key(const EC_KEY *a) { return NULL; }
static const EC_METHOD *EC_GROUP_method_of(const EC_GROUP *a) { return NULL; }
static int EC_METHOD_get_field_type(const EC_METHOD *a) { return 0; }
static int EC_GROUP_get_order(const EC_GROUP *a, BIGNUM *b, BN_CTX *c) { return 0; }
static int EC_POINT_mul(const EC_GROUP *a, EC_POINT *b, const BIGNUM *c, const EC_POINT *d, const BIGNUM *e, BN_CTX *f) { return 0; }
static int EC_POINT_get_affine_coordinates_GFp(const EC_GROUP *a, const EC_POINT *b, BIGNUM *c, BIGNUM *d, BN_CTX *e) { return 0; }
static int BN_rand_range(BIGNUM *a, const BIGNUM *b) { return 0; }
static int BN_generate_dsa_nonce(BIGNUM *a, const BIGNUM *b, const BIGNUM *c, const unsigned char *d, int e, BN_CTX *f) { return 0; }
static int BN_add(BIGNUM *a, const BIGNUM *b, const BIGNUM *c) { return 0; }
static int BN_nnmod(BIGNUM *a, const BIGNUM *b, const BIGNUM *c, BN_CTX *d) { return 0; }
static int BN_mod_inverse(BIGNUM *a, const BIGNUM *b, const BIGNUM *c, BN_CTX *d) { return 0; }
static int BN_mod_sub(BIGNUM *a, const BIGNUM *b, const BIGNUM *c, const BIGNUM *d, BN_CTX *e) { return 0; }
static int BN_mod_exp_mont_consttime(BIGNUM *a, const BIGNUM *b, const BIGNUM *c, const BIGNUM *d, BN_CTX *e, void *f) { return 0; }
static void *EC_GROUP_get_mont_data(const EC_GROUP *a) { return NULL; }
static int fips_check_ec_prng(EC_KEY *a) { return 1; }