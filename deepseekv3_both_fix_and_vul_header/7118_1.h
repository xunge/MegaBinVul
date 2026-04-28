#include <stddef.h>

typedef struct bignum_st BIGNUM;

#define FFC_ERROR_PASSED_NULL_PARAM 1
#define FFC_ERROR_PRIVKEY_TOO_SMALL 2
#define FFC_ERROR_PRIVKEY_TOO_LARGE 4

int BN_cmp(const BIGNUM *a, const BIGNUM *b);
const BIGNUM *BN_value_one(void);