#include <stdlib.h>
#include <string.h>

#define NID_undef 0
#define NID_X9_62_characteristic_two_field 1
#define NID_X9_62_prime_field 2
#define NID_X9_62_tpBasis 3
#define NID_X9_62_ppBasis 4
#define NID_X9_62_onBasis 5
#define NID_wap_wsg_idm_ecid_wtls12 6
#define NID_secp224r1 7

#define OPENSSL_ECC_MAX_FIELD_BITS 661
#define OPENSSL_EC_EXPLICIT_CURVE 0

typedef struct ec_group_st {
    unsigned char *seed;
    int seed_len;
} EC_GROUP;

typedef struct ec_point_st EC_POINT;
typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;
typedef struct asn1_string_st ASN1_INTEGER;
typedef struct asn1_object_st ASN1_OBJECT;

typedef struct {
    int fieldType;
    union {
        ASN1_INTEGER *prime;
        void *ptr;
        struct {
            int type;
            union {
                ASN1_INTEGER *tpBasis;
                struct {
                    int k1;
                    int k2;
                    int k3;
                } *ppBasis;
            } p;
            long m;
        } *char_two;
    } p;
} ECPARAMETERS_FIELDID;

typedef struct {
    unsigned char *data;
    int length;
} ASN1_BIT_STRING;

typedef struct {
    ASN1_BIT_STRING *a;
    ASN1_BIT_STRING *b;
    ASN1_BIT_STRING *seed;
} ECPARAMETERS_CURVE;

typedef struct ECPARAMETERS_st {
    int version;
    ECPARAMETERS_FIELDID *fieldID;
    ECPARAMETERS_CURVE *curve;
    ASN1_BIT_STRING *base;
    ASN1_INTEGER *order;
    ASN1_INTEGER *cofactor;
} ECPARAMETERS;

typedef struct {
    int type;
    union {
        ASN1_INTEGER *tpBasis;
        struct {
            int k1;
            int k2;
            int k3;
        } *ppBasis;
    } p;
    long m;
} X9_62_CHARACTERISTIC_TWO;

typedef struct {
    int k1;
    int k2;
    int k3;
} X9_62_PENTANOMIAL;

typedef enum {
    POINT_CONVERSION_COMPRESSED,
    POINT_CONVERSION_UNCOMPRESSED,
    POINT_CONVERSION_HYBRID
} point_conversion_form_t;

#define EC_F_EC_GROUP_NEW_FROM_ECPARAMETERS 0
#define EC_R_ASN1_ERROR 0
#define EC_R_GF2M_NOT_SUPPORTED 0
#define EC_R_FIELD_TOO_LARGE 0
#define ERR_R_BN_LIB 0
#define ERR_R_MALLOC_FAILURE 0
#define EC_R_INVALID_TRINOMIAL_BASIS 0
#define EC_R_INVALID_PENTANOMIAL_BASIS 0
#define EC_R_NOT_IMPLEMENTED 0
#define EC_R_INVALID_FIELD 0
#define ERR_R_ASN1_LIB 0
#define ERR_R_EC_LIB 0
#define EC_R_INVALID_GROUP_ORDER 0

static void ECerr(int a, int b) {}
static int OBJ_obj2nid(ASN1_OBJECT *obj) { return 0; }
static long ASN1_INTEGER_get(ASN1_INTEGER *a) { return 0; }
static BIGNUM *BN_new() { return NULL; }
static int BN_set_bit(BIGNUM *a, int b) { return 0; }
static BIGNUM *ASN1_INTEGER_to_BN(ASN1_INTEGER *a, BIGNUM *b) { return NULL; }
static int BN_is_negative(BIGNUM *a) { return 0; }
static int BN_is_zero(BIGNUM *a) { return 0; }
static long BN_num_bits(BIGNUM *a) { return 0; }
static BIGNUM *BN_bin2bn(const unsigned char *a, int b, BIGNUM *c) { return NULL; }
static void BN_free(BIGNUM *a) {}
static EC_GROUP *EC_GROUP_new_curve_GFp(BIGNUM *a, BIGNUM *b, BIGNUM *c, BN_CTX *d) { return NULL; }
static EC_GROUP *EC_GROUP_new_curve_GF2m(BIGNUM *a, BIGNUM *b, BIGNUM *c, BN_CTX *d) { return NULL; }
static void EC_GROUP_free(EC_GROUP *a) {}
static EC_POINT *EC_POINT_new(EC_GROUP *a) { return NULL; }
static void EC_POINT_free(EC_POINT *a) {}
static int EC_POINT_oct2point(EC_GROUP *a, EC_POINT *b, const unsigned char *c, int d, BN_CTX *e) { return 0; }
static void EC_GROUP_set_point_conversion_form(EC_GROUP *a, point_conversion_form_t b) {}
static int EC_GROUP_set_generator(EC_GROUP *a, EC_POINT *b, BIGNUM *c, BIGNUM *d) { return 0; }
static BN_CTX *BN_CTX_new() { return NULL; }
static void BN_CTX_free(BN_CTX *a) {}
static EC_GROUP *EC_GROUP_dup(EC_GROUP *a) { return NULL; }
static int EC_GROUP_set_seed(EC_GROUP *a, const unsigned char *b, int c) { return 0; }
static int ec_curve_nid_from_params(EC_GROUP *a, BN_CTX *b) { return 0; }
static EC_GROUP *EC_GROUP_new_by_curve_name(int a) { return NULL; }
static void EC_GROUP_set_asn1_flag(EC_GROUP *a, int b) {}
static void *OPENSSL_malloc(int a) { return NULL; }
static void OPENSSL_free(void *a) {}