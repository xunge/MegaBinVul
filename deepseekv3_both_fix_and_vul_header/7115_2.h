#include <stddef.h>

typedef struct pkcs7_st {
    struct {
        void *ptr;
    } d;
} PKCS7;

typedef struct pkcs7_ctx_st PKCS7_CTX;
typedef struct ossl_lib_ctx_st OSSL_LIB_CTX;
typedef struct pkcs7_recip_info_st {
    struct x509_st *cert;
} PKCS7_RECIP_INFO;
typedef struct pkcs7_signer_info_st {
    const PKCS7_CTX *ctx;
} PKCS7_SIGNER_INFO;
typedef struct x509_st X509;

struct stack_st;
#define STACK_OF(type) struct stack_st
typedef STACK_OF(PKCS7_RECIP_INFO) *stack_st_PKCS7_RECIP_INFO;
typedef STACK_OF(PKCS7_SIGNER_INFO) *stack_st_PKCS7_SIGNER_INFO;
typedef STACK_OF(X509) *stack_st_X509;

const PKCS7_CTX *ossl_pkcs7_get0_ctx(PKCS7 *p7);
OSSL_LIB_CTX *ossl_pkcs7_ctx_get0_libctx(const PKCS7_CTX *ctx);
const char *ossl_pkcs7_ctx_get0_propq(const PKCS7_CTX *ctx);
stack_st_PKCS7_RECIP_INFO *pkcs7_get_recipient_info(PKCS7 *p7);
stack_st_PKCS7_SIGNER_INFO *PKCS7_get_signer_info(PKCS7 *p7);
stack_st_X509 *pkcs7_get_signer_certs(PKCS7 *p7);
int sk_X509_num(const stack_st_X509 *sk);
X509 *sk_X509_value(const stack_st_X509 *sk, int idx);
void ossl_x509_set0_libctx(X509 *x, OSSL_LIB_CTX *libctx, const char *propq);
int sk_PKCS7_RECIP_INFO_num(const stack_st_PKCS7_RECIP_INFO *sk);
PKCS7_RECIP_INFO *sk_PKCS7_RECIP_INFO_value(const stack_st_PKCS7_RECIP_INFO *sk, int idx);
int sk_PKCS7_SIGNER_INFO_num(const stack_st_PKCS7_SIGNER_INFO *sk);
PKCS7_SIGNER_INFO *sk_PKCS7_SIGNER_INFO_value(const stack_st_PKCS7_SIGNER_INFO *sk, int idx);