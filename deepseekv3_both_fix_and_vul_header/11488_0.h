#include <stdlib.h>

typedef struct ec_method_st EC_METHOD;
typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct ec_extra_data_st EC_EXTRA_DATA;

struct ec_method_st {
    int (*group_clear_finish)(EC_GROUP *);
    int (*group_finish)(EC_GROUP *);
};

struct ec_group_st {
    const EC_METHOD *meth;
    EC_EXTRA_DATA *extra_data;
    BN_MONT_CTX *mont_data;
    EC_POINT *generator;
    int order;
    int cofactor;
    unsigned char *seed;
    size_t seed_len;
};

void EC_EX_DATA_clear_free_all_data(EC_EXTRA_DATA **);
void EC_POINT_clear_free(EC_POINT *);
void BN_clear_free(int *);
void BN_MONT_CTX_free(BN_MONT_CTX *);
void OPENSSL_cleanse(void *, size_t);
void OPENSSL_free(void *);