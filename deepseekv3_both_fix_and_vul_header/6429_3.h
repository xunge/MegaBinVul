#include <string.h>
#include <stdio.h>

typedef struct ssl_st SSL;

#define SSL_F_SSL3_READ_BYTES 0
#define SSL_R_SSL_HANDSHAKE_FAILURE 0
#define SSL_R_APP_DATA_IN_HANDSHAKE 0
#define SSL_R_CCS_RECEIVED_EARLY 0
#define SSL_R_DATA_BETWEEN_CCS_AND_FINISHED 0
#define SSL_R_UNEXPECTED_RECORD 0
#define SSL_R_UNEXPECTED_MESSAGE 0
#define SSL_R_NO_RENEGOTIATION 0
#define SSL_R_TOO_MANY_WARN_ALERTS 0
#define SSL_R_BAD_HELLO_REQUEST 0
#define SSL_R_UNKNOWN_ALERT_TYPE 0

#define SSL3_RT_APPLICATION_DATA 0
#define SSL3_RT_HANDSHAKE 1
#define SSL3_RT_CHANGE_CIPHER_SPEC 2
#define SSL3_RT_ALERT 3
#define SSL3_MT_HELLO_REQUEST 0
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_AL_WARNING 1
#define SSL3_AL_FATAL 2
#define SSL_AD_NO_RENEGOTIATION 0
#define SSL_AD_INTERNAL_ERROR 1
#define SSL_AD_UNEXPECTED_MESSAGE 2
#define SSL_AD_DECODE_ERROR 3
#define SSL_AD_HANDSHAKE_FAILURE 4
#define SSL_AD_ILLEGAL_PARAMETER 5
#define SSL_AD_CLOSE_NOTIFY 6
#define SSL_AD_REASON_OFFSET 0

#define SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS 0
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0
#define SSL_MODE_AUTO_RETRY 0
#define SSL_MODE_RELEASE_BUFFERS 0
#define SSL_CB_READ_ALERT 0

#define SSL_ST_READ_HEADER 0
#define SSL_NOTHING 0
#define SSL_READING 0
#define SSL_RECEIVED_SHUTDOWN 0
#define SSL_SENT_SHUTDOWN 0

#define MAX_WARN_ALERT_COUNT 0
#define SSL2_VERSION 0
#define SSL3_VERSION 0
#define TLS_ANY_VERSION 0
#define TLS1_VERSION 0
#define TLS1_1_VERSION 0

typedef struct ssl3_record_st {
    unsigned char *data;
    unsigned int off;
    unsigned int length;
    int type;
    int rec_version;
    int read;
} SSL3_RECORD;

typedef struct ssl3_buffer_st {
    int initialized;
    int left;
} SSL3_BUFFER;

typedef struct ssl_session_st {
    void *cipher;
} SSL_SESSION;

typedef struct ssl_ctx_st {
    void *info_callback;
    unsigned long options;
    void (*remove_session)(struct ssl_ctx_st *, struct ssl_session_st *);
} SSL_CTX;

typedef struct bio_st {
    void (*clear_retry_flags)(struct bio_st *);
    void (*set_retry_read)(struct bio_st *);
} BIO;

struct ssl3_state_st {
    int flags;
    int warn_alert;
    int fatal_alert;
    int change_cipher_spec;
    int renegotiate;
    int send_connection_binding;
    int in_read_app_data;
};

struct record_layer_st {
    SSL3_BUFFER rbuf;
    SSL3_RECORD *rrec;
    unsigned char handshake_fragment[4];
    unsigned int handshake_fragment_len;
    unsigned char alert_fragment[2];
    unsigned int alert_fragment_len;
    int rstate;
    int alert_count;
};

struct ssl_st {
    int version;
    int server;
    int shutdown;
    int rwstate;
    int mode;
    int renegotiate;
    int new_session;
    SSL_SESSION *session;
    SSL_CTX *session_ctx;
    SSL_CTX *ctx;
    struct ssl3_state_st *s3;
    struct record_layer_st rlayer;
    BIO *rbio;
    int (*handshake_func)(struct ssl_st *s);
    void (*info_callback)(const struct ssl_st *ssl, int type, int val);
    void (*msg_callback)(int write_p, int version, int content_type,
                         const void *buf, size_t len, struct ssl_st *ssl, void *arg);
    void *msg_callback_arg;
    struct {
        int version;
    } *method;
    void *enc_read_ctx;
};

#define SSL3_BUFFER_is_initialised(b) ((b)->initialized)
#define SSL3_BUFFER_get_left(b) ((b)->left)
#define SSL3_RECORD_is_read(r) ((r)->read)
#define SSL3_RECORD_set_read(r) ((r)->read = 1)
#define SSL3_RECORD_get_type(r) ((r)->type)
#define SSL3_RECORD_get_length(r) ((r)->length)
#define SSL3_RECORD_set_length(r, l) ((r)->length = (l))
#define SSL3_RECORD_add_length(r, n) ((r)->length += (n))
#define SSL3_RECORD_get_off(r) ((r)->off)
#define SSL3_RECORD_set_off(r, o) ((r)->off = (o))
#define SSL3_RECORD_add_off(r, n) ((r)->off += (n))
#define SSL3_RECORD_get_data(r) ((r)->data)
#define SSL3_RECORD_sub_length(r, n) ((r)->length -= (n))

#define RECORD_LAYER_get_numrpipes(rl) 0
#define RECORD_LAYER_set_numrpipes(rl, n)

#define SSL_in_init(s) 0
#define SSL_is_init_finished(s) 0
#define SSL_get_rbio(s) ((s)->rbio)
#define SSL_CTX_remove_session(ctx, sess) ((ctx)->remove_session((ctx), (sess)))

#define ERR_R_INTERNAL_ERROR 0
#define ERR_add_error_data(n, ...)

static inline void BIO_clear_retry_flags(BIO *bio) { bio->clear_retry_flags(bio); }
static inline void BIO_set_retry_read(BIO *bio) { bio->set_retry_read(bio); }

#define ossl_statem_get_in_handshake(s) 0
#define ossl_statem_set_in_init(s, v)
#define ossl_statem_app_data_allowed(s) 0

static inline int ssl3_setup_read_buffer(SSL *s) { return 0; }
static inline void ssl3_release_read_buffer(SSL *s) {}
static inline int ssl3_get_record(SSL *s) { return 0; }
static inline void ssl3_send_alert(SSL *s, int level, int desc) {}
static inline void ssl3_renegotiate(SSL *s) {}
static inline int ssl3_renegotiate_check(SSL *s) { return 0; }

static inline void SSLerr(int f, int r) {}