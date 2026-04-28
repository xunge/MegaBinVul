#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_EC
#define OPENSSL_NO_SRP
#define OPENSSL_NO_SRTP

#define SSL_OP_SAFARI_ECDHE_ECDSA_BUG 0
#define SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION 0
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0

#define TLSEXT_TYPE_server_name 0
#define TLSEXT_NAMETYPE_host_name 0
#define TLSEXT_MAXLEN_host_name 255
#define TLSEXT_TYPE_srp 0
#define TLSEXT_TYPE_ec_point_formats 0
#define TLSEXT_TYPE_elliptic_curves 0
#define TLSEXT_TYPE_opaque_prf_input 0
#define TLSEXT_TYPE_session_ticket 0
#define TLSEXT_TYPE_renegotiate 0
#define TLSEXT_TYPE_signature_algorithms 0
#define TLSEXT_TYPE_status_request 0
#define TLSEXT_STATUSTYPE_ocsp 0
#define TLSEXT_TYPE_heartbeat 0
#define TLSEXT_TYPE_next_proto_neg 0
#define TLSEXT_TYPE_application_layer_protocol_negotiation 0
#define TLSEXT_TYPE_use_srtp 0

#define SSL_TLSEXT_HB_ENABLED 0
#define SSL_TLSEXT_HB_DONT_SEND_REQUESTS 0

#define SSL_AD_DECODE_ERROR 0
#define SSL_AD_HANDSHAKE_FAILURE 0
#define SSL_AD_ILLEGAL_PARAMETER 0
#define SSL_AD_INTERNAL_ERROR 0
#define TLS1_AD_UNRECOGNIZED_NAME 0
#define TLS1_AD_INTERNAL_ERROR 0

#define SSL_F_SSL_SCAN_CLIENTHELLO_TLSEXT 0
#define SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED 0

typedef struct SSL SSL;
typedef struct SSL3_STATE SSL3_STATE;
typedef struct CERT CERT;
typedef struct SRP_CTX {
    char *login;
} SRP_CTX;
typedef struct OCSP_RESPID OCSP_RESPID;
typedef struct X509_EXTENSION X509_EXTENSION;
typedef struct SSL_SESSION {
    char *tlsext_hostname;
    unsigned char *tlsext_ecpointformatlist;
    int tlsext_ecpointformatlist_length;
    unsigned char *tlsext_ellipticcurvelist;
    int tlsext_ellipticcurvelist_length;
} SSL_SESSION;

struct SSL {
    int servername_done;
    int tlsext_status_type;
    int options;
    int hit;
    int renegotiate;
    SSL3_STATE *s3;
    CERT *cert;
    SRP_CTX srp_ctx;
    unsigned int tlsext_heartbeat;
    void (*tlsext_debug_cb)(SSL *s, int client_server, int type,
                           unsigned char *data, int len, void *arg);
    void *tlsext_debug_arg;
    int (*tls_session_ticket_ext_cb)(SSL *s, const unsigned char *data,
                                    int len, void *arg);
    void *tls_session_ticket_ext_cb_arg;
    void *srtp_profile;
    void *tlsext_ocsp_ids;
    void *tlsext_ocsp_exts;
    SSL_SESSION *session;
};

struct SSL3_STATE {
    int next_proto_neg_seen;
    unsigned char *alpn_selected;
    int alpn_selected_len;
    int client_opaque_prf_input_len;
    void *client_opaque_prf_input;
    struct {
        int finish_md_len;
    } tmp;
};

struct CERT {
    int alpn_proposed_len;
    unsigned char *alpn_proposed;
    unsigned char *peer_sigalgs;
};

static inline void n2s(const unsigned char *c, unsigned short *s)
{
    *s = ((unsigned int)c[0] << 8) | (unsigned int)c[1];
    c += 2;
}

void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);
void *BUF_memdup(const void *data, size_t siz);
int sk_OCSP_RESPID_push(void *sk, OCSP_RESPID *ptr);
void *sk_OCSP_RESPID_new_null();
void OCSP_RESPID_free(OCSP_RESPID *id);
void sk_X509_EXTENSION_pop_free(void *sk, void (*freefunc)(X509_EXTENSION *));
void X509_EXTENSION_free(X509_EXTENSION *a);
void *d2i_X509_EXTENSIONS(void **a, const unsigned char **in, long len);
OCSP_RESPID *d2i_OCSP_RESPID(OCSP_RESPID **a, const unsigned char **in, long len);
void SSLerr(int func, int reason);
int tls1_save_sigalgs(SSL *s, const unsigned char *data, int dsize);
int tls1_alpn_handle_client_hello(SSL *s, const unsigned char *data, int size, int *al);
int ssl_parse_clienthello_renegotiate_ext(SSL *s, const unsigned char *data, int size, int *al);
int ssl_parse_clienthello_use_srtp_ext(SSL *s, const unsigned char *data, int size, int *al);
int ssl_check_for_safari(SSL *s, const unsigned char *data, const unsigned char *limit);
int SSL_IS_DTLS(SSL *s);
void *SSL_get_srtp_profiles(SSL *s);