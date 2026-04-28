#include <string.h>
#include <sys/time.h>

typedef struct bio_st BIO;
typedef struct ssl_st SSL;

struct dtls1_state_st {
    struct timeval timeout;
    struct timeval next_timeout;
    unsigned int timeout_duration;
};

struct ssl_st {
    struct dtls1_state_st *d1;
};

BIO *SSL_get_rbio(const SSL *s);
long BIO_ctrl(BIO *bp, int cmd, long larg, void *parg);
void dtls1_clear_record_buffer(SSL *s);

#define BIO_CTRL_DGRAM_SET_NEXT_TIMEOUT 45