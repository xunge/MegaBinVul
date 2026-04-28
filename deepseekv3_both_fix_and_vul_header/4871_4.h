#include <stdlib.h>
#include <string.h>

typedef struct SSL SSL;

typedef struct SSL_CIPHER {
    unsigned long algorithm_mac;
} SSL_CIPHER;

typedef struct SSL3_STATE {
    unsigned char *alpn_selected;
    size_t alpn_selected_len;
    unsigned int flags;
    unsigned int next_proto_neg_seen;
    unsigned char *server_opaque_prf_input;
    size_t server_opaque_prf_input_len;
    struct {
        size_t finish_md_len;
        SSL_CIPHER *new_cipher;
    } tmp;
} SSL3_STATE;

typedef struct SSL_SESSION {
    unsigned char *tlsext_hostname;
    unsigned char *tlsext_ecpointformatlist;
    size_t tlsext_ecpointformatlist_length;
} SSL_SESSION;

typedef struct custom_cli_ext_record {
    unsigned short ext_type;
    int (*fn2)(SSL *s, unsigned short type, const unsigned char *in,
              unsigned int inlen, int *al, void *arg);
    void *arg;
} custom_cli_ext_record;

typedef struct SSL_CTX {
    int (*next_proto_select_cb)(SSL *s, unsigned char **out, unsigned char *outlen,
                              const unsigned char *in, unsigned int inlen, void *arg);
    void *next_proto_select_cb_arg;
    size_t custom_cli_ext_records_count;
    custom_cli_ext_record *custom_cli_ext_records;
} SSL_CTX;

struct SSL {
    SSL3_STATE *s3;
    SSL_SESSION *session;
    SSL_CTX *ctx;
    char *tlsext_hostname;
    unsigned char *next_proto_negotiated;
    size_t next_proto_negotiated_len;
    unsigned char *alpn_client_proto_list;
    int tlsext_heartbeat;
    int tlsext_status_type;
    int tlsext_status_expected;
    int tlsext_ticket_expected;
    int hit;
    int options;
    int (*tlsext_debug_cb)(SSL *s, int client_server, int type,
                          unsigned char *data, int len, void *arg);
    void *tlsext_debug_arg;
    int (*tls_session_ticket_ext_cb)(SSL *s, const unsigned char *data, int len, void *arg);
    void *tls_session_ticket_ext_cb_arg;
};

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_EC
#define TLSEXT_TYPE_encrypt_then_mac 1
#define TLSEXT_TYPE_opaque_prf_input 2
#define TLSEXT_TYPE_server_name 3
#define TLSEXT_TYPE_session_ticket 4
#define TLSEXT_TYPE_status_request 5
#define TLSEXT_TYPE_renegotiate 6
#define TLSEXT_TYPE_heartbeat 7
#define TLSEXT_TYPE_use_srtp 8
#define TLSEXT_TYPE_application_layer_protocol_negotiation 9

#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_UNRECOGNIZED_NAME 112
#define TLS1_AD_DECODE_ERROR 50
#define TLS1_AD_INTERNAL_ERROR 80
#define TLS1_AD_UNRECOGNIZED_NAME 112
#define TLS1_AD_UNSUPPORTED_EXTENSION 110

#define SSL_OP_LEGACY_SERVER_CONNECT 0x00000004L
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x00040000L

#define SSL_TLSEXT_HB_ENABLED 0x01
#define SSL_TLSEXT_HB_DONT_SEND_REQUESTS 0x02

#define TLS1_FLAGS_ENCRYPT_THEN_MAC 0x0002

#define SSL_AEAD 0x00000020L

#define SSL_F_SSL_SCAN_SERVERHELLO_TLSEXT 1000
#define SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED 1000

#define n2s(c,s) do { \
    s = ((unsigned int)((c)[0])) << 8 | \
        ((unsigned int)((c)[1])); \
    (c) += 2; \
} while(0)

static void *OPENSSL_malloc(size_t size) { return malloc(size); }
static void OPENSSL_free(void *ptr) { free(ptr); }
static void *BUF_memdup(const void *data, size_t size) { void *ret = malloc(size); if (ret) memcpy(ret, data, size); return ret; }
static char *BUF_strdup(const char *str) { return str ? strdup(str) : NULL; }
static void SSLerr(int f, int r) {}

static int ssl_next_proto_validate(const unsigned char *data, unsigned int size) { return 1; }
static int ssl_parse_serverhello_renegotiate_ext(SSL *s, const unsigned char *data, size_t size, int *al) { return 1; }
static int ssl_parse_serverhello_use_srtp_ext(SSL *s, const unsigned char *data, size_t size, int *al) { return 1; }
static int tls_use_ticket(SSL *s) { return 1; }