#include <stdlib.h>

typedef struct ec_method_st EC_METHOD;
typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct bignum_st {
    int dummy;
} BIGNUM;

struct ec_method_st {
    void (*group_finish)(EC_GROUP *);
};

struct ec_group_st {
    EC_METHOD *meth;
    void *extra_data;
    BN_MONT_CTX *mont_data;
    EC_POINT *generator;
    BIGNUM order;
    BIGNUM cofactor;
    unsigned char *seed;
};

void EC_EX_DATA_free_all_data(void **);
void EC_POINT_free(EC_POINT *);
void BN_free(BIGNUM *);
void BN_MONT_CTX_free(BN_MONT_CTX *);
void OPENSSL_free(void *);