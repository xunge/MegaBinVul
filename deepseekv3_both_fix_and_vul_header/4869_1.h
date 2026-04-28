#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DECIMAL_SIZE(type) ((sizeof(type)*8+2)/3+1)
#define ULONG_MAX (~0UL)
#define NID_undef 0

typedef struct asn1_object_st ASN1_OBJECT;
struct asn1_object_st {
    const unsigned char *data;
    int length;
};

typedef struct bignum_st BIGNUM;
struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

int OBJ_obj2nid(const ASN1_OBJECT *a);
const char *OBJ_nid2ln(int n);
const char *OBJ_nid2sn(int n);
char *BN_bn2dec(const BIGNUM *a);
int BN_add_word(BIGNUM *a, unsigned long w);
int BN_set_word(BIGNUM *a, unsigned long w);
int BN_lshift(BIGNUM *r, const BIGNUM *a, int n);
int BN_sub_word(BIGNUM *a, unsigned long w);
BIGNUM *BN_new(void);
void BN_free(BIGNUM *a);
void OPENSSL_free(void *addr);
int BIO_snprintf(char *buf, size_t n, const char *format, ...);
size_t BUF_strlcpy(char *dst, const char *src, size_t siz);