#include <stdlib.h>

typedef int krb5_error_code;
typedef void *krb5_context;
typedef struct pkinit_plg_crypto_context *pkinit_plg_crypto_context;
typedef struct pkinit_req_crypto_context *pkinit_req_crypto_context;
typedef struct pkinit_identity_crypto_context {
    void *my_certs;
    int cert_index;
} *pkinit_identity_crypto_context;

typedef struct X509 X509;
typedef struct X509_NAME X509_NAME;
typedef struct ASN1_INTEGER ASN1_INTEGER;
typedef struct PKCS7_ISSUER_AND_SERIAL {
    X509_NAME *issuer;
    ASN1_INTEGER *serial;
} PKCS7_ISSUER_AND_SERIAL;

#define KRB5KDC_ERR_PREAUTH_FAILED (-1)

X509 *sk_X509_value(void *sk, int index);
void pkiDebug(const char *fmt);
PKCS7_ISSUER_AND_SERIAL *d2i_PKCS7_ISSUER_AND_SERIAL(PKCS7_ISSUER_AND_SERIAL **a, const unsigned char **pp, long length);
int X509_NAME_cmp(X509_NAME *a, X509_NAME *b);
X509_NAME *X509_get_issuer_name(X509 *a);
int ASN1_INTEGER_cmp(ASN1_INTEGER *a, ASN1_INTEGER *b);
ASN1_INTEGER *X509_get_serialNumber(X509 *a);
void X509_NAME_free(X509_NAME *a);
void ASN1_INTEGER_free(ASN1_INTEGER *a);