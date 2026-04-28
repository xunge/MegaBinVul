#include <stdlib.h>
#include <string.h>

typedef struct ASN1_ITEM_st ASN1_ITEM;

typedef struct X509_algor_st {
    void *algorithm;
} X509_ALGOR;

typedef struct asn1_string_st {
    int type;
    int flags;
    unsigned char *data;
    long length;
} ASN1_BIT_STRING;

typedef struct evp_pkey_st {
    struct {
        int pkey_id;
        int (*item_verify)();
    } *ameth;
} EVP_PKEY;

typedef struct evp_md_ctx_st {
    int dummy;
} EVP_MD_CTX;

typedef struct evp_md_st EVP_MD;

#define V_ASN1_BIT_STRING 3
#define NID_undef 0
#define ASN1_F_ASN1_ITEM_VERIFY 0
#define ASN1_F_ASN1_VERIFY 0
#define ERR_R_PASSED_NULL_PARAMETER 0
#define ASN1_R_INVALID_BIT_STRING_BITS_LEFT 0
#define ASN1_R_UNKNOWN_SIGNATURE_ALGORITHM 0
#define ASN1_R_UNKNOWN_MESSAGE_DIGEST_ALGORITHM 0
#define ASN1_R_WRONG_PUBLIC_KEY_TYPE 0
#define ERR_R_EVP_LIB 0
#define ERR_R_MALLOC_FAILURE 0

void ASN1err(int a, int b);
int OBJ_find_sigid_algs(int a, int *b, int *c);
int OBJ_obj2nid(void *a);
int EVP_PKEY_type(int a);
int EVP_DigestVerifyInit(EVP_MD_CTX *a, void *b, const EVP_MD *c, void *d, EVP_PKEY *e);
int EVP_DigestVerifyUpdate(EVP_MD_CTX *a, const void *b, size_t c);
int EVP_DigestVerifyFinal(EVP_MD_CTX *a, const unsigned char *b, size_t c);
const EVP_MD *EVP_get_digestbynid(int a);
void EVP_MD_CTX_init(EVP_MD_CTX *a);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *a);
int ASN1_item_i2d(void *a, unsigned char **b, const ASN1_ITEM *c);
void OPENSSL_cleanse(void *a, unsigned int b);
void OPENSSL_free(void *a);