#include <stddef.h>

typedef struct SIGALG_LOOKUP {
    int sigandhash;
} SIGALG_LOOKUP;

typedef struct ssl3_ctx_st {
    struct {
        int *peer_cert_sigalgs;
        size_t peer_cert_sigalgslen;
    } tmp;
} ssl3_ctx_st;

typedef struct X509 {
    int dummy;
} X509;

typedef struct ssl_st {
    ssl3_ctx_st *s3;
    size_t shared_sigalgslen;
    const SIGALG_LOOKUP **shared_sigalgs;
} SSL;

#define SSL_IS_TLS13(s) (0)

static int X509_get_signature_nid(X509 *x) { return 0; }
static const SIGALG_LOOKUP *tls1_lookup_sigalg(int sigalg) { return NULL; }