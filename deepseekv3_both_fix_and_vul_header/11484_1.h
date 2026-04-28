#include <stdlib.h>
#include <string.h>

typedef struct ec_extra_data_st EC_EXTRA_DATA;
typedef struct ec_method_st EC_METHOD;
typedef struct ec_group_st EC_GROUP;
typedef struct ec_point_st EC_POINT;
typedef struct bn_mont_ctx_st BN_MONT_CTX;
typedef struct bignum_st BIGNUM;

struct ec_method_st {
    int (*group_copy)(EC_GROUP *, const EC_GROUP *);
};

struct ec_extra_data_st {
    void *data;
    void *(*dup_func)(void *);
    void (*free_func)(void *);
    void (*clear_free_func)(void *);
    EC_EXTRA_DATA *next;
};

struct ec_group_st {
    EC_METHOD *meth;
    EC_EXTRA_DATA *extra_data;
    BN_MONT_CTX *mont_data;
    EC_POINT *generator;
    BIGNUM *order;
    BIGNUM *cofactor;
    int curve_name;
    int asn1_flag;
    int asn1_form;
    unsigned char *seed;
    size_t seed_len;
};

#define EC_F_EC_GROUP_COPY 0
#define EC_R_INCOMPATIBLE_OBJECTS 0
#define ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED 0

void ECerr(int a, int b);
void EC_EX_DATA_free_all_data(EC_EXTRA_DATA **d);
int EC_EX_DATA_set_data(EC_EXTRA_DATA **d, void *t, void *dup, void *free, void *clear);
BN_MONT_CTX *BN_MONT_CTX_new(void);
int BN_MONT_CTX_copy(BN_MONT_CTX *a, BN_MONT_CTX *b);
void BN_MONT_CTX_free(BN_MONT_CTX *a);
EC_POINT *EC_POINT_new(EC_GROUP *a);
int EC_POINT_copy(EC_POINT *a, EC_POINT *b);
void EC_POINT_clear_free(EC_POINT *a);
int BN_copy(BIGNUM *a, BIGNUM *b);
void *OPENSSL_malloc(size_t a);
void OPENSSL_free(void *a);