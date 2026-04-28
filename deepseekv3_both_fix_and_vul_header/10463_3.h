#include <stdlib.h>
#include <string.h>

struct ssl_st;
struct ssl3_state_st;
struct ssl_session_st;
struct ssl_ctx_st;

typedef struct ssl_st {
    struct ssl3_state_st *s3;
    struct ssl_session_st *session;
    struct ssl_ctx_st *ctx;
    char *tlsext_hostname;
    int tlsext_ticket_expected;
    int tlsext_heartbeat;
    int tlsext_use_etm;
    int version;
    int hit;
    int options;
    int tlsext_status_type;
    int tlsext_status_expected;
    void *tlsext_scts;
    size_t tlsext_scts_len;
    void *next_proto_negotiated;
    size_t next_proto_negotiated_len;
    void (*tlsext_debug_cb)(struct ssl_st *s, int client_server, unsigned int type, 
                           const unsigned char *data, unsigned int size, void *arg);
    void *tlsext_debug_arg;
    int (*tls_session_ticket_ext_cb)(struct ssl_st *s, const unsigned char *data, int size, void *arg);
    void *tls_session_ticket_ext_cb_arg;
    int (*ct_validation_callback)(void);
    int tlsext_debug_cb_present;
    int tls_session_ticket_ext_cb_present;
} SSL;

typedef struct ssl3_state_st {
    int next_proto_neg_seen;
    void *alpn_selected;
    size_t alpn_selected_len;
    int flags;
    struct {
        int finish_md_len;
        struct {
            int algorithm_mac;
            int algorithm_enc;
        } *new_cipher;
    } tmp;
    int alpn_sent;
} SSL3_STATE;

typedef struct ssl_session_st {
    char *tlsext_hostname;
    unsigned char *tlsext_ecpointformatlist;
    size_t tlsext_ecpointformatlist_length;
    int flags;
} SSL_SESSION;

typedef struct ssl_ctx_st {
    int (*next_proto_select_cb)(SSL *s, unsigned char **out, 
                              unsigned char *outlen, const unsigned char *in,
                              unsigned int inlen, void *arg);
    void *next_proto_select_cb_arg;
} SSL_CTX;

typedef struct packet_st {
    const unsigned char *curr;
    size_t remaining;
} PACKET;

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_EC
#define OPENSSL_NO_CT
#define OPENSSL_NO_SRTP

#define SSL_AD_DECODE_ERROR 50
#define TLS1_AD_UNRECOGNIZED_NAME 112
#define TLS1_AD_DECODE_ERROR 50
#define TLS1_AD_INTERNAL_ERROR 80
#define TLS1_AD_UNSUPPORTED_EXTENSION 110
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_UNRECOGNIZED_NAME 112

#define SSL_OP_LEGACY_SERVER_CONNECT 0x00000004
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x00040000

#define SSL_SESS_FLAG_EXTMS 0x0001
#define TLS1_FLAGS_RECEIVED_EXTMS 0x0002
#define TLS1_FLAGS_ENCRYPT_THEN_MAC 0x0004
#define SSL_DTLSEXT_HB_ENABLED 0x01
#define SSL_DTLSEXT_HB_DONT_SEND_REQUESTS 0x02

#define SSL_AEAD 0x00000001
#define SSL_RC4 0x00000002
#define SSL3_VERSION 0x0300
#define TLSEXT_TYPE_renegotiate 0xff01
#define TLSEXT_TYPE_server_name 0
#define TLSEXT_TYPE_ec_point_formats 11
#define TLSEXT_TYPE_session_ticket 35
#define TLSEXT_TYPE_status_request 5
#define TLSEXT_TYPE_signed_certificate_timestamp 18
#define TLSEXT_TYPE_next_proto_neg 13172
#define TLSEXT_TYPE_application_layer_protocol_negotiation 16
#define TLSEXT_TYPE_heartbeat 15
#define TLSEXT_TYPE_use_srtp 14
#define TLSEXT_TYPE_encrypt_then_mac 22
#define TLSEXT_TYPE_extended_master_secret 23

#define SSL_TLSEXT_ERR_OK 0
#define SSL_F_SSL_SCAN_SERVERHELLO_TLSEXT 1000
#define SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED 1001
#define SSL_R_INCONSISTENT_EXTMS 1002

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
char *OPENSSL_strdup(const char *s);
int SSL_IS_DTLS(const SSL *s);
int tls1_check_duplicate_extensions(PACKET *pkt);
int ssl_parse_serverhello_renegotiate_ext(SSL *s, PACKET *pkt, int *al);
int tls_use_ticket(SSL *s);
int ssl_next_proto_validate(PACKET *pkt);
int ssl_parse_serverhello_use_srtp_ext(SSL *s, PACKET *pkt, int *al);
int custom_ext_parse(SSL *s, int server, unsigned int type, const unsigned char *data, size_t size, int *al);
void SSLerr(int f, int r);

int PACKET_get_net_2(PACKET *pkt, unsigned int *data);
int PACKET_remaining(const PACKET *pkt);
int PACKET_get_sub_packet(PACKET *pkt, PACKET *subpkt, size_t len);
int PACKET_peek_bytes(const PACKET *pkt, const unsigned char **data, size_t len);
int PACKET_get_1(PACKET *pkt, unsigned int *data);
int PACKET_copy_bytes(PACKET *pkt, unsigned char *data, size_t len);