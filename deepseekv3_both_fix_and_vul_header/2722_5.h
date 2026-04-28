#include <stddef.h>

struct X509;
struct X509_STORE;
struct EVP_PKEY;
struct stack_st_X509;
struct ocsp_basic_response_st;

typedef struct X509_STORE_CTX {
    struct X509_STORE *ctx;
    struct X509 *cert;
    struct stack_st_X509 *chain;
} X509_STORE_CTX;

typedef struct X509_STORE X509_STORE;
typedef struct X509 X509;
typedef struct EVP_PKEY EVP_PKEY;
typedef struct stack_st_X509 STACK_OF_X509;
typedef struct ocsp_basic_response_st {
    STACK_OF_X509 *certs;
} OCSP_BASICRESP;

#define STACK_OF(X) STACK_OF_##X
#define STACK_OF_X509 STACK_OF_X509

#define OCSP_TRUSTOTHER 0x1
#define OCSP_NOVERIFY 0x2
#define OCSP_NOSIGS 0x4
#define OCSP_NOCHAIN 0x8
#define OCSP_NOCHECKS 0x10
#define OCSP_NOEXPLICIT 0x20

#define OCSP_F_OCSP_BASIC_VERIFY 0
#define OCSP_R_SIGNER_CERTIFICATE_NOT_FOUND 0
#define OCSP_R_SIGNATURE_FAILURE 0
#define OCSP_R_CERTIFICATE_VERIFY_ERROR 0
#define OCSP_R_ROOT_CA_NOT_TRUSTED 0
#define ERR_R_X509_LIB 0

#define X509_PURPOSE_OCSP_HELPER 0
#define X509_TRUST_TRUSTED 1
#define NID_OCSP_sign 0

int ocsp_find_signer(X509 **signer, OCSP_BASICRESP *bs, STACK_OF_X509 *certs, X509_STORE *st, unsigned long flags);
int OCSP_BASICRESP_verify(OCSP_BASICRESP *bs, EVP_PKEY *pkey, int md);
int X509_STORE_CTX_init(X509_STORE_CTX *ctx, X509_STORE *store, X509 *x509, STACK_OF_X509 *chain);
void X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx, int purpose);
int X509_verify_cert(X509_STORE_CTX *ctx);
STACK_OF_X509 *X509_STORE_CTX_get1_chain(X509_STORE_CTX *ctx);
void X509_STORE_CTX_cleanup(X509_STORE_CTX *ctx);
int X509_STORE_CTX_get_error(X509_STORE_CTX *ctx);
const char *X509_verify_cert_error_string(int n);
int ocsp_check_issuer(OCSP_BASICRESP *bs, STACK_OF_X509 *chain, unsigned long flags);
int X509_check_trust(X509 *x, int id, int flags);
void OCSPerr(int f, int r);
void ERR_add_error_data(int num, ...);
EVP_PKEY *X509_get_pubkey(X509 *x);
void EVP_PKEY_free(EVP_PKEY *pkey);
X509 *sk_X509_value(STACK_OF_X509 *sk, int i);
int sk_X509_num(STACK_OF_X509 *sk);
void sk_X509_pop_free(STACK_OF_X509 *sk, void (*func)(X509*));
void X509_free(X509 *a);