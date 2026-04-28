#include <stdlib.h>

typedef struct asn1_string_st {
    int type;
    int length;
    unsigned char *data;
} ASN1_INTEGER;

typedef struct bignum_st BIGNUM;

#define ASN1_F_BN_TO_ASN1_INTEGER 0
#define ERR_R_NESTED_ASN1_ERROR 1
#define ERR_R_MALLOC_FAILURE 2
#define V_ASN1_INTEGER 2
#define V_ASN1_NEG_INTEGER 3

#define M_ASN1_INTEGER_new() ((ASN1_INTEGER *)calloc(1, sizeof(ASN1_INTEGER)))
#define M_ASN1_INTEGER_free(a) free(a)
#define OPENSSL_realloc realloc

void ASN1err(int a, int b);
int BN_is_negative(const BIGNUM *bn);
int BN_num_bits(const BIGNUM *bn);
int BN_bn2bin(const BIGNUM *bn, unsigned char *data);