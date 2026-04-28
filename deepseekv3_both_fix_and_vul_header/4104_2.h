#include <stdio.h>
#include <string.h>

#define BUFSIZ 8192
#define MS_STATIC static
#define SSL_ERROR_WANT_X509_LOOKUP 1
#define X509_V_OK 0
#define SSL_CTRL_GET_FLAGS 1
#define TLS1_FLAGS_TLS_PADDING_BUG 1

typedef struct SSL SSL;
typedef struct X509 X509;
typedef struct BIO BIO;
typedef struct SRP_user_pwd {
    char *info;
} SRP_user_pwd;
typedef struct SRP_VBASE SRP_VBASE;
typedef struct SRTP_PROTECTION_PROFILE {
    char *name;
} SRTP_PROTECTION_PROFILE;

extern BIO *bio_s_out;
extern BIO *bio_err;
extern int s_brief;
extern char *keymatexportlabel;
extern int keymatexportlen;

struct srp_callback_parm_st {
    char *login;
    SRP_user_pwd *user;
    SRP_VBASE *vb;
};
extern struct srp_callback_parm_st srp_callback_parm;

int SSL_accept(SSL *ssl);
int SSL_get_error(SSL *ssl, int ret);
int BIO_printf(BIO *bio, const char *format, ...);
int BIO_write(BIO *bio, const void *buf, int len);
int BIO_sock_should_retry(int i);
long SSL_get_verify_result(SSL *ssl);
const char *X509_verify_cert_error_string(long n);
void ERR_print_errors(BIO *bio);
void *OPENSSL_malloc(int size);
void OPENSSL_free(void *addr);
int SSL_export_keying_material(SSL *ssl, void *out, size_t olen,
                              const char *label, size_t llen,
                              const void *context, size_t contextlen, int use_context);

void print_ssl_summary(BIO *bio, SSL *ssl);
void ssl_print_sigalgs(BIO *bio, SSL *ssl);
void ssl_print_point_formats(BIO *bio, SSL *ssl);
void ssl_print_curves(BIO *bio, SSL *ssl, int noshared);