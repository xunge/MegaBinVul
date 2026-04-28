#include <stddef.h>

typedef struct pj_ssl_sock_t pj_ssl_sock_t;
typedef struct ossl_sock_t ossl_sock_t;
typedef struct SSL SSL;

extern int sslsock_idx;

enum {
    SSL_STATE_NULL
};

struct pj_ssl_sock_t {
    void *write_mutex;
    int ssl_state;
    void *shutdown_op_key;
};

struct ossl_sock_t {
    SSL *ossl_ssl;
    pj_ssl_sock_t *ssock;
};

int SSL_set_ex_data(SSL *ssl, int idx, void *data);
int SSL_in_init(SSL *ssl);
int SSL_shutdown(SSL *ssl);
void ERR_clear_error(void);

void pj_lock_acquire(void *mutex);
void pj_lock_release(void *mutex);
void ssl_close_sockets(pj_ssl_sock_t *ssock);
void flush_circ_buf_output(pj_ssl_sock_t *ssock, void *key, int a, int b);