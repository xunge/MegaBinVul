#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_EC
#define OPENSSL_NO_SRP
#define OPENSSL_NO_SRTP

#define TLSEXT_MAXLEN_host_name 255
#define TLSEXT_TYPE_server_name 0
#define TLSEXT_NAMETYPE_host_name 0
#define TLSEXT_TYPE_srp 12
#define TLSEXT_TYPE_ec_point_formats 11
#define TLSEXT_TYPE_elliptic_curves 10
#define TLSEXT_TYPE_opaque_prf_input 21
#define TLSEXT_TYPE_session_ticket 35
#define TLSEXT_TYPE_renegotiate 65281
#define TLSEXT_TYPE_signature_algorithms 13
#define TLSEXT_TYPE_status_request 5
#define TLSEXT_STATUSTYPE_ocsp 1
#define TLSEXT_TYPE_heartbeat 15
#define TLSEXT_TYPE_next_proto_neg 13172
#define TLSEXT_TYPE_use_srtp 14

#define SSL_TLSEXT_HB_ENABLED 0x01
#define SSL_TLSEXT_HB_DONT_SEND_REQUESTS 0x02

#define SSL_OP_SAFARI_ECDHE_ECDSA_BUG 0x00000040L
#define SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION 0x00040000L

#define TLS1_AD_UNRECOGNIZED_NAME 112
#define TLS1_AD_INTERNAL_ERROR 80
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_INTERNAL_ERROR 80
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_HANDSHAKE_FAILURE 40

#define DTLS1_VERSION 0xFEFF

#define SSL_F_SSL_PARSE_CLIENTHELLO_TLSEXT 100
#define SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED 101

typedef struct ssl_st SSL;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl3_state_st SSL3_STATE;
typedef struct srp_ctx_st {
    char *login;
} SRP_CTX;
typedef struct ocsp_responder_id_st OCSP_RESPID;
typedef struct X509_extension_st X509_EXTENSION;

struct ssl_st {
    int servername_done;
    int tlsext_status_type;
    SSL_SESSION *session;
    SSL3_STATE *s3;
    SRP_CTX srp_ctx;
    void *srtp_profile;
    void *tlsext_ocsp_exts;
    void *tlsext_debug_arg;
    int (*tlsext_debug_cb)(SSL *, int, int, unsigned char *, int, void *);
    int (*tls_session_ticket_ext_cb)(SSL *, unsigned char *, int, void *);
    void *tls_session_ticket_ext_cb_arg;
    int renegotiate;
    unsigned long options;
    int hit;
    unsigned int tlsext_heartbeat;
    void *tlsext_ocsp_ids;
    int version;
};

struct ssl_session_st {
    char *tlsext_hostname;
    unsigned char *tlsext_ecpointformatlist;
    int tlsext_ecpointformatlist_length;
    unsigned char *tlsext_ellipticcurvelist;
    int tlsext_ellipticcurvelist_length;
};

struct ssl3_state_st {
    int next_proto_neg_seen;
    unsigned char *client_opaque_prf_input;
    int client_opaque_prf_input_len;
    struct {
        int finish_md_len;
    } tmp;
};

static void n2s(const unsigned char *p, unsigned short *s) {
    *s = (p[0] << 8) | p[1];
}

static void OPENSSL_free(void *p) {
    free(p);
}

static void *OPENSSL_malloc(size_t size) {
    return malloc(size);
}

static void *BUF_memdup(const void *data, size_t size) {
    void *ret = malloc(size);
    if (ret) memcpy(ret, data, size);
    return ret;
}

static int ssl_check_for_safari(SSL *s, unsigned char *data, unsigned char *limit) {
    return 0;
}

static int tls1_process_sigalgs(SSL *s, unsigned char *data, int dsize) {
    return 1;
}

static int ssl_parse_clienthello_renegotiate_ext(SSL *s, unsigned char *data, int size, int *al) {
    return 1;
}

static int ssl_parse_clienthello_use_srtp_ext(SSL *s, unsigned char *data, int size, int *al) {
    return 1;
}

static void SSLerr(int f, int r) {
}

static void sk_OCSP_RESPID_pop_free(void *stack, void (*freefunc)(void *)) {
}

static void OCSP_RESPID_free(void *a) {
}

static void *sk_OCSP_RESPID_new_null(void) {
    return NULL;
}

static int sk_OCSP_RESPID_push(void *stack, void *data) {
    return 0;
}

static void *d2i_OCSP_RESPID(void **a, const unsigned char **in, long len) {
    return NULL;
}

static void sk_X509_EXTENSION_pop_free(void *stack, void (*freefunc)(void *)) {
}

static void X509_EXTENSION_free(void *a) {
}

static void *d2i_X509_EXTENSIONS(void **a, const unsigned char **in, long len) {
    return NULL;
}