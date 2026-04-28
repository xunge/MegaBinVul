#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SSL_AD_INTERNAL_ERROR 80
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_PROTOCOL_VERSION 70
#define SSL_AD_ILLEGAL_PARAMETER 47
#define SSL_AD_HANDSHAKE_FAILURE 40

#define SSL3_ST_SR_CLNT_HELLO_A 100
#define SSL3_ST_SR_CLNT_HELLO_B 101
#define SSL3_ST_SR_CLNT_HELLO_C 102
#define SSL3_MT_CLIENT_HELLO 1
#define SSL3_RT_MAX_PLAIN_LENGTH 16384
#define SSL3_RANDOM_SIZE 32
#define SSL_MAX_SSL_SESSION_ID_LENGTH 32
#define SSL3_VERSION_MAJOR 3

#define SSL_OP_COOKIE_EXCHANGE 0x00002000
#define SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION 0x00010000
#define SSL_OP_NO_DTLSv1_2 0x04000000
#define SSL_OP_NO_DTLSv1 0x08000000
#define SSL_OP_NO_COMPRESSION 0x00020000
#define SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG 0x00000008
#define SSL_OP_NETSCAPE_DEMO_CIPHER_CHANGE_BUG 0x00000010

#define SSL_VERIFY_PEER 0x01

#define DTLS_ANY_VERSION 0
#define DTLS1_VERSION 0xFEFF
#define DTLS1_2_VERSION 0xFEFD
#define SSL3_VERSION 0x0300
#define TLS1_VERSION 0x0301

#define OPENSSL_NO_COMP
#define OPENSSL_NO_TLSEXT

#define SSL_R_LENGTH_TOO_SHORT 1
#define SSL_R_WRONG_VERSION_NUMBER 2
#define SSL_R_LENGTH_MISMATCH 3
#define SSL_R_NO_CIPHERS_SPECIFIED 4
#define SSL_R_NO_COMPRESSION_SPECIFIED 5
#define SSL_R_PARSE_TLSEXT 6
#define SSL_R_NO_SHARED_CIPHER 7
#define SSL_R_INCONSISTENT_COMPRESSION 8
#define SSL_R_INVALID_COMPRESSION_ALGORITHM 9
#define SSL_R_REQUIRED_COMPRESSSION_ALGORITHM_MISSING 10
#define SSL_R_CERT_CB_ERROR 11
#define SSL_R_CLIENTHELLO_TLSEXT 12
#define SSL_R_COOKIE_MISMATCH 13
#define SSL_R_ONLY_DTLS_1_2_ALLOWED_IN_SUITEB_MODE 14
#define SSL_R_REQUIRED_CIPHER_MISSING 15
#define ERR_R_INTERNAL_ERROR 16
#define SSL_F_SSL3_GET_CLIENT_HELLO 1000

#define SSL_X509_LOOKUP 1
#define SSL_NOTHING 0
#define SSL_ST_ERR 2

typedef struct ssl_cipher_st SSL_CIPHER;
typedef struct ssl_comp_st SSL_COMP;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_method_st SSL_METHOD;
typedef struct ssl_st SSL;
typedef struct stack_st_SSL_CIPHER STACK_OF_SSL_CIPHER;
typedef struct stack_st_SSL_COMP STACK_OF_SSL_COMP;

struct ssl_cipher_st {
    unsigned long id;
    int algorithm_enc;
    const char *name;
};

struct ssl_comp_st {
    int id;
};

struct ssl_session_st {
    int ssl_version;
    SSL_CIPHER *cipher;
    STACK_OF_SSL_CIPHER *ciphers;
    unsigned char master_key[48];
    int master_key_length;
    int verify_result;
    unsigned char compress_meth;
};

struct ssl_ctx_st {
    STACK_OF_SSL_COMP *comp_methods;
    int (*app_verify_cookie_cb)(SSL *, unsigned char *, unsigned int);
};

struct ssl_method_st {
    int version;
    int (*ssl_get_message)(SSL *, int, int, int, long, int *);
};

struct ssl_st {
    int state;
    int first_packet;
    int client_version;
    int version;
    int hit;
    int new_session;
    int options;
    int verify_mode;
    int rwstate;
    SSL_METHOD *method;
    SSL_SESSION *session;
    SSL_CTX *ctx;
    struct ssl3_state_st *s3;
    struct d1_state_st *d1;
    struct cert_st *cert;
    void *init_msg;
    void *tls_session_secret_cb_arg;
    int (*tls_session_secret_cb)(SSL *, SSL_SESSION *, unsigned char *, int *,
                                 STACK_OF_SSL_CIPHER *, SSL_CIPHER **, void *);
    int (*cert_cb)(SSL *ssl, void *arg);
    STACK_OF_SSL_CIPHER *cipher_list;
    STACK_OF_SSL_CIPHER *cipher_list_by_id;
    void *enc_write_ctx;
    void *write_hash;
};

struct ssl3_state_st {
    unsigned char client_random[SSL3_RANDOM_SIZE];
    unsigned char server_random[SSL3_RANDOM_SIZE];
    struct {
        SSL_CIPHER *new_cipher;
        SSL_COMP *new_compression;
    } tmp;
};

struct d1_state_st {
    unsigned char rcvd_cookie[256];
    unsigned char cookie[256];
    unsigned int cookie_len;
};

struct cert_st {
    int (*cert_cb)(SSL *ssl, void *arg);
    void *cert_cb_arg;
};

struct stack_st_SSL_CIPHER {
    SSL_CIPHER *data;
    int num;
};

struct stack_st_SSL_COMP {
    SSL_COMP *data;
    int num;
};

#define n2s(c,s) ((s=(((unsigned int)(c[0]))<< 8)| \
                   (((unsigned int)(c[1]))    )),c+=2)

#define SSLerr(f,r) fprintf(stderr, "SSL error: %d in %s\n", (r), #f)
#define ssl3_send_alert(s, level, desc) (0)
#define ssl_get_new_session(s, session) (1)
#define ssl_get_prev_session(s, p, j, d) (0)
#define ssl_bytes_to_cipher_list(s, p, i, ciphers) (NULL)
#define ssl_parse_clienthello_tlsext(s, p, d) (1)
#define ssl3_choose_cipher(s, c1, c2) (NULL)
#define SSL_IS_DTLS(s) (0)
#define SSL_USE_SIGALGS(s) (0)
#define SSL_get_options(s) (0)
#define SSL_get_ciphers(s) (NULL)
#define tls1_suiteb(s) (0)
#define tls1_set_server_sigalgs(s) (1)
#define ssl3_digest_cached_records(s) (1)
#define ssl_check_clienthello_tlsext_late(s) (1)
#define ssl_fill_hello_random(s, type, buf, len) (1)
#define DTLSv1_2_server_method() NULL
#define DTLSv1_server_method() NULL

#define sk_SSL_CIPHER_num(st) ((st) ? (st)->num : 0)
#define sk_SSL_CIPHER_value(st,i) ((st)->data + (i))
#define sk_SSL_CIPHER_free(st) free(st)
#define sk_SSL_CIPHER_dup(st) ((st) ? (struct stack_st_SSL_CIPHER *)memdup((st), sizeof(struct stack_st_SSL_CIPHER)) : NULL)

#define sk_SSL_COMP_num(st) ((st) ? (st)->num : 0)
#define sk_SSL_COMP_value(st,i) ((st)->data + (i))

static void *memdup(const void *src, size_t n) {
    void *dest = malloc(n);
    if (dest) memcpy(dest, src, n);
    return dest;
}

#define STACK_OF(type) struct stack_st_##type