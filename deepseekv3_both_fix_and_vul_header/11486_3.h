#include <stddef.h>

typedef struct bignum_st {
    int dummy;  // 简化BIGNUM结构
} BIGNUM;

typedef struct ec_point_st {
    int dummy;  // 简化EC_POINT结构
} EC_POINT;

typedef struct ec_group_st {
    EC_POINT *generator;
    BIGNUM order;
    BIGNUM cofactor;
} EC_GROUP;

#define EC_F_EC_GROUP_SET_GENERATOR 0
#define ERR_R_PASSED_NULL_PARAMETER 0

EC_POINT *EC_POINT_new(EC_GROUP *group);
int EC_POINT_copy(EC_POINT *dest, const EC_POINT *src);
int BN_copy(BIGNUM *dest, const BIGNUM *src);
void BN_zero(BIGNUM *a);
void ECerr(int lib, int reason);