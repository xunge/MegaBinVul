#include <stddef.h>

struct X509;
struct x509_verify_ctx;
struct x509_verify_chain;

#define X509_V_OK 0
#define X509_V_ERR_CERT_CHAIN_TOO_LONG 1
#define X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY 2
#define X509_V_ERR_OUT_OF_MEM 3

struct x509_verify_chain {
    void *certs;
    int *cert_errors;
};

struct x509_verify_ctx {
    struct x509_verify_chain **chains;
    size_t chains_count;
    size_t max_chains;
    int error;
    size_t error_depth;
};

extern struct X509 *x509_verify_chain_last(struct x509_verify_chain *chain);
extern struct X509 *x509_verify_chain_leaf(struct x509_verify_chain *chain);
extern struct x509_verify_chain *x509_verify_chain_dup(struct x509_verify_chain *chain);
extern int x509_verify_cert_error(struct x509_verify_ctx *ctx, struct X509 *cert, size_t depth, int error, int ok);
extern int x509_verify_ctx_validate_legacy_chain(struct x509_verify_ctx *ctx, struct x509_verify_chain *chain, size_t depth);
extern int x509_verify_cert_valid(struct x509_verify_ctx *ctx, struct X509 *cert, void *unused);
extern int x509_verify_cert_hostname(struct x509_verify_ctx *ctx, struct X509 *cert, char *name);
extern int sk_X509_num(void *sk);

typedef struct X509 X509;