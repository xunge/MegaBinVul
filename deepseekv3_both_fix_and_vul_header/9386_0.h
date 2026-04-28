#include <stdlib.h>
#include <string.h>

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_EC
#define OPENSSL_NO_SRTP

#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_UNRECOGNIZED_NAME 112
#define TLS1_AD_UNRECOGNIZED_NAME 112
#define TLS1_AD_DECODE_ERROR 50
#define TLS1_AD_INTERNAL_ERROR 80
#define TLS1_AD_UNSUPPORTED_EXTENSION 110

#define SSL_TLSEXT_HB_ENABLED 0x01
#define SSL_TLSEXT_HB_DONT_SEND_REQUESTS 0x02

#define TLSEXT_TYPE_server_name 0
#define TLSEXT_TYPE_ec_point_formats 11
#define TLSEXT_TYPE_session_ticket 35
#define TLSEXT_TYPE_status_request 5
#define TLSEXT_TYPE_next_proto_neg 13172
#define TLSEXT_TYPE_renegotiate 0xff01
#define TLSEXT_TYPE_heartbeat 15
#define TLSEXT_TYPE_use_srtp 14

#define SSL_OP_NO_TICKET 0x00004000L
#define SSL_OP_LEGACY_SERVER_CONNECT 0x00000004L
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x00040000L

#define SSL_F_SSL_PARSE_SERVERHELLO_TLSEXT 0
#define SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED 0

#define DTLS1_VERSION 0xFEFF

typedef struct ssl_st SSL;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl3_state_st SSL3_STATE;

struct ssl_st {
    SSL_SESSION *session;
    SSL_CTX *ctx;
    SSL3_STATE *s3;
    char *tlsext_hostname;
    int tlsext_debug_arg;
    int (*tlsext_debug_cb)(SSL *, int, int, unsigned char *, int, void *);
    int tlsext_heartbeat;
    int (*tls_session_ticket_ext_cb)(SSL *, unsigned char *, int, void *);
    void *tls_session_ticket_ext_cb_arg;
    int tlsext_ticket_expected;
    int tlsext_status_type;
    int tlsext_status_expected;
    unsigned char *next_proto_negotiated;
    unsigned int next_proto_negotiated_len;
    int hit;
    unsigned long options;
    int version;
};

struct ssl_session_st {
    unsigned char *tlsext_ecpointformatlist;
    int tlsext_ecpointformatlist_length;
    char *tlsext_hostname;
};

struct ssl3_state_st {
    int next_proto_neg_seen;
    unsigned char *server_opaque_prf_input;
    int server_opaque_prf_input_len;
    int tmp_finish_md_len;
};

struct ssl_ctx_st {
    int (*next_proto_select_cb)(SSL *, unsigned char **, unsigned char *, unsigned char *, unsigned int, void *);
    void *next_proto_select_cb_arg;
};

#define n2s(c,s) ((s=(((unsigned int)(c[0]))<< 8)| \
                   (((unsigned int)(c[1]))    )),c+=2)

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
void *BUF_memdup(const void *data, size_t siz);
char *BUF_strdup(const char *str);
void SSLerr(int f, int r);
int ssl_next_proto_validate(unsigned char *data, unsigned int size);
int ssl_parse_serverhello_renegotiate_ext(SSL *s, unsigned char *data, unsigned int size, int *al);
int ssl_parse_serverhello_use_srtp_ext(SSL *s, unsigned char *data, unsigned int size, int *al);