#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct ssl3_record_st SSL3_RECORD;
typedef struct bio_st BIO;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_cipher_st SSL_CIPHER;

struct ssl3_buffer_st {
    unsigned char *buf;
    unsigned int left;
};

struct ssl3_record_st {
    unsigned char type;
    unsigned char *data;
    unsigned int off;
    unsigned int length;
};

struct ssl3_state_st {
    struct ssl3_buffer_st rbuf;
    struct ssl3_record_st rrec;
    int change_cipher_spec;
    unsigned char handshake_fragment[4];
    unsigned int handshake_fragment_len;
    unsigned char alert_fragment[2];
    unsigned int alert_fragment_len;
    int flags;
    int renegotiate;
    int send_connection_binding;
    int in_read_app_data;
    int total_renegotiations;
    int warn_alert;
    int fatal_alert;
    struct {
        SSL_CIPHER *new_cipher;
    } tmp;
};

struct ssl_st {
    SSL3_STATE *s3;
    int in_handshake;
    int rwstate;
    int rstate;
    int mode;
    int server;
    int shutdown;
    int version;
    int state;
    int renegotiate;
    int new_session;
    SSL_SESSION *session;
    SSL_CTX *ctx;
    void *msg_callback_arg;
    void (*msg_callback)(int, int, int, const void *, size_t, SSL *, void *);
    void (*info_callback)(const SSL *, int, int);
    void *enc_read_ctx;
    int (*handshake_func)(SSL *);
};

struct ssl_session_st {
    SSL_CIPHER *cipher;
};

struct ssl_ctx_st {
    int options;
    void (*info_callback)(const SSL *, int, int);
};

#define SSL_F_SSL3_READ_BYTES 0
#define SSL_R_SSL_HANDSHAKE_FAILURE 0
#define SSL_R_DATA_BETWEEN_CCS_AND_FINISHED 0
#define SSL_R_APP_DATA_IN_HANDSHAKE 0
#define SSL_R_NO_RENEGOTIATION 0
#define SSL_R_UNKNOWN_ALERT_TYPE 0
#define SSL_R_BAD_CHANGE_CIPHER_SPEC 0
#define SSL_R_CCS_RECEIVED_EARLY 0
#define SSL_R_UNEXPECTED_RECORD 0
#define SSL_R_BAD_HELLO_REQUEST 0
#define SSL_R_INTERNAL_ERROR 0

#define SSL_AD_UNEXPECTED_MESSAGE 0
#define SSL_AD_DECODE_ERROR 0
#define SSL_AD_NO_RENEGOTIATION 0
#define SSL_AD_HANDSHAKE_FAILURE 0
#define SSL_AD_ILLEGAL_PARAMETER 0
#define SSL_AD_REASON_OFFSET 0
#define SSL_AD_CLOSE_NOTIFY 0

#define SSL3_RT_APPLICATION_DATA 0x17
#define SSL3_RT_HANDSHAKE 0x16
#define SSL3_RT_ALERT 0x15
#define SSL3_RT_CHANGE_CIPHER_SPEC 0x14
#define TLS1_RT_HEARTBEAT 0x18

#define SSL3_MT_HELLO_REQUEST 0
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_MT_CCS 1

#define SSL_ST_MASK 0x0FFF
#define SSL_ST_OK 0x03
#define SSL_ST_BEFORE 0x4000
#define SSL_ST_ACCEPT 0x8000
#define SSL_ST_CONNECT 0x10000
#define SSL_ST_READ_BODY 0x100
#define SSL_ST_READ_HEADER 0x200

#define SSL3_ST_CW_CLNT_HELLO_A 0x210
#define SSL3_ST_CR_SRVR_HELLO_A 0x220
#define SSL3_ST_SW_HELLO_REQ_A 0x110
#define SSL3_ST_SR_CLNT_HELLO_A 0x120

#define SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS 0x0001
#define SSL3_FLAGS_SEND_CONNECTION_BINDING 0x0002
#define SSL3_FLAGS_CCS_OK 0x0004

#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x0004

#define SSL_MODE_RELEASE_BUFFERS 0x00000010
#define SSL_MODE_AUTO_RETRY 0x00000020

#define SSL_CB_READ_ALERT 0x4000

#define SSL_RECEIVED_SHUTDOWN 0x01
#define SSL_SENT_SHUTDOWN 0x02
#define SSL_READING 0x04
#define SSL_NOTHING 0x05

#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301
#define TLS1_1_VERSION 0x0302

#define SSL3_AL_WARNING 1
#define SSL3_AL_FATAL 2

#define ERR_R_INTERNAL_ERROR 1

void SSLerr(int f, int r);
void ERR_add_error_data(int num, ...);
int BIO_snprintf(char *buf, size_t n, const char *format, ...);
void BIO_clear_retry_flags(BIO *bio);
void BIO_set_retry_read(BIO *bio);
BIO *SSL_get_rbio(SSL *s);
int SSL_in_init(SSL *s);
int SSL_is_init_finished(SSL *s);
int ssl3_setup_read_buffer(SSL *s);
int ssl3_get_record(SSL *s);
void ssl3_release_read_buffer(SSL *s);
int ssl3_do_change_cipher_spec(SSL *s);
void ssl3_send_alert(SSL *s, int level, int desc);
void ssl3_renegotiate(SSL *s);
int ssl3_renegotiate_check(SSL *s);
void SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *sess);
int tls1_process_heartbeat(SSL *s);