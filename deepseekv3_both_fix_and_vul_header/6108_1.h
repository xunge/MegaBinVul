#include <stddef.h>

typedef struct pj_ssl_sock_t pj_ssl_sock_t;
typedef struct X509_STORE_CTX X509_STORE_CTX;
typedef struct SSL SSL;

typedef int pj_bool_t;
#define PJ_FALSE 0
#define PJ_TRUE 1

#define PJ_SSL_CERT_EISSUER_NOT_FOUND  (1 << 0)
#define PJ_SSL_CERT_EINVALID_FORMAT    (1 << 1)
#define PJ_SSL_CERT_EVALIDITY_PERIOD   (1 << 2)
#define PJ_SSL_CERT_ECRL_FAILURE      (1 << 3)
#define PJ_SSL_CERT_EUNTRUSTED        (1 << 4)
#define PJ_SSL_CERT_EISSUER_MISMATCH  (1 << 5)
#define PJ_SSL_CERT_EREVOKED          (1 << 6)
#define PJ_SSL_CERT_EINVALID_PURPOSE  (1 << 7)
#define PJ_SSL_CERT_ECHAIN_TOO_LONG   (1 << 8)
#define PJ_SSL_CERT_EUNKNOWN          (1 << 9)

#define X509_V_OK 0
#define X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT 1
#define X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD 2
#define X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD 3
#define X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE 4
#define X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY 5
#define X509_V_ERR_CERT_NOT_YET_VALID 6
#define X509_V_ERR_CERT_HAS_EXPIRED 7
#define X509_V_ERR_UNABLE_TO_GET_CRL 8
#define X509_V_ERR_CRL_NOT_YET_VALID 9
#define X509_V_ERR_CRL_HAS_EXPIRED 10
#define X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE 11
#define X509_V_ERR_CRL_SIGNATURE_FAILURE 12
#define X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD 13
#define X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD 14
#define X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT 15
#define X509_V_ERR_CERT_UNTRUSTED 16
#define X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN 17
#define X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY 18
#define X509_V_ERR_CERT_SIGNATURE_FAILURE 19
#define X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE 20
#define X509_V_ERR_SUBJECT_ISSUER_MISMATCH 21
#define X509_V_ERR_AKID_SKID_MISMATCH 22
#define X509_V_ERR_AKID_ISSUER_SERIAL_MISMATCH 23
#define X509_V_ERR_KEYUSAGE_NO_CERTSIGN 24
#define X509_V_ERR_CERT_REVOKED 25
#define X509_V_ERR_INVALID_PURPOSE 26
#define X509_V_ERR_CERT_REJECTED 27
#define X509_V_ERR_INVALID_CA 28
#define X509_V_ERR_CERT_CHAIN_TOO_LONG 29
#define X509_V_ERR_PATH_LENGTH_EXCEEDED 30
#define X509_V_ERR_OUT_OF_MEM 31

extern int sslsock_idx;
extern const char *THIS_FILE;

struct pj_ssl_sock_t {
    unsigned verify_status;
    struct {
        pj_bool_t verify_peer;
    } param;
};

#define PJ_LOG(level, args)

static inline SSL *X509_STORE_CTX_get_ex_data(X509_STORE_CTX *ctx, int idx) { return NULL; }
static inline int SSL_get_ex_data_X509_STORE_CTX_idx(void) { return 0; }
static inline pj_ssl_sock_t *SSL_get_ex_data(SSL *ssl, int idx) { return NULL; }
static inline int X509_STORE_CTX_get_error(X509_STORE_CTX *ctx) { return 0; }