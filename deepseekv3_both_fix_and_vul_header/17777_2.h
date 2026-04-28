#include <stdint.h>
#include <string.h>

typedef struct rfbClient {
    char *serverHost;
} rfbClient;

typedef int rfbBool;

typedef enum {
    rfbX509CrlVerifyNone,
    rfbX509CrlVerifyClient,
    rfbX509CrlVerifyAll
} rfbX509CrlVerifyMode;

typedef struct {
    char *x509CACertFile;
    char *x509CACrlFile;
    char *x509ClientCertFile;
    char *x509ClientKeyFile;
    rfbX509CrlVerifyMode x509CrlVerifyMode;
} rfbX509Credential;

typedef struct {
    rfbX509Credential x509Credential;
} rfbCredential;

struct SSL;
struct SSL_CTX;
struct X509_VERIFY_PARAM;

typedef struct SSL SSL;
typedef struct SSL_CTX SSL_CTX;
typedef struct X509_VERIFY_PARAM X509_VERIFY_PARAM;

#define SSL_FILETYPE_PEM 1
#define SSL_VERIFY_PEER 1
#define X509_V_FLAG_CRL_CHECK 0x4
#define X509_V_FLAG_CRL_CHECK_ALL 0x8

extern SSL_CTX *SSL_CTX_new(void *method);
extern void *SSLv23_client_method(void);
extern X509_VERIFY_PARAM *X509_VERIFY_PARAM_new(void);
extern int SSL_CTX_load_verify_locations(SSL_CTX *ctx, const char *cafile, const char *capath);
extern void SSL_CTX_set_default_verify_paths(SSL_CTX *ctx);
extern int SSL_CTX_use_certificate_chain_file(SSL_CTX *ctx, const char *file);
extern int SSL_CTX_use_PrivateKey_file(SSL_CTX *ctx, const char *file, int type);
extern int SSL_CTX_check_private_key(SSL_CTX *ctx);
extern void SSL_CTX_set_verify(SSL_CTX *ctx, int mode, void *callback);
extern void X509_VERIFY_PARAM_set_flags(X509_VERIFY_PARAM *param, unsigned long flags);
extern int X509_VERIFY_PARAM_set1_host(X509_VERIFY_PARAM *param, const char *name, size_t namelen);
extern void SSL_CTX_set1_param(SSL_CTX *ctx, X509_VERIFY_PARAM *param);
extern SSL *SSL_new(SSL_CTX *ctx);
extern int SSL_set_cipher_list(SSL *ssl, const char *str);
extern int SSL_set_fd(SSL *ssl, int fd);
extern void SSL_CTX_set_app_data(SSL_CTX *ctx, void *data);
extern int SSL_connect(SSL *ssl);
extern int SSL_shutdown(SSL *ssl);
extern void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param);
extern void SSL_free(SSL *ssl);
extern void SSL_CTX_free(SSL_CTX *ctx);
extern int wait_for_data(SSL *ssl, int n, int timeout);
extern int load_crls_from_file(const char *file, SSL_CTX *ssl_ctx);
extern void rfbClientLog(const char *format, ...);