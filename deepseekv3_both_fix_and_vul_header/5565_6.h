#include <stddef.h>

typedef struct X509_st X509;
typedef struct X509_store_st X509_STORE;
typedef struct X509_store_ctx_st X509_STORE_CTX;
typedef struct bio_st BIO;

typedef struct {
    X509 **data;
    int num;
} STACK_OF_X509;

typedef struct {
    void *issuer;
    void *serial;
} PKCS7_ISSUER_AND_SERIAL;

typedef struct {
    PKCS7_ISSUER_AND_SERIAL *issuer_and_serial;
} PKCS7_SIGNER_INFO;

typedef struct {
    STACK_OF_X509 *cert;
} PKCS7_SIGNED;

typedef struct {
    STACK_OF_X509 *cert;
} PKCS7_SIGNEDANDENVELOPED;

typedef struct {
    union {
        void *ptr;
        PKCS7_SIGNED *sign;
        PKCS7_SIGNEDANDENVELOPED *signed_and_enveloped;
    } d;
} PKCS7;

#define PKCS7_F_PKCS7_DATAVERIFY 0
#define PKCS7_R_INVALID_NULL_POINTER 0
#define PKCS7_R_NO_CONTENT 0
#define PKCS7_R_WRONG_PKCS7_TYPE 0
#define PKCS7_R_UNABLE_TO_FIND_CERTIFICATE 0
#define ERR_R_X509_LIB 0
#define X509_PURPOSE_SMIME_SIGN 0

void PKCS7err(int a, int b);
int PKCS7_type_is_signed(PKCS7 *p7);
int PKCS7_type_is_signedAndEnveloped(PKCS7 *p7);
X509 *X509_find_by_issuer_and_serial(STACK_OF_X509 *cert, void *issuer, void *serial);
int X509_STORE_CTX_init(X509_STORE_CTX *ctx, X509_STORE *store, X509 *x509, STACK_OF_X509 *chain);
void X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx, int purpose);
int X509_verify_cert(X509_STORE_CTX *ctx);
void X509_STORE_CTX_cleanup(X509_STORE_CTX *ctx);
int PKCS7_signatureVerify(BIO *bio, PKCS7 *p7, PKCS7_SIGNER_INFO *si, X509 *x509);

#define STACK_OF(type) struct { type **data; int num; }