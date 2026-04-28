#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bignum_st BIGNUM;
typedef unsigned long BN_ULONG;

#define BN_DEC_NUM 19
#define BN_DEC_FMT1 "%lu" 
#define BN_DEC_FMT2 "%019lu"
#define BN_DEC_CONV 10000000000000000000UL

#define OPENSSL_malloc malloc
#define OPENSSL_free free

int BN_num_bits(const BIGNUM *a);
int BN_is_zero(const BIGNUM *a);
int BN_is_negative(const BIGNUM *a);
BIGNUM *BN_dup(const BIGNUM *a);
BN_ULONG BN_div_word(BIGNUM *a, BN_ULONG w);
void BN_free(BIGNUM *a);
int BIO_snprintf(char *buf, size_t n, const char *format, ...);

#define BN_F_BN_BN2DEC 0
#define ERR_R_MALLOC_FAILURE 0
#define BNerr(a,b)