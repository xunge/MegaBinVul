#include <string.h>
#include <unistd.h>

typedef struct ssl_st SSL;
typedef struct bio_st BIO;
typedef struct bio_method_st BIO_METHOD;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct kssl_ctx_st KSSL_CTX;
typedef struct srp_user_pwd_st {
    char *info;
} SRP_user_pwd;
typedef struct srp_vbase_st SRP_VBASE;

#define BIO_NOCLOSE 0
#define BIO_CLOSE 1
#define KSSL_SERVICE 0
#define KSSL_KEYTAB 1
#define BIO_RR_SSL_X509_LOOKUP 0
#define SSL_SENT_SHUTDOWN 1
#define SSL_RECEIVED_SHUTDOWN 2

extern int bufsize;
extern SSL_CTX *ctx;
extern BIO *bio_err;
extern BIO *bio_s_out;
extern BIO *bio_s_msg;
extern int s_debug;
extern int s_msg;
extern int s_quiet;
extern int s_ign_eof;
extern int s_tlsextdebug;
extern char KRB5SVC[];
extern char KRB5KEYTAB[];

struct srp_callback_parm_st {
    SRP_VBASE *vb;
    char *login;
    SRP_user_pwd *user;
} srp_callback_parm;

void *OPENSSL_malloc(int size);
void OPENSSL_free(void *ptr);
BIO_METHOD *BIO_f_buffer(void);
BIO_METHOD *BIO_f_ssl(void);
BIO *BIO_new(BIO_METHOD *type);
int BIO_set_write_buffer_size(BIO *b, int size);
SSL *SSL_new(SSL_CTX *ctx);
void SSL_set_bio(SSL *s, BIO *rbio, BIO *wbio);
void SSL_set_accept_state(SSL *s);
void BIO_set_ssl(BIO *b, SSL *ssl, int c);
BIO *BIO_push(BIO *b, BIO *append);
int BIO_do_handshake(BIO *b);
int BIO_should_retry(BIO *b);
int BIO_gets(BIO *b, char *buf, int size);
int BIO_write(BIO *b, const void *buf, int len);
int BIO_flush(BIO *b);
void BIO_free_all(BIO *a);
void SSL_set_shutdown(SSL *s, int mode);
void ERR_print_errors(BIO *bp);
int BIO_printf(BIO *bp, const char *format, ...);
int BIO_puts(BIO *bp, const char *buf);
void BUF_reverse(unsigned char *out, const unsigned char *in, size_t size);
BIO *BIO_new_socket(int sock, int close_flag);
void SSL_set_tlsext_debug_callback(SSL *ssl, void *cb);
void SSL_set_tlsext_debug_arg(SSL *ssl, void *arg);
KSSL_CTX *kssl_ctx_new(void);
void kssl_ctx_setstring(KSSL_CTX *kctx, int type, char *str);
void SSL_set_session_id_context(SSL *ssl, const unsigned char *sid_ctx, unsigned int sid_ctx_len);
void SSL_set_debug(SSL *ssl, int debug);
void BIO_set_callback(BIO *b, void (*cb)(BIO *, int, const char *, int, long, long));
BIO *SSL_get_rbio(const SSL *ssl);
void BIO_set_callback_arg(BIO *b, char *arg);
void SSL_set_msg_callback(SSL *ssl, void (*cb)(int, int, int, const void *, size_t, SSL *, void *));
void SSL_set_msg_callback_arg(SSL *ssl, void *arg);
int BIO_should_io_special(BIO *b);
int BIO_get_retry_reason(BIO *b);
SRP_user_pwd *SRP_VBASE_get_by_user(SRP_VBASE *vb, char *username);
void print_ssl_summary(BIO *bio, SSL *ssl);
void tlsext_cb(SSL *s, int client_server, int type, unsigned char *data, int len, void *arg);
void bio_dump_callback(BIO *bio, int cmd, const char *argp, int argi, long argl, long ret);
void SSL_trace(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg);
void msg_cb(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg);