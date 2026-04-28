#include <stdlib.h>
#include <string.h>

#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_INTERNAL_ERROR 80
#define SSL_AD_HANDSHAKE_FAILURE 40
#define SSL_AD_ILLEGAL_PARAMETER 47
#define TLS1_AD_UNRECOGNIZED_NAME 112
#define TLS1_AD_INTERNAL_ERROR 80

#define SSL_OP_SAFARI_ECDHE_ECDSA_BUG 0x00000040L
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x00040000L

#define SSL3_VERSION 0x0300

#define TLSEXT_TYPE_renegotiate 0xff01
#define TLSEXT_TYPE_server_name 0
#define TLSEXT_TYPE_srp 12
#define TLSEXT_TYPE_ec_point_formats 11
#define TLSEXT_TYPE_elliptic_curves 10
#define TLSEXT_TYPE_session_ticket 35
#define TLSEXT_TYPE_signature_algorithms 13
#define TLSEXT_TYPE_status_request 5
#define TLSEXT_TYPE_heartbeat 15
#define TLSEXT_TYPE_next_proto_neg 13172
#define TLSEXT_TYPE_application_layer_protocol_negotiation 16
#define TLSEXT_TYPE_use_srtp 14
#define TLSEXT_TYPE_encrypt_then_mac 22

#define TLSEXT_NAMETYPE_host_name 0
#define TLSEXT_MAXLEN_host_name 255

#define TLSEXT_STATUSTYPE_ocsp 1

#define SSL_DTLSEXT_HB_ENABLED 0x01
#define SSL_DTLSEXT_HB_DONT_SEND_REQUESTS 0x02

#define TLS1_FLAGS_ENCRYPT_THEN_MAC 0x0100

#define SSL_F_SSL_SCAN_CLIENTHELLO_TLSEXT 1000
#define SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED 1001

#define SSL_IS_DTLS(s) (0)
#define SSL_get_srtp_profiles(s) NULL

typedef struct PACKET {
    const unsigned char *data;
    size_t remaining;
} PACKET;

typedef struct SSL3_STATE {
    int next_proto_neg_seen;
    void *alpn_selected;
    size_t alpn_selected_len;
    void *alpn_proposed;
    size_t alpn_proposed_len;
    struct {
        void *peer_sigalgs;
        size_t finish_md_len;
    } tmp;
    unsigned long flags;
} SSL3_STATE;

typedef struct SSL_SESSION {
    char *tlsext_hostname;
    void *tlsext_ecpointformatlist;
    size_t tlsext_ecpointformatlist_length;
    void *tlsext_ellipticcurvelist;
    size_t tlsext_ellipticcurvelist_length;
} SSL_SESSION;

typedef struct SRP_CTX {
    char *login;
} SRP_CTX;

typedef struct SSL {
    int servername_done;
    int tlsext_status_type;
    int tlsext_heartbeat;
    int tlsext_use_etm;
    int version;
    int hit;
    int renegotiate;
    unsigned long options;
    SSL_SESSION *session;
    SSL3_STATE *s3;
    SRP_CTX srp_ctx;
    void *srtp_profile;
    void *tlsext_debug_arg;
    int (*tlsext_debug_cb)(struct SSL *, int, int, const unsigned char *, size_t, void *);
    int (*tls_session_ticket_ext_cb)(struct SSL *, const unsigned char *, size_t, void *);
    void *tls_session_ticket_ext_cb_arg;
    void *tlsext_ocsp_ids;
    void *tlsext_ocsp_exts;
} SSL;

typedef struct OCSP_RESPID {
    // OCSP responder ID structure
} OCSP_RESPID;

typedef struct X509_EXTENSION {
    // X509 extension structure
} X509_EXTENSION;

static void X509_EXTENSION_free(X509_EXTENSION *a) {
    free(a);
}

static const unsigned char *PACKET_end(const PACKET *pkt) {
    return pkt->data + pkt->remaining;
}

int PACKET_remaining(const PACKET *pkt);
int PACKET_as_length_prefixed_2(PACKET *pkt, PACKET *subpkt);
int PACKET_get_net_2(PACKET *pkt, unsigned int *data);
int PACKET_get_length_prefixed_2(PACKET *pkt, PACKET *subpkt);
const unsigned char *PACKET_data(const PACKET *pkt);
int PACKET_contains_zero_byte(const PACKET *pkt);
int PACKET_strndup(PACKET *pkt, char **data);
int PACKET_equal(const PACKET *pkt, const char *data, size_t len);
int PACKET_get_1(PACKET *pkt, unsigned int *data);
int PACKET_as_length_prefixed_1(PACKET *pkt, PACKET *subpkt);
int PACKET_memdup(PACKET *pkt, void **data, size_t *len);
int tls1_check_duplicate_extensions(PACKET *pkt);
int ssl_parse_clienthello_renegotiate_ext(SSL *s, PACKET *pkt, int *al);
int tls1_save_sigalgs(SSL *s, const unsigned char *data, size_t len);
int tls1_alpn_handle_client_hello(SSL *s, PACKET *pkt, int *al);
int ssl_parse_clienthello_use_srtp_ext(SSL *s, PACKET *pkt, int *al);
int custom_ext_parse(SSL *s, int server, unsigned int type, const unsigned char *data, size_t len, int *al);
void OPENSSL_free(void *ptr);
void SSLerr(int f, int r);
void sk_OCSP_RESPID_pop_free(void *sk, void (*freefunc)(OCSP_RESPID *));
void *sk_OCSP_RESPID_new_null();
int sk_OCSP_RESPID_push(void *sk, OCSP_RESPID *id);
void OCSP_RESPID_free(OCSP_RESPID *id);
void sk_X509_EXTENSION_pop_free(void *sk, void (*freefunc)(X509_EXTENSION *));
void *d2i_X509_EXTENSIONS(void **a, const unsigned char **in, long len);
OCSP_RESPID *d2i_OCSP_RESPID(OCSP_RESPID **a, const unsigned char **in, long len);
int ssl_check_for_safari(SSL *s, PACKET *pkt);