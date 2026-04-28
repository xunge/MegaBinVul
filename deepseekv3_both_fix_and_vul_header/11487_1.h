#include <stdlib.h>

typedef struct ec_method_st EC_METHOD;
typedef struct ec_group_st EC_GROUP;
typedef struct bignum_st {
    int dummy;
} BIGNUM;

struct ec_method_st {
    int (*group_init)(EC_GROUP *);
};

struct ec_group_st {
    const EC_METHOD *meth;
    void *extra_data;
    void *mont_data;
    void *generator;
    BIGNUM order;
    BIGNUM cofactor;
    int curve_name;
    int asn1_flag;
    int asn1_form;
    unsigned char *seed;
    size_t seed_len;
};

#define EC_F_EC_GROUP_NEW 0
#define EC_R_SLOT_FULL 0
#define ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED 0
#define ERR_R_MALLOC_FAILURE 0
#define POINT_CONVERSION_UNCOMPRESSED 0

void ECerr(int a, int b);
void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
void BN_init(BIGNUM *a);