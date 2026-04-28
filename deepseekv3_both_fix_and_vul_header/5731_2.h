#include <stdlib.h>
#include <string.h>

typedef struct ssl_session_st {
    unsigned char *session_id;
    unsigned int session_id_length;
    unsigned char *tlsext_tick;
    unsigned int tlsext_ticklen;
    unsigned long tlsext_tick_lifetime_hint;
} SSL_SESSION;

typedef struct ssl_ctx_st {
    int session_cache_mode;
    void (*remove_session_cb)(struct ssl_ctx_st *ctx, SSL_SESSION *sess);
} SSL_CTX;

typedef struct ssl_method_st {
    long (*ssl_get_message)(void *s, int a, int b, int c, int d, int *ok);
} SSL_METHOD;

typedef struct ssl_st {
    SSL_METHOD *method;
    unsigned char *init_msg;
    SSL_SESSION *session;
    SSL_CTX *session_ctx;
    int state;
} SSL;

#define SSL3_ST_CR_SESSION_TICKET_A 0
#define SSL3_ST_CR_SESSION_TICKET_B 1
#define SSL3_MT_NEWSESSION_TICKET 4
#define SSL_AD_DECODE_ERROR 50
#define SSL_AD_INTERNAL_ERROR 80
#define SSL_F_SSL3_GET_NEW_SESSION_TICKET 0
#define SSL_R_LENGTH_MISMATCH 0
#define ERR_R_MALLOC_FAILURE 0
#define SSL_SESS_CACHE_CLIENT 1
#define SSL_SESS_CACHE_NO_INTERNAL_STORE 2
#define SSL3_AL_FATAL 2
#define SSL_ST_ERR 0

#define OPENSSL_free free
#define OPENSSL_malloc malloc
#define SSLerr(a,b)
#define ssl3_send_alert(a,b,c)
#define EVP_sha256() NULL

#define n2l(c,l) (l = ((unsigned long)(*((c)++)))<<24L, \
                   l|=((unsigned long)(*((c)++)))<<16L, \
                   l|=((unsigned long)(*((c)++)))<< 8L, \
                   l|=((unsigned long)(*((c)++))))
#define n2s(c,l) (l = ((unsigned short)(*((c)++)))<< 8L, \
                   l|=((unsigned short)(*((c)++))))

void SSL_SESSION_free(SSL_SESSION *s);
SSL_SESSION *ssl_session_dup(SSL_SESSION *s, int allocation);
void SSL_CTX_remove_session(SSL_CTX *ctx, SSL_SESSION *s);
void EVP_Digest(const void *data, size_t count,
                unsigned char *md, unsigned int *size,
                const void *type, void *ctx);