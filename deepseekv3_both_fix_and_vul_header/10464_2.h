#include <stddef.h>
#include <string.h>

#define SSL_F_SSL_ADD_SERVERHELLO_TLSEXT 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL_kECDHE 0
#define SSL_aECDSA 0
#define SSL_AEAD 0
#define SSL_RC4 0
#define SSL_eGOST2814789CNT 0
#define SSL_eGOST2814789CNT12 0
#define SSL_OP_CRYPTOPRO_TLSEXT_BUG 0
#define SSL_DTLSEXT_HB_ENABLED 0
#define SSL_DTLSEXT_HB_DONT_RECV_REQUESTS 0
#define SSL_DTLSEXT_HB_DONT_SEND_REQUESTS 0
#define SSL_TLSEXT_ERR_OK 0
#define TLSEXT_TYPE_renegotiate 0
#define TLSEXT_TYPE_server_name 0
#define TLSEXT_TYPE_ec_point_formats 0
#define TLSEXT_TYPE_session_ticket 0
#define TLSEXT_TYPE_status_request 0
#define TLSEXT_TYPE_use_srtp 0
#define TLSEXT_TYPE_heartbeat 0
#define TLSEXT_TYPE_next_proto_neg 0
#define TLSEXT_TYPE_encrypt_then_mac 0
#define TLSEXT_TYPE_extended_master_secret 0
#define TLSEXT_TYPE_application_layer_protocol_negotiation 0
#define TLS1_FLAGS_RECEIVED_EXTMS 0
#define TLS1_FLAGS_ENCRYPT_THEN_MAC 0
#define SSL3_VERSION 0

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_EC
#define OPENSSL_NO_SRTP
#define OPENSSL_NO_HEARTBEATS

#define CHECKLEN(a, b, c) 0
#define s2n(a, b) (void)0

typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_st SSL;
typedef struct ssl3_state_st SSL3_STATE;

struct ssl3_state_st {
    unsigned long flags;
    int next_proto_neg_seen;
    const unsigned char *alpn_selected;
    size_t alpn_selected_len;
    int send_connection_binding;
    struct {
        struct {
            unsigned long algorithm_mkey;
            unsigned long algorithm_auth;
            unsigned long algorithm_enc;
            unsigned long algorithm_mac;
            int id;
        } *new_cipher;
    } tmp;
};

struct ssl_st {
    int version;
    int hit;
    int servername_done;
    int tlsext_ticket_expected;
    int tlsext_status_expected;
    int tlsext_heartbeat;
    int tlsext_use_etm;
    SSL_SESSION *session;
    SSL_CTX *ctx;
    SSL3_STATE *s3;
    int (*custom_ext_add)(SSL *s, int, unsigned char **, const unsigned char *, int *);
};

struct ssl_session_st {
    unsigned char *tlsext_hostname;
    unsigned char *tlsext_ecpointformatlist;
};

struct ssl_ctx_st {
    int (*next_protos_advertised_cb)(SSL *s, const unsigned char **out,
                                    unsigned int *outlen, void *arg);
    void *next_protos_advertised_cb_arg;
};

void SSLerr(int function, int reason);
int SSL_IS_DTLS(const SSL *s);
int SSL_get_options(const SSL *s);
int tls_use_ticket(SSL *s);
void tls1_get_formatlist(SSL *s, const unsigned char **plist, size_t *plistlen);
int ssl_add_serverhello_renegotiate_ext(SSL *s, unsigned char *buf, int *len, int maxlen);
int ssl_add_serverhello_use_srtp_ext(SSL *s, unsigned char *buf, int *len, int maxlen);
int custom_ext_add(SSL *s, int type, unsigned char **out, const unsigned char *limit, int *al);