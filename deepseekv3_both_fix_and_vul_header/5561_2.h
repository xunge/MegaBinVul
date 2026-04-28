#include <stdlib.h>

typedef struct ASN1_STRING_st {
    int length;
    unsigned char *data;
} ASN1_STRING;

typedef struct X509_req_info_st {
    ASN1_STRING *version;
    void *subject;
    void *pubkey;
} X509_REQ_INFO;

typedef struct X509_req_st {
    X509_REQ_INFO *req_info;
} X509_REQ;

typedef struct evp_pkey_st EVP_PKEY;
typedef struct env_md_st EVP_MD;
typedef struct X509_st X509;

#define X509_F_X509_TO_X509_REQ 0
#define ERR_R_MALLOC_FAILURE 0

void *OPENSSL_malloc(size_t size);
void X509err(int a, int b);
void EVP_PKEY_free(EVP_PKEY *pkey);
int X509_REQ_set_pubkey(X509_REQ *req, EVP_PKEY *pkey);
EVP_PKEY *X509_get_pubkey(X509 *x);
int X509_REQ_set_subject_name(X509_REQ *req, void *name);
void *X509_get_subject_name(X509 *x);
int X509_REQ_sign(X509_REQ *req, EVP_PKEY *pkey, const EVP_MD *md);
void X509_REQ_free(X509_REQ *req);
X509_REQ *X509_REQ_new();