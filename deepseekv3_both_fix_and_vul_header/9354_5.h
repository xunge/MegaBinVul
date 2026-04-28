#include <stdlib.h>
#include <string.h>

typedef struct x509_st X509;
typedef struct x509_extension_st X509_EXTENSION;
typedef struct ocsp_respid_st OCSP_RESPID;
typedef struct evp_md_st EVP_MD;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct rsa_st RSA;
typedef struct dh_st DH;
typedef struct ec_key_st EC_KEY;

typedef struct stack_st {
    void *data;
    int num;
} STACK;

#define STACK_OF(type) struct stack_st

typedef struct sess_cert_st {
    RSA *peer_rsa_tmp;
    DH *peer_dh_tmp;
    EC_KEY *peer_ecdh_tmp;
    struct {
        const EVP_MD *digest;
    } *peer_key;
} SESS_CERT;

typedef struct cert_pkey_st {
    STACK_OF(X509) *chain;
} CERT_PKEY;

typedef struct ssl_cipher_st {
    unsigned long algorithm_auth;
} SSL_CIPHER;

typedef struct ssl_method_st {
    int version;
} SSL_METHOD;

typedef struct ssl_st {
    int hit;
    struct {
        int num_renegotiations;
        int total_renegotiations;
        unsigned long flags;
        struct {
            const SSL_CIPHER *new_cipher;
            int cert_req;
            unsigned char *ctype;
            int ctype_num;
        } tmp;
    } *s3;
    struct cert_st {
        RSA *rsa_tmp;
        DH *dh_tmp;
        EC_KEY *ecdh_tmp;
        struct {
            EVP_PKEY *privatekey;
        } pkeys[1];
        CERT_PKEY *key;
        STACK_OF(X509) *chain;
        unsigned char *ctypes;
        size_t ctype_num;
        int ecdh_tmp_auto;
    } *cert;
    int options;
    int server;
    int version;
    struct ssl_ctx_st {
        void *cert_store;
        SSL_METHOD *method;
    } *ctx;
    struct ssl_session_st {
        SESS_CERT *sess_cert;
        unsigned char *tlsext_ellipticcurvelist;
        size_t tlsext_ellipticcurvelist_length;
    } *session;
    char *tlsext_hostname;
    void *tlsext_debug_arg;
    void *tlsext_opaque_prf_input;
    size_t tlsext_opaque_prf_input_len;
    int tlsext_status_type;
    STACK_OF(X509_EXTENSION) *tlsext_ocsp_exts;
    STACK_OF(OCSP_RESPID) *tlsext_ocsp_ids;
    unsigned char *tlsext_ocsp_resp;
    size_t tlsext_ocsp_resplen;
    int tlsext_hb_pending;
    int tlsext_heartbeat;
} SSL;

#define SSL_aNULL 0x1
#define SSL_aSRP 0x2

#define OPENSSL_NO_DSA
#define OPENSSL_NO_RSA
#define OPENSSL_NO_DH
#define OPENSSL_NO_ECDH
#define OPENSSL_NO_TLSEXT
#define OPENSSL_NO_HEARTBEATS
#define OPENSSL_NO_EC

#define SSL_F_SSL3_CTRL 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_PASSED_NULL_PARAMETER 0
#define ERR_R_RSA_LIB 0
#define ERR_R_DH_LIB 0
#define ERR_R_ECDH_LIB 0
#define ERR_R_INTERNAL_ERROR 0
#define ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED 0
#define SSL_R_SSL3_EXT_INVALID_SERVERNAME 0
#define SSL_R_SSL3_EXT_INVALID_SERVERNAME_TYPE 0
#define SSL_R_OPAQUE_PRF_INPUT_TOO_LONG 0

