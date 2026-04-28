#include <stdlib.h>

typedef struct bignum_st {
    int dummy;
} BIGNUM;

typedef struct ec_group_st {
    BIGNUM field;
    BIGNUM order;
    BIGNUM cofactor;
    struct ec_point_st *generator;
    struct bn_mont_ctx_st *mont_data;
} EC_GROUP;

typedef struct ec_point_st EC_POINT;
typedef struct bn_mont_ctx_st BN_MONT_CTX;

#define EC_F_EC_GROUP_SET_GENERATOR 0
#define ERR_R_PASSED_NULL_PARAMETER 0
#define EC_R_INVALID_FIELD 0
#define EC_R_INVALID_GROUP_ORDER 0
#define EC_R_UNKNOWN_COFACTOR 0

#define EC_GROUP_VERSION(group) 0

int ECerr(int lib, int reason);
int BN_is_zero(const BIGNUM *a);
int BN_is_negative(const BIGNUM *a);
int BN_num_bits(const BIGNUM *a);
int BN_copy(BIGNUM *to, const BIGNUM *from);
void BN_zero(BIGNUM *a);
int BN_is_odd(const BIGNUM *a);
EC_POINT *EC_POINT_new(const EC_GROUP *group);
int EC_POINT_copy(EC_POINT *dest, const EC_POINT *src);
int ec_guess_cofactor(EC_GROUP *group);
int ec_precompute_mont_data(EC_GROUP *group);
void BN_MONT_CTX_free(BN_MONT_CTX *mont);