#include <string.h>
#include <stdlib.h>

#define SSL3_VERSION 0x0300
#define TLS1_2_VERSION 0x0303
#define DTLS1_VERSION 0xFEFF

#define TLSEXT_TYPE_server_name 0
#define TLSEXT_NAMETYPE_host_name 0
#define TLSEXT_TYPE_renegotiate 0xff01
#define TLSEXT_TYPE_srp 0x0C
#define TLSEXT_TYPE_ec_point_formats 0x0B
#define TLSEXT_TYPE_elliptic_curves 0x0A
#define TLSEXT_TYPE_session_ticket 0x23
#define TLSEXT_TYPE_signature_algorithms 0x0D
#define TLSEXT_TYPE_opaque_prf_input 0x0E
#define TLSEXT_TYPE_status_request 0x05
#define TLSEXT_STATUSTYPE_ocsp 1
#define TLSEXT_TYPE_heartbeat 0x0F
#define TLSEXT_TYPE_next_proto_neg 0x3374
#define TLSEXT_TYPE_use_srtp 0x000E
#define TLSEXT_TYPE_padding 0x15

#define SSL_TLSEXT_HB_ENABLED 1
#define SSL_TLSEXT_HB_DONT_RECV_REQUESTS 2
#define SSL_TLSEXT_HB_DONT_SEND_REQUESTS 2

#define SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT 0
#define ERR_R_INTERNAL_ERROR 0

#define SSL_OP_NO_TICKET 0x00004000L
#define SSL_OP_TLSEXT_PADDING 0x00000010L

#define OPENSSL_NO_SRP
#define OPENSSL_NO_EC
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_NEXTPROTONEG
#define OPENSSL_NO_SRTP

#define SSL23_ST_CW_CLNT_HELLO_A 0x1000

typedef struct ssl_st {
    int client_version;
    struct ssl3_state_st *s3;
    char *tlsext_hostname;
    int renegotiate;
    struct {
        char *login;
    } srp_ctx;
    unsigned char *tlsext_ecpointformatlist;
    unsigned long tlsext_ecpointformatlist_length;
    unsigned char *tlsext_ellipticcurvelist;
    unsigned long tlsext_ellipticcurvelist_length;
    int options;
    struct ssl_session_st *session;
    struct {
        unsigned char *data;
        int length;
    } *tlsext_session_ticket;
    int new_session;
    int tlsext_status_type;
    void *tlsext_ocsp_ids;
    void *tlsext_ocsp_exts;
    int version;
    int tlsext_heartbeat;
    struct ssl_ctx_st *ctx;
    struct {
        unsigned char *data;
    } *init_buf;
    int state;
} SSL;

typedef struct ssl3_state_st {
    int send_connection_binding;
    unsigned char *client_opaque_prf_input;
    size_t client_opaque_prf_input_len;
    struct {
        size_t finish_md_len;
    } tmp;
} SSL3_STATE;

typedef struct ssl_session_st {
    unsigned char *tlsext_tick;
    int tlsext_ticklen;
} SSL_SESSION;

typedef struct ssl_ctx_st {
    void (*next_proto_select_cb)(void);
} SSL_CTX;

typedef struct ocsp_responder_id_st OCSP_RESPID;
typedef struct stack_st_OCSP_RESPID STACK_OF_OCSP_RESPID;
typedef struct stack_st_X509_EXTENSION X509_EXTENSIONS;

static const unsigned char tls12_sigalgs[2] = {0};

#define s2n(l,c) (*((c)++)=(unsigned char)(((l)>>8)&0xff), \
                 *((c)++)=(unsigned char)(((l))&0xff))

int ssl_add_clienthello_renegotiate_ext(SSL *s, unsigned char *p, int *len, int maxlen);
int ssl_add_clienthello_use_srtp_ext(SSL *s, unsigned char *p, int *len, int maxlen);
unsigned long SSL_get_options(const SSL *s);
unsigned int TLS1_get_client_version(const SSL *s);
void SSLerr(int f, int r);

int sk_OCSP_RESPID_num(const STACK_OF_OCSP_RESPID *sk);
OCSP_RESPID *sk_OCSP_RESPID_value(const STACK_OF_OCSP_RESPID *sk, int idx);
int i2d_OCSP_RESPID(OCSP_RESPID *a, unsigned char **pp);
int i2d_X509_EXTENSIONS(X509_EXTENSIONS *a, unsigned char **pp);

void *OPENSSL_malloc(int size);