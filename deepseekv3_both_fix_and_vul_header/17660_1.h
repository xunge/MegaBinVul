#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;
typedef unsigned int UINT32;

typedef struct bignum_st BIGNUM;
typedef struct bn_ctx_st BN_CTX;

BIGNUM *BN_new(void);
void BN_free(BIGNUM *a);
void BN_clear_free(BIGNUM *a);
BN_CTX *BN_CTX_new(void);
void BN_CTX_free(BN_CTX *c);
int BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);
int BN_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx);
int BN_bn2bin(const BIGNUM *a, unsigned char *to);