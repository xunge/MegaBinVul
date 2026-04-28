#include <stddef.h>

typedef enum WORK_STATE {
    WORK_MORE_A,
    WORK_ERROR,
    WORK_FINISHED_CONTINUE
} WORK_STATE;

typedef struct SSL_CERT_LOOKUP {
    unsigned long amask;
} SSL_CERT_LOOKUP;

typedef struct SSL {
    int rwstate;
    int verify_mode;
    int verify_result;
    struct {
        struct {
            struct {
                unsigned long algorithm_auth;
            } *new_cipher;
        } tmp;
    } s3;
    unsigned char cert_verify_hash[64];
    size_t cert_verify_hash_len;
    struct {
        void *peer_chain;
        void *peer;
        int verify_result;
    } *session;
} SSL;

#define SSL_RETRY_VERIFY 1
#define SSL_VERIFY_NONE 0
#define SSL_VERIFY_PEER 1
#define SSL_R_CERTIFICATE_VERIFY_FAILED 1
#define SSL_AD_INTERNAL_ERROR 1
#define SSL_R_UNABLE_TO_FIND_PUBLIC_KEY_PARAMETERS 1
#define SSL_AD_ILLEGAL_PARAMETER 1
#define SSL_R_UNKNOWN_CERTIFICATE_TYPE 1
#define SSL_R_WRONG_CERTIFICATE_TYPE 1
#define SSL_IS_TLS13(s) (0)

typedef void X509;
typedef void EVP_PKEY;

int ssl_verify_cert_chain(SSL *s, void *chain);
void SSLfatal(SSL *s, int alert, int reason);
void ERR_clear_error(void);
void *sk_X509_value(void *sk, int idx);
EVP_PKEY *X509_get0_pubkey(X509 *x);
int EVP_PKEY_missing_parameters(EVP_PKEY *pkey);
const SSL_CERT_LOOKUP *ssl_cert_lookup_by_pkey(EVP_PKEY *pkey, size_t *pidx);
int ssl_x509err2alert(int err);
int ssl_handshake_hash(SSL *s, unsigned char *hash, size_t hash_len, size_t *out_len);
void X509_free(X509 *x);
void X509_up_ref(X509 *x);