#include <stddef.h>

typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl_st SSL;

#define SSL_OP_NO_TICKET 0x00004000L
#define SSL3_VERSION 0x0300
#define TLSEXT_TYPE_session_ticket 35

#define SSL_IS_DTLS(s) (0)

#define n2s(c,s) (s = ((unsigned int)((c)[0]) << 8) | (unsigned int)((c)[1]), (c) += 2)

struct ssl_st {
    int version;
    unsigned int tlsext_ticket_expected;
    unsigned long options;
    int (*tls_session_secret_cb)(SSL *s, void *secret, int *secret_len,
                                void *peer_ciphers, void **cipher, void *arg);
};

unsigned long SSL_get_options(SSL *s);
int tls_decrypt_ticket(SSL *s, const unsigned char *p, int size,
                      unsigned char *session_id, int len, SSL_SESSION **ret);