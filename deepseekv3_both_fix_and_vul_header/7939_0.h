#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_st SSL;

#define OPENSSL_NO_TLSEXT
#define SSL_SESS_CACHE_NO_INTERNAL_LOOKUP 0
#define SSL_SESS_CACHE_NO_INTERNAL_STORE 0
#define SSL_F_SSL_GET_PREV_SESSION 0
#define SSL_R_SESSION_ID_CONTEXT_UNINITIALIZED 0
#define SSL3_VERSION_MAJOR 0
#define CRYPTO_LOCK_SSL_CTX 0
#define CRYPTO_LOCK_SSL_SESSION 0
#define SSL_VERIFY_PEER 0

struct ssl_session_st {
    int ssl_version;
    int session_id_length;
    unsigned char session_id[1];
    int sid_ctx_length;
    unsigned char sid_ctx[1];
    void *cipher;
    unsigned long cipher_id;
    long timeout;
    time_t time;
    int references;
    int verify_result;
};

struct ssl_ctx_st {
    int session_cache_mode;
    struct lhash_st_SSL_SESSION *sessions;
    struct {
        int sess_miss;
        int sess_cb_hit;
        int sess_timeout;
        int sess_hit;
    } stats;
    SSL_SESSION *(*get_session_cb)(SSL *ssl, unsigned char *session_id, int len, int *copy);
};

struct ssl_st {
    int version;
    SSL_CTX *session_ctx;
    SSL_SESSION *session;
    int sid_ctx_length;
    unsigned char sid_ctx[1];
    int verify_mode;
    int verify_result;
    int tlsext_ticket_expected;
};

void CRYPTO_r_lock(int lock);
void CRYPTO_r_unlock(int lock);
void CRYPTO_add(int *a, int b, int lock);
void *lh_SSL_SESSION_retrieve(void *lh, SSL_SESSION *s);
void SSLerr(int f, int r);
void *ssl_get_cipher_by_char(SSL *s, unsigned char *p);
int SSL_CTX_add_session(SSL_CTX *ctx, SSL_SESSION *s);
void SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *s);
void SSL_SESSION_free(SSL_SESSION *s);
int tls1_process_ticket(SSL *s, unsigned char *session_id, int len, const unsigned char *limit, SSL_SESSION **ret);