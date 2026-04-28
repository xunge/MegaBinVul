#include <string.h>
#include <unistd.h>

/* Basic type definitions */
typedef struct SSL SSL;
typedef struct BIO BIO;
typedef struct X509 X509;
typedef struct SSL_CIPHER SSL_CIPHER;
typedef struct SSL_CTX SSL_CTX;
typedef struct SSL_SESSION SSL_SESSION;
typedef struct KSSL_CTX KSSL_CTX;
typedef struct STACK STACK;

/* Stack macros to replace OPENSSL's STACK_OF */
#define STACK_OF(type) struct stack_st_##type
#define sk_SSL_CIPHER_num(st) 0
#define sk_SSL_CIPHER_value(st, i) NULL

/* Constants and flags */
#define OPENSSL_NO_KRB5
#define OPENSSL_NO_TLSEXT
#define OPENSSL_NO_SRP
#define OPENSSL_NO_EC
#define OPENSSL_NO_SSL_TRACE
#define FIONBIO 1
#define BIO_NOCLOSE 1
#define BIO_CLOSE 1
#define SSL_ERROR_NONE 1
#define SSL_ERROR_WANT_READ 2
#define SSL_ERROR_WANT_WRITE 3
#define SSL_ERROR_WANT_X509_LOOKUP 4
#define SSL_ERROR_SYSCALL 5
#define SSL_ERROR_SSL 6
#define SSL_ERROR_ZERO_RETURN 7
#define BIO_RR_SSL_X509_LOOKUP 1
#define SSL_SENT_SHUTDOWN 1
#define SSL_RECEIVED_SHUTDOWN 2

/* External variables */
extern SSL_CTX *ctx;
extern int bufsize;
extern int s_nbio;
extern int s_quiet;
extern BIO *bio_err;
extern BIO *bio_s_out;
extern BIO *bio_s_msg;
extern int s_tlsextdebug;
extern int s_debug;
extern int s_msg;
extern int hack;
extern int www;
extern char **local_argv;
extern int local_argc;
extern int s_nbio_test;
extern int total_bytes;

/* Structure definitions */
struct srp_cb_parm_st {
    char *login;
    void *vb;
    void *user;
    char *info;
};
extern struct srp_cb_parm_st srp_callback_parm;

/* Function declarations */
/* Memory management */
extern void *OPENSSL_malloc(int size);
extern void OPENSSL_free(void *ptr);

/* BIO functions */
extern BIO *BIO_new(void *type);
extern void *BIO_f_buffer(void);
extern void *BIO_f_ssl(void);
extern int BIO_set_write_buffer_size(BIO *bio, int size);
extern int BIO_gets(BIO *bio, char *buf, int len);
extern int BIO_should_retry(BIO *bio);
extern int BIO_should_io_special(BIO *bio);
extern int BIO_get_retry_reason(BIO *bio);
extern int BIO_flush(BIO *bio);
extern void BIO_free_all(BIO *bio);
extern BIO *BIO_new_socket(int sock, int flags);
extern void *BIO_f_nbio_test(void);
extern BIO *BIO_push(BIO *bio, BIO *append);
extern BIO *BIO_new_file(const char *filename, const char *mode);
extern int BIO_read(BIO *bio, void *buf, int len);
extern int BIO_write(BIO *bio, const void *buf, int len);
extern int BIO_printf(BIO *bio, const char *format, ...);
extern int BIO_puts(BIO *bio, const char *str);
extern void BIO_set_ssl(BIO *bio, SSL *ssl, int flags);
extern void BIO_set_callback(BIO *bio, void *callback);
extern void BIO_set_callback_arg(BIO *bio, void *arg);
extern int BIO_socket_ioctl(int fd, int type, void *arg);
extern void BIO_free(BIO *bio);

/* SSL functions */
extern SSL *SSL_new(SSL_CTX *ctx);
extern int SSL_set_tlsext_debug_callback(SSL *ssl, void *cb);
extern void SSL_set_tlsext_debug_arg(SSL *ssl, BIO *bio);
extern int SSL_set_session_id_context(SSL *ssl, unsigned char *sid_ctx, unsigned int sid_ctx_len);
extern void SSL_set_bio(SSL *ssl, BIO *rbio, BIO *wbio);
extern void SSL_set_accept_state(SSL *ssl);
extern void SSL_set_debug(SSL *ssl, int debug);
extern BIO *SSL_get_rbio(SSL *ssl);
extern int SSL_set_msg_callback(SSL *ssl, void *cb);
extern void SSL_set_msg_callback_arg(SSL *ssl, BIO *bio);
extern int SSL_accept(SSL *ssl);
extern int SSL_get_error(SSL *ssl, int ret);
extern void SSL_renegotiate(SSL *ssl);
extern int SSL_write(SSL *ssl, const void *buf, int len);
extern STACK *SSL_get_ciphers(SSL *ssl);
extern char *SSL_get_shared_ciphers(SSL *ssl, char *buf, int len);
extern int SSL_cache_hit(SSL *ssl);
extern SSL_CIPHER *SSL_get_current_cipher(SSL *ssl);
extern void SSL_SESSION_print(BIO *bio, SSL_SESSION *session);
extern X509 *SSL_get_peer_certificate(SSL *ssl);
extern SSL_CTX *SSL_get_SSL_CTX(SSL *ssl);
extern void SSL_set_shutdown(SSL *ssl, int mode);
extern int SSL_get_secure_renegotiation_support(SSL *ssl);
extern SSL_SESSION *SSL_get_session(SSL *ssl);

/* X509 functions */
extern int X509_print(BIO *bio, X509 *x509);
extern int PEM_write_bio_X509(BIO *bio, X509 *x509);

/* Error handling */
extern int ERR_print_errors(BIO *bio);

/* Utility functions */
extern int app_isdir(const char *path);
extern void ssl_print_sigalgs(BIO *bio, SSL *s);
extern void ssl_print_curves(BIO *bio, SSL *s, int noshared);
extern void print_stats(BIO *bio, SSL_CTX *ssl_ctx);

/* Callback functions */
extern void bio_dump_callback(BIO *bio, int cmd, const char *argp, 
                            int argi, long argl, long ret);
extern void msg_cb(int write_p, int version, int content_type, 
                  const void *buf, size_t len, SSL *ssl, void *arg);