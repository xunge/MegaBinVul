#include <stdio.h>

struct config {
    int insecure;
};

extern struct config *conf;

typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct x509_st X509;

#define SSL_MODE_AUTO_RETRY 0
#define SSL_VERIFY_PEER 0
#define X509_V_OK 0

void ssl_startup(void);
SSL_CTX *SSL_CTX_new(void *method);
void SSL_CTX_free(SSL_CTX *ctx);
void SSL_CTX_set_default_verify_paths(SSL_CTX *ctx);
void SSL_CTX_set_verify(SSL_CTX *ctx, int mode, void *cb);
void SSL_CTX_set_mode(SSL_CTX *ctx, int mode);
SSL *SSL_new(SSL_CTX *ctx);
void SSL_set_fd(SSL *ssl, int fd);
void SSL_set_tlsext_host_name(SSL *ssl, const char *name);
int SSL_connect(SSL *ssl);
char *ERR_reason_error_string(unsigned long e);
unsigned long ERR_get_error();
int SSL_get_verify_result(SSL *ssl);
X509 *SSL_get_peer_certificate(SSL *ssl);
void X509_free(X509 *x);
int ssl_validate_hostname(const char *hostname, X509 *cert);