#include <stdlib.h>
#include <string.h>

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_EC
#define OPENSSL_NO_HEARTBEATS
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
#define TLSEXT_TYPE_application_layer_protocol_negotiation 16
#define TLSEXT_TYPE_renegotiate 65281
#define TLSEXT_TYPE_heartbeat 15
#define TLSEXT_TYPE_use_srtp 14

#define SSL_OP_NO_TICKET 0x00004000L
#define SSL_OP_LEGACY_SERVER_CONNECT 0x00000004L
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x00040000L

#define SSL_F_SSL_SCAN_SERVERHELLO_TLSEXT 0
#define SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED 0
#define SSL_TLSEXT_ERR_OK 0

typedef struct ssl_st SSL;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_cert_st SSL_CERT;

struct ssl_st {
    SSL_SESSION *session;
    SSL_CTX *ctx;
    SSL_CERT *cert;
    struct ssl3_state_st *s3;
    char *tlsext_hostname;
    int tlsext_debug_arg;
    void (*tlsext_debug_cb)(SSL *, int, int, unsigned char *, int, int);
    int tlsext_status_type;
    int tlsext_status_expected;
    int tlsext_ticket_expected;
    int tlsext_heartbeat;
    int hit;
    int options;
    unsigned char *next_proto_negotiated;
    unsigned char next_proto_negotiated_len;
    int (*tls_session_ticket_ext_cb)(SSL *, unsigned char *, int, void *);
    void *tls_session_ticket_ext_cb_arg;
};

struct ssl3_state_st {
    unsigned char *alpn_selected;
    size_t alpn_selected_len;
    unsigned char *server_opaque_prf_input;
    size_t server_opaque_prf_input_len;
    struct {
        size_t finish_md_len;
    } tmp;
    int next_proto_neg_seen;
};

struct ssl_session_st {
    unsigned char *tlsext_hostname;
    unsigned char *tlsext_ecpointformatlist;
    size_t tlsext_ecpointformatlist_length;
};

struct ssl_ctx_st {
    int (*next_proto_select_cb)(SSL *, unsigned char **, unsigned char *,
                               const unsigned char *, unsigned int, void *);
    void *next_proto_select_cb_arg;
};

struct ssl_cert_st {
    int alpn_sent;
};

#define n2s(c,s) ((s=(((unsigned int)(c[0]))<< 8)| \
                  (((unsigned int)(c[1]))    )),c+=2)

static void SSLerr(int a, int b) {}
static void *OPENSSL_malloc(size_t size) { return malloc(size); }
static void OPENSSL_free(void *ptr) { free(ptr); }
static void *BUF_memdup(const void *data, size_t size) { return memcpy(malloc(size), data, size); }
static char *BUF_strdup(const char *str) { return strdup(str); }
static int ssl_next_proto_validate(const unsigned char *data, unsigned int size) { return 1; }
static int ssl_parse_serverhello_renegotiate_ext(SSL *s, unsigned char *data, int size, int *al) { return 1; }
static int ssl_parse_serverhello_use_srtp_ext(SSL *s, unsigned char *data, int size, int *al) { return 1; }
static int custom_ext_parse(SSL *s, int a, int b, unsigned char *c, int d, int *e) { return 1; }
static long SSL_get_options(const SSL *s) { return s->options; }