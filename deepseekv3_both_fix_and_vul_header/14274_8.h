#include <stddef.h>

typedef struct x509_st X509;
typedef struct x509_store_ctx_st X509_STORE_CTX;
typedef struct x509_store_st X509_STORE;
typedef struct x509_verify_param_st X509_VERIFY_PARAM;
typedef struct ssl_st SSL;
typedef struct ssl_ctx_st SSL_CTX;

struct stack_st_X509;
typedef struct stack_st_X509 STACK_OF_X509;

struct cert_st {
    X509_STORE *verify_store;
};

struct ssl_dane_st {
    int dummy;
};

struct ssl_st {
    struct cert_st *cert;
    SSL_CTX *ctx;
    struct ssl_dane_st dane;
    int server;
    X509_VERIFY_PARAM *param;
    int (*verify_callback)(int, X509_STORE_CTX *);
    int verify_result;
    STACK_OF_X509 *verified_chain;
};

struct ssl_ctx_st {
    X509_STORE *cert_store;
    void *libctx;
    char *propq;
    int (*app_verify_callback)(X509_STORE_CTX *, void *);
    void *app_verify_arg;
};

#define ERR_LIB_SSL 0
#define ERR_R_MALLOC_FAILURE 0
#define ERR_R_X509_LIB 0

int sk_X509_num(STACK_OF_X509 *sk);
X509 *sk_X509_value(STACK_OF_X509 *sk, int idx);
void sk_X509_pop_free(STACK_OF_X509 *sk, void (*free_func)(X509 *));
int SSL_get_security_level(SSL *s);
int tls1_suiteb(SSL *s);
int SSL_get_ex_data_X509_STORE_CTX_idx(void);
int DANETLS_ENABLED(struct ssl_dane_st *dane);
void X509_free(X509 *x);

#define STACK_OF(type) STACK_OF_##type
typedef STACK_OF_X509 STACK_OF(X509);