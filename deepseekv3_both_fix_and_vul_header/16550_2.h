#include <string.h>
#include <stdlib.h>

typedef struct X509_name_st X509_NAME;
typedef struct X509_serial_st {
    unsigned char *data;
    int length;
} ASN1_INTEGER;

typedef struct X509_cinf_st {
    X509_NAME *issuer;
    ASN1_INTEGER serialNumber;
} X509_CINF;

typedef struct X509_st {
    X509_CINF cert_info;  // Changed from pointer to direct struct
} X509;

typedef struct evp_md_ctx_st EVP_MD_CTX;

EVP_MD_CTX *EVP_MD_CTX_new(void);
void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const void *type, void *impl);
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *data, size_t count);
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s);
void *EVP_md5(void);
char *X509_NAME_oneline(X509_NAME *a, char *buf, int size);
void OPENSSL_free(void *ptr);