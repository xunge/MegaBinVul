#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DECIMAL_SIZE(x) (sizeof(x)*2+1)
#define ULONG_MAX (~0UL)
#define NID_undef 0

typedef struct asn1_object_st {
    const unsigned char *data;
    int length;
} ASN1_OBJECT;

typedef struct bignum_st BIGNUM;

int OBJ_obj2nid(const ASN1_OBJECT *a);
const char *OBJ_nid2ln(int nid);
const char *OBJ_nid2sn(int nid);
size_t OPENSSL_strlcpy(char *dst, const char *src, size_t siz);
int BN_add_word(BIGNUM *a, unsigned long w);
BIGNUM *BN_new(void);
int BN_set_word(BIGNUM *a, unsigned long w);
int BN_lshift(BIGNUM *r, const BIGNUM *a, int n);
int BN_sub_word(BIGNUM *a, unsigned long w);
char *BN_bn2dec(const BIGNUM *a);
void OPENSSL_free(void *ptr);
void BN_free(BIGNUM *a);
int BIO_snprintf(char *buf, size_t n, const char *format, ...);