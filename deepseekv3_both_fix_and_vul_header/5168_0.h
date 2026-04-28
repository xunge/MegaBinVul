#include <stdlib.h>

#define SSL3_VERSION 0x0300
#define SSL3_AL_FATAL 2
#define SSL_AD_PROTOCOL_VERSION 70
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_ST_ERR 0x1000

typedef struct ssl3_buffer_st {
    size_t left;
} SSL3_BUFFER;

typedef struct ssl3_state_st {
    int alert_dispatch;
    unsigned char send_alert[2];
    SSL3_BUFFER wbuf;
} SSL3_STATE;

typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;

typedef struct ssl3_enc_method_st {
    int (*alert_value)(int);
} SSL3_ENC_METHOD;

typedef struct ssl_method_st {
    int (*ssl_dispatch_alert)(void *);
    SSL3_ENC_METHOD *ssl3_enc;
} SSL_METHOD;

typedef struct ssl_st {
    int version;
    int state;
    SSL_METHOD *method;
    SSL_SESSION *session;
    SSL_CTX *session_ctx;
    SSL3_STATE *s3;
} SSL;

void SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *sess);