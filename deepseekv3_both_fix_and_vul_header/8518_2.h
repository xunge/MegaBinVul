#include <string.h>

typedef struct ssl3_record_st {
    unsigned char *data;
    unsigned int off;
    unsigned int length;
    int type;
    int rec_version;
    int read;
} SSL3_RECORD;

typedef struct ssl3_buffer_st {
    unsigned char *buf;
    size_t len;
    size_t offset;
    size_t left;
    int initialized;
} SSL3_BUFFER;

typedef struct ssl_session_st {
    void *cipher;
} SSL_SESSION;

typedef struct ssl_ctx_st {
    unsigned long options;
    void *info_callback;
} SSL_CTX;

typedef struct ssl3_state_st {
    int change_cipher_spec;
    unsigned long flags;
    int renegotiate;
    int warn_alert;
    int fatal_alert;
    int send_connection_binding;
    int in_read_app_data;
} SSL3_STATE;

typedef struct bio_st {
    // Minimal BIO structure
} BIO;

typedef struct ssl_method_st {
    int version;
} SSL_METHOD;

typedef struct ssl_st {
    struct {
        SSL3_BUFFER rbuf;
        SSL3_RECORD *rrec;
        unsigned char handshake_fragment[4];
        unsigned int handshake_fragment_len;
        unsigned char alert_fragment[2];
        unsigned int alert_fragment_len;
        unsigned int alert_count;
        int rstate;
    } rlayer;
    int rwstate;
    int shutdown;
    int version;
    int server;
    int mode;
    SSL3_STATE *s3;
    void *enc_read_ctx;
    SSL_SESSION *session;
    SSL_CTX *ctx;
    void *session_ctx;
    SSL_METHOD *method;
    int (*handshake_func)(struct ssl_st *);
    void (*msg_callback)(int, int, int, const void *, size_t, struct ssl_st *, void *);
    void *msg_callback_arg;
    void (*info_callback)(const struct ssl_st *, int, int);
    int renegotiate;
    int new_session;
} SSL;

#define SSL_F_SSL3_READ_BYTES 100
#define ERR_R_INTERNAL_ERROR 1
#define SSL_R_SSL_HANDSHAKE_FAILURE 2
#define SSL_R_APP_DATA_IN_HANDSHAKE 3
#define SSL_R_CCS_RECEIVED_EARLY 4
#define SSL_R_DATA_BETWEEN_CCS_AND_FINISHED 5
#define SSL_R_UNEXPECTED_MESSAGE 6
#define SSL_R_BAD_HELLO_REQUEST 7
#define SSL_R_TOO_MANY_WARN_ALERTS 8
#define SSL_R_NO_RENEGOTIATION 9
#define SSL_R_UNKNOWN_ALERT_TYPE 10
#define SSL_R_UNEXPECTED_RECORD 11

#define SSL3_RT_APPLICATION_DATA 23
#define SSL3_RT_HANDSHAKE 22
#define SSL3_RT_CHANGE_CIPHER_SPEC 20
#define SSL3_RT_ALERT 21
#define SSL3_MT_HELLO_REQUEST 0
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_AL_WARNING 1
#define SSL3_AL_FATAL 2
#define SSL_AD_NO_RENEGOTIATION 100
#define SSL_AD_INTERNAL_ERROR 80
#define SSL_AD_UNEXPECTED_MESSAGE 10
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_CLOSE_NOTIFY 0
#define SSL_AD_REASON_OFFSET 1000

#define SSL_ST_READ_HEADER 1
#define SSL_NOTHING 1
#define SSL_READING 2
#define SSL_RECEIVED_SHUTDOWN 1
#define SSL_SENT_SHUTDOWN 2
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x00040000L
#define SSL_MODE_AUTO_RETRY 0x00000004L
#define SSL_MODE_RELEASE_BUFFERS 0x00000010L
#define MAX_WARN_ALERT_COUNT 5
#define SSL_CB_READ_ALERT 0x4000
#define SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS 0x0001
#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301
#define TLS1_1_VERSION 0x0302
#define TLS_ANY_VERSION 0x10000
#define SSL2_VERSION 0x0002

#define SSL3_BUFFER_is_initialised(b) ((b)->initialized)
#define SSL3_BUFFER_get_left(b) ((b)->left)
#define SSL3_RECORD_is_read(r) ((r)->read)
#define SSL3_RECORD_set_read(r) ((r)->read = 1)
#define SSL3_RECORD_get_type(r) ((r)->type)
#define SSL3_RECORD_get_length(r) ((r)->length)
#define SSL3_RECORD_set_length(r, l) ((r)->length = (l))
#define SSL3_RECORD_add_length(r, l) ((r)->length += (l))
#define SSL3_RECORD_get_off(r) ((r)->off)
#define SSL3_RECORD_set_off(r, o) ((r)->off = (o))
#define SSL3_RECORD_add_off(r, o) ((r)->off += (o))
#define SSL3_RECORD_get_data(r) ((r)->data)
#define SSL3_RECORD_sub_length(r, l) ((r)->length -= (l))
#define RECORD_LAYER_get_numrpipes(s) (1)
#define RECORD_LAYER_set_numrpipes(s, n) 

void SSLerr(int f, int r);
int SSL_in_init(SSL *s);
int SSL_is_init_finished(SSL *s);
int ossl_statem_get_in_handshake(SSL *s);
int ossl_statem_app_data_allowed(SSL *s);
void ossl_statem_set_in_init(SSL *s, int in_init);
int ssl3_setup_read_buffer(SSL *s);
int ssl3_get_record(SSL *s);
void ssl3_send_alert(SSL *s, int level, int desc);
int ssl3_renegotiate(SSL *s);
int ssl3_renegotiate_check(SSL *s);
void ssl3_release_read_buffer(SSL *s);
void SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *sess);
BIO *SSL_get_rbio(SSL *s);
void BIO_clear_retry_flags(BIO *bio);
void BIO_set_retry_read(BIO *bio);
int BIO_snprintf(char *buf, size_t n, const char *format, ...);
void ERR_add_error_data(int num, ...);