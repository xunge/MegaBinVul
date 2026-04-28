#include <stdlib.h>
#include <stddef.h>

#define SSL_F_TLS1_SET_SERVER_SIGALGS 0
#define SSL_PKEY_NUM 0
#define SSL_AD_INTERNAL_ERROR 0
#define SSL_AD_ILLEGAL_PARAMETER 0
#define SSL_R_NO_SHARED_SIGATURE_ALGORITHMS 0
#define SSL3_AL_FATAL 0
#define ERR_R_MALLOC_FAILURE 0

typedef struct ssl_cert_st {
    void **shared_sigalgs;
    void **peer_sigalgs;
    size_t shared_sigalgslen;
    struct {
        void *digest;
        int valid_flags;
    } pkeys[SSL_PKEY_NUM];
} SSL_CERT;

typedef struct ssl_st {
    SSL_CERT *cert;
} SSL;

void OPENSSL_free(void *ptr);
void SSLerr(int function, int reason);
int tls1_process_sigalgs(SSL *s);
void ssl_cert_set_default_md(SSL_CERT *cert);
void ssl3_send_alert(SSL *s, int level, int al);