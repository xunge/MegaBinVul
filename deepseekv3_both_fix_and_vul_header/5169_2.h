#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bio_st BIO;
typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct ssl3_record_st SSL3_RECORD;
typedef struct ssl3_buffer_st SSL3_BUFFER;
typedef struct ssl_cert_st CERT;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;

#define SSL_F_SSL3_READ_BYTES 100
#define ERR_R_INTERNAL_ERROR 1
#define SSL3_RT_APPLICATION_DATA 23
#define SSL3_RT_HANDSHAKE 22
#define SSL3_RT_ALERT 21
#define SSL3_RT_CHANGE_CIPHER_SPEC 20
#define TLS1_RT_HEARTBEAT 24
#define SSL3_MT_HELLO_REQUEST 0
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_MT_CCS 1
#define SSL3_AL_WARNING 1
#define SSL3_AL_FATAL 2
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_NO_RENEGOTIATION 100
#define SSL_AD_CLOSE_NOTIFY 0
#define SSL_AD_REASON_OFFSET 1000
#define SSL_R_SSL_HANDSHAKE_FAILURE 1
#define SSL_R_APP_DATA_IN_HANDSHAKE 2
#define SSL_R_BAD_HELLO_REQUEST 3
#define SSL_R_NO_RENEGOTIATION 4
#define SSL_R_UNEXPECTED_RECORD 5
#define SSL_R_TOO_MANY_WARN_ALERTS 6
#define SSL_R_DATA_BETWEEN_CCS_AND_FINISHED 7
#define SSL_R_BAD_CHANGE_CIPHER_SPEC 8
#define SSL_R_CCS_RECEIVED_EARLY 9
#define SSL_R_UNKNOWN_ALERT_TYPE 10
#define SSL_CB_READ_ALERT 0x400
#define SSL_ST_READ_HEADER 1
#define SSL_ST_READ_BODY 2
#define SSL_ST_OK 3
#define SSL_ST_ERR 4
#define SSL_ST_CONNECT 5
#define SSL_ST_ACCEPT 6
#define SSL_ST_BEFORE 7
#define SSL_ST_MASK 0xFF
#define SSL3_ST_CW_CLNT_HELLO_A 10
#define SSL3_ST_CR_SRVR_HELLO_A 11
#define SSL3_ST_SW_HELLO_REQ_A 12
#define SSL3_ST_SR_CLNT_HELLO_A 13
#define SSL3_HM_HEADER_LENGTH 4
#define SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS 0x0001
#define SSL3_FLAGS_CCS_OK 0x0002
#define MAX_WARN_ALERT_COUNT 5
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x0004
#define SSL_MODE_RELEASE_BUFFERS 0x0001
#define SSL_MODE_AUTO_RETRY 0x0002
#define SSL_NOTHING 0
#define SSL_READING 1
#define SSL_WRITING 2
#define SSL_SENT_SHUTDOWN 1
#define SSL_RECEIVED_SHUTDOWN 2
#define SSL3_VERSION 0x0300
#define SSL_VERSION_SSL3 0x0300
#define SSL_VERSION_TLS1 0x0301
#define SSL_VERSION_TLS1_1 0x0302
#define SSL_VERSION_TLS1_2 0x0303

struct ssl3_record_st {
    int type;
    unsigned int length;
    unsigned int off;
    unsigned char *data;
};

struct ssl3_buffer_st {
    unsigned char *buf;
    unsigned int left;
};

struct ssl_cipher_st {
    int dummy;
};

struct ssl3_state_st {
    SSL3_BUFFER rbuf;
    SSL3_RECORD rrec;
    unsigned char handshake_fragment[4];
    unsigned int handshake_fragment_len;
    unsigned char alert_fragment[2];
    unsigned int alert_fragment_len;
    int warn_alert;
    int fatal_alert;
    int change_cipher_spec;
    int flags;
    int in_read_app_data;
    int total_renegotiations;
    int renegotiate;
    int send_connection_binding;
    unsigned int previous_client_finished_len;
    struct {
        struct ssl_cipher_st *new_cipher;
    } tmp;
};

struct ssl_cert_st {
    int alert_count;
};

struct ssl_session_st {
    struct ssl_cipher_st *cipher;
};

struct ssl_ctx_st {
    void (*info_callback)(const SSL *ssl, int type2, int val);
};

struct ssl_st {
    int version;
    int state;
    int rstate;
    int server;
    int shutdown;
    int in_handshake;
    int renegotiate;
    int new_session;
    int mode;
    int options;
    int rwstate;
    SSL3_STATE *s3;
    CERT *cert;
    SSL_SESSION *session;
    SSL_CTX *ctx;
    void (*msg_callback)(int, int, int, const void *, size_t, SSL *, void *);
    void *msg_callback_arg;
    void (*info_callback)(const SSL *ssl, int type2, int val);
    void *enc_read_ctx;
    void *session_ctx;
    int (*handshake_func)(struct ssl_st *s);
};

void SSLerr(int f, int r);
int SSL_in_init(SSL *s);
int SSL_is_init_finished(SSL *s);
int ssl3_setup_read_buffer(SSL *s);
int ssl3_get_record(SSL *s);
void ssl3_send_alert(SSL *s, int level, int desc);
int ssl3_do_change_cipher_spec(SSL *s);
void ssl3_release_read_buffer(SSL *s);
void ssl3_renegotiate(SSL *s);
int ssl3_renegotiate_check(SSL *s);
BIO *SSL_get_rbio(SSL *s);
void SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *sess);
void ERR_add_error_data(int num, ...);
int BIO_snprintf(char *buf, size_t n, const char *format, ...);
void BIO_clear_retry_flags(BIO *bio);
void BIO_set_retry_read(BIO *bio);
int tls1_process_heartbeat(SSL *s);