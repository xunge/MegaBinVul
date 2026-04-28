#include <sys/socket.h>

#define SSL_OP_COOKIE_EXCHANGE 0x00002000

typedef struct ssl_st SSL;
typedef struct bio_st BIO;

struct dtls1_state_st {
    int listen;
};

struct ssl_st {
    struct dtls1_state_st *d1;
};

int SSL_set_options(SSL *s, int op);
int SSL_accept(SSL *s);
BIO *SSL_get_rbio(const SSL *s);
int BIO_dgram_get_peer(BIO *b, struct sockaddr *peer);