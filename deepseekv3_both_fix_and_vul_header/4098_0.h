#include <stdint.h>
#include <stdlib.h>

typedef uint64_t BN_ULONG;

struct bignum_st {
    BN_ULONG *d;
    int top;
};
typedef struct bignum_st BIGNUM;

static int bn_wexpand(BIGNUM *a, int words);
static void bn_correct_top(BIGNUM *a);
static int constant_time_eq_int(int a, int b);