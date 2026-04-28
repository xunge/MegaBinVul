#include <stdlib.h>
#include <string.h>

typedef struct stack_st_X509 STACK_OF_X509;
typedef struct stack_st_X509_NAME STACK_OF_X509_NAME;
typedef void (*X509_free_func)(void *);
typedef void (*X509_NAME_free_func)(void *);

typedef struct tls_buffer_st TLS_BUFFER;
typedef struct tls_content_st TLS_CONTENT;
typedef struct tls_key_share_st TLS_KEY_SHARE;
typedef struct tls13_secrets_st TLS13_SECRETS;

struct ssl3_state_st {
    TLS_CONTENT *rcontent;
    TLS_BUFFER *alert_fragment;
    TLS_BUFFER *handshake_fragment;
    struct {
        unsigned char *sigalgs;
        size_t sigalgs_len;
        STACK_OF_X509 *peer_certs;
        STACK_OF_X509 *peer_certs_no_leaf;
        TLS_KEY_SHARE *key_share;
        struct {
            TLS13_SECRETS *secrets;
            unsigned char *cookie;
            size_t cookie_len;
            TLS_BUFFER *quic_read_buffer;
        } tls13;
        struct {
            STACK_OF_X509_NAME *ca_names;
        } tls12;
    } hs;
    unsigned char *alpn_selected;
    unsigned char *peer_quic_transport_params;
    size_t peer_quic_transport_params_len;
};

typedef struct ssl_st {
    struct ssl3_state_st *s3;
    STACK_OF_X509 *verified_chain;
} SSL;

#define freezero(ptr, size) do { if (ptr) { memset(ptr, 0, size); free(ptr); } } while (0)

void X509_free(void *x);
void X509_NAME_free(void *x);
void sk_X509_pop_free(STACK_OF_X509 *sk, X509_free_func free_func);
void sk_X509_NAME_pop_free(STACK_OF_X509_NAME *sk, X509_NAME_free_func free_func);
void tls1_cleanup_key_block(SSL *s);
void ssl3_release_read_buffer(SSL *s);
void ssl3_release_write_buffer(SSL *s);
void tls_content_free(TLS_CONTENT *content);
void tls_buffer_free(TLS_BUFFER *buf);
void tls_key_share_free(TLS_KEY_SHARE *key_share);
void tls13_secrets_destroy(TLS13_SECRETS *secrets);
void tls13_clienthello_hash_clear(struct ssl3_state_st *s3);
void tls1_transcript_free(SSL *s);
void tls1_transcript_hash_free(SSL *s);