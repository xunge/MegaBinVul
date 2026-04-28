#include <stdlib.h>

typedef enum {
    WORK_FINISHED_CONTINUE,
    WORK_FINISHED_STOP
} WORK_STATE;

#define OPENSSL_NO_SCTP
#define SSL_IS_DTLS(s) 0
#define SSL_SESS_CACHE_SERVER 0
#define SSL_SESS_CACHE_CLIENT 1
#define SSL_CB_HANDSHAKE_DONE 1

typedef struct BUF_MEM BUF_MEM;
typedef struct bio_st BIO;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct dtls1_state_st DTLS1_STATE;

struct ssl_st {
    SSL_CTX *ctx;
    void (*handshake_func)(struct ssl_st *);
    void (*info_callback)(const struct ssl_st *ssl, int type, int val);
    BUF_MEM *init_buf;
    int init_num;
    int server;
    int renegotiate;
    int new_session;
    int hit;
    DTLS1_STATE *d1;
    BIO *wbio;
};

struct ssl_ctx_st {
    void (*info_callback)(const struct ssl_st *ssl, int type, int val);
    struct {
        unsigned int sess_accept_good;
        unsigned int sess_hit;
        unsigned int sess_connect_good;
    } stats;
};

struct dtls1_state_st {
    unsigned int handshake_read_seq;
    unsigned int handshake_write_seq;
    unsigned int next_handshake_write_seq;
};

typedef struct ssl_st SSL;

WORK_STATE dtls_wait_for_dry(SSL *s);
void ssl3_cleanup_key_block(SSL *s);
void BUF_MEM_free(BUF_MEM *buf);
void ssl_free_wbio_buffer(SSL *s);
void ssl_update_cache(SSL *s, int mode);
void ossl_statem_accept(SSL *s);
void ossl_statem_connect(SSL *s);
BIO *SSL_get_wbio(SSL *s);
int BIO_dgram_is_sctp(BIO *bio);