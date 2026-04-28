#include <stdlib.h>
#include <stdio.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct x509_st X509;
typedef struct x509_name_st X509_NAME;
typedef struct evp_md_st EVP_MD;

#define X509_V_OK 0
#define EVP_MAX_MD_SIZE 64

const EVP_MD *EVP_md5(void);
int SSL_get_verify_result(const SSL *ssl);
X509_NAME *X509_get_subject_name(X509 *x);
X509_NAME *X509_get_issuer_name(X509 *x);
char *X509_NAME_oneline(X509_NAME *a, char *buf, int size);
int X509_digest(const X509 *x, const EVP_MD *type, unsigned char *md, unsigned int *len);

void g_warning(const char *format, ...);