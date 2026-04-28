#include <stdlib.h>
#include <string.h>

typedef struct EVP_MD_CTX {
    int dummy;
} EVP_MD_CTX;

typedef struct EVP_MD {
    int dummy; 
} EVP_MD;

typedef struct X509_ALGOR {
    void *algorithm;
} X509_ALGOR;

typedef struct ASN1_BIT_STRING {
    int type;
    int flags;
    int length;
    unsigned char *data;
} ASN1_BIT_STRING;

typedef struct EVP_PKEY {
    int dummy;
} EVP_PKEY;

typedef int i2d_of_void(void *a, unsigned char **pp);

#define V_ASN1_BIT_STRING 3
#define ASN1_F_ASN1_VERIFY 0
#define ASN1_R_UNKNOWN_MESSAGE_DIGEST_ALGORITHM 0 
#define ASN1_R_INVALID_BIT_STRING_BITS_LEFT 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_EVP_LIB 0

void ASN1err(int a, int b);
void EVP_MD_CTX_init(EVP_MD_CTX *ctx);
int OBJ_obj2nid(void *a);
char *OBJ_nid2sn(int n);
const EVP_MD *EVP_get_digestbyname(const char *name);
void *OPENSSL_malloc(size_t size);
void OPENSSL_cleanse(void *ptr, size_t len);
void OPENSSL_free(void *ptr);
int EVP_VerifyInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, void *a);
int EVP_VerifyUpdate(EVP_MD_CTX *ctx, const unsigned char *d, unsigned int cnt);
int EVP_VerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sigbuf, unsigned int siglen, EVP_PKEY *pkey);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx);