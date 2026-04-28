#include <string.h>

#define SSL3_VERSION 0
#define TLSEXT_TYPE_server_name 0
#define TLSEXT_TYPE_renegotiate 0
#define TLSEXT_TYPE_ec_point_formats 0
#define TLSEXT_TYPE_session_ticket 0
#define TLSEXT_TYPE_status_request 0
#define TLSEXT_TYPE_use_srtp 0
#define TLSEXT_TYPE_heartbeat 0
#define TLSEXT_TYPE_next_proto_neg 0
#define SSL_OP_NO_TICKET 0
#define SSL_OP_CRYPTOPRO_TLSEXT_BUG 0
#define SSL_TLSEXT_HB_ENABLED 0
#define SSL_TLSEXT_HB_DONT_RECV_REQUESTS 0
#define SSL_TLSEXT_HB_DONT_SEND_REQUESTS 0
#define SSL_TLSEXT_ERR_OK 0
#define DTLS1_VERSION 0
#define ERR_R_INTERNAL_ERROR 0
#define SSL_F_SSL_ADD_SERVERHELLO_TLSEXT 0

#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_EC
#define OPENSSL_NO_SRTP
#define OPENSSL_NO_HEARTBEATS

#define s2n(l,c) (*((c)++)=(unsigned char)(((l)>>8)&0xff), \
                 *((c)++)=(unsigned char)(((l))&0xff))

typedef struct ssl3_state_st {
    int send_connection_binding;
    struct {
        struct {
            unsigned int id;
        } *new_cipher;
    } tmp;
    int next_proto_neg_seen;
    unsigned char *server_opaque_prf_input;
    size_t server_opaque_prf_input_len;
} ssl3_state_st;

typedef struct ssl_session_st {
    char *tlsext_hostname;
} SSL_SESSION;

typedef struct ssl_ctx_st {
    int (*next_protos_advertised_cb)(struct ssl_st *s, const unsigned char **out,
                                   unsigned int *outlen, void *arg);
    void *next_protos_advertised_cb_arg;
} SSL_CTX;

typedef struct ssl_st {
    int version;
    int hit;
    int servername_done;
    ssl3_state_st *s3;
    SSL_SESSION *session;
    unsigned char *tlsext_ecpointformatlist;
    unsigned long tlsext_ecpointformatlist_length;
    int tlsext_ticket_expected;
    int tlsext_status_expected;
    int tlsext_heartbeat;
    SSL_CTX *ctx;
    void *srtp_profile;
} SSL;

void SSLerr(int f, int r);
int SSL_get_options(const SSL *s);
int ssl_add_serverhello_renegotiate_ext(SSL *s, unsigned char *p, int *len, int maxlen);
int ssl_add_serverhello_use_srtp_ext(SSL *s, unsigned char *p, int *len, int maxlen);