#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct bio_st BIO;
typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct kssl_ctx_st KSSL_CTX;

#define OPENSSL_NO_KRB5
#define OPENSSL_NO_TLSEXT
#define OPENSSL_NO_JPAKE
#define OPENSSL_NO_SRP
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_SSL_TRACE

#define SOCK_DGRAM 2
#define BIO_NOCLOSE 0
#define SSL_OP_NO_QUERY_MTU 0
#define SSL_OP_COOKIE_EXCHANGE 0
#define DTLS1_VERSION 0
#define SSL_ERROR_NONE 0
#define SSL_ERROR_WANT_READ 2
#define SSL_ERROR_WANT_WRITE 3
#define SSL_ERROR_SYSCALL 5
#define SSL_ERROR_SSL 1
#define SSL_ERROR_ZERO_RETURN 6
#define SSL_SENT_SHUTDOWN 1
#define SSL_RECEIVED_SHUTDOWN 2
#define SSL_VERIFY_PEER 1
#define SSL_VERIFY_CLIENT_ONCE 2
#define SSL_ERROR_WANT_X509_LOOKUP 7
#define BIO_CTRL_DGRAM_SET_RECV_TIMEOUT 0
#define BIO_CTRL_DGRAM_SET_SEND_TIMEOUT 0
#define BIO_CTRL_DGRAM_MTU_DISCOVER 0
#define DGRAM_RCV_TIMEOUT 0
#define DGRAM_SND_TIMEOUT 0

struct tlsextstatus {
    BIO *err;
};

extern BIO *bio_err;
extern BIO *bio_s_out;
extern BIO *bio_s_msg;
extern SSL_CTX *ctx;
extern int bufsize;
extern int s_nbio;
extern int s_quiet;
extern int s_tlsextdebug;
extern int s_tlsextstatus;
extern int enable_timeouts;
extern int socket_mtu;
extern int s_nbio_test;
extern int s_debug;
extern int s_msg;
extern int s_crlf;
extern int s_brief;
extern char *jpake_secret;
extern struct tlsextstatus tlscstatp;
extern int (*msg_cb)(int write_p, int version, int content_type, const void *buf, size_t len, SSL *ssl, void *arg);
extern int (*tlsext_cb)(SSL *s, int client_server, int type, unsigned char *data, int len, void *arg);
extern int (*cert_status_cb)(SSL *ssl, void *arg);
extern int (*init_ssl_connection)(SSL *con);
extern int (*bio_dump_callback)(BIO *bio, int cmd, const char *argp, int argi, long argl, long ret);