#include <stdlib.h>

typedef struct ssl3_state_st {
    struct {
        unsigned char *peer_sigalgs;
        size_t peer_sigalgslen;
    } tmp;
} ssl3_state;

typedef struct ssl_st {
    ssl3_state *s3;
} SSL;

void OPENSSL_free(void *ptr);