#define SSL_CTRL_GET_SESSION_REUSED 1
#define SSL_CTRL_GET_CLIENT_CERT_REQUEST 2
#define SSL_CTRL_GET_NUM_RENEGOTIATIONS 3
#define SSL_CTRL_CLEAR_NUM_RENEGOTIATIONS 4
#define SSL_CTRL_GET_TOTAL_RENEGOTIATIONS 5
#define SSL_CTRL_GET_FLAGS 6
#define SSL_CTRL_CHAIN 7
#define SSL_CTRL_CHAIN_CERT 8
#define SSL_CTRL_GET_CHAIN_CERTS 9
#define SSL_CTRL_SELECT_CURRENT_CERT 10
#define SSL_CTRL_SET_CURRENT_CERT 11
#define SSL_CTRL_SET_SIGALGS 12
#define SSL_CTRL_SET_SIGALGS_LIST 13
#define SSL_CTRL_SET_CLIENT_SIGALGS 14
#define SSL_CTRL_SET_CLIENT_SIGALGS_LIST 15
#define SSL_CTRL_GET_CLIENT_CERT_TYPES 16
#define SSL_CTRL_SET_CLIENT_CERT_TYPES 17
#define SSL_CTRL_BUILD_CERT_CHAIN 18
#define SSL_CTRL_SET_VERIFY_CERT_STORE 19
#define SSL_CTRL_SET_CHAIN_CERT_STORE 20
#define SSL_CTRL_GET_PEER_SIGNATURE_NID 21
#define SSL_CTRL_GET_SERVER_TMP_KEY 22
#define SSL_CTRL_CHECK_PROTO_VERSION 23

#define SSL_PKEY_RSA_ENC 0
#define SSL_OP_SINGLE_DH_USE 0
#define SSL_OP_SINGLE_ECDH_USE 0
#define SSL_OP_NO_TLSv1_2 0
#define SSL_OP_NO_TLSv1_1 0
#define SSL_OP_NO_TLSv1 0
#define SSL_OP_NO_SSLv3 0
#define SSL_OP_NO_SSLv2 0

#define SSL_CERT_SET_SERVER 0
#define SSL_USE_SIGALGS(s) 0

#define SSL_IS_DTLS(s) 0
#define TLS1_2_VERSION 0
#define TLS1_1_VERSION 0
#define TLS1_VERSION 0
#define SSL3_VERSION 0
#define SSL2_VERSION 0
#define TLS_MAX_VERSION 0

static const SSL_METHOD sslv23_method = {0};

#define SSLv23_method() (&sslv23_method)

int ssl_cert_inst(void **cert);
int SSLerr(int f, int r);
int ssl_cert_set1_chain(void *cert, STACK_OF(X509) *chain);
int ssl_cert_set0_chain(void *cert, STACK_OF(X509) *chain);
int ssl_cert_add1_chain_cert(void *cert, X509 *x);
int ssl_cert_add0_chain_cert(void *cert, X509 *x);
int ssl_cert_select_current(void *cert, X509 *x);
int ssl_cert_set_current(void *cert, long l);
int ssl_build_cert_chain(void *cert, void *store, long flags);
int ssl_cert_set_cert_store(void *cert, void *store, int chain, long flags);
int ssl3_set_req_cert_type(void *cert, void *p, long l);
int tls1_set_sigalgs(void *c, void *parg, long larg, int client);
int tls1_set_sigalgs_list(void *c, void *str, int client);
CERT_PKEY *ssl_get_server_send_pkey(SSL *s);
int EVP_PKEY_size(EVP_PKEY *pkey);
EVP_PKEY *EVP_PKEY_new();
int EVP_PKEY_set1_RSA(EVP_PKEY *pkey, RSA *key);
int EVP_PKEY_set1_DH(EVP_PKEY *pkey, DH *key);
int EVP_PKEY_set1_EC_KEY(EVP_PKEY *pkey, EC_KEY *key);
void EVP_PKEY_free(EVP_PKEY *pkey);
int EVP_MD_type(const EVP_MD *md);