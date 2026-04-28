typedef int pj_status_t;
typedef struct pj_ssl_sock_t {
    unsigned long last_err;
} pj_ssl_sock_t;

#define SSL_ERROR_SSL 1

unsigned long ERR_peek_error(void);
void SSLLogErrors(char *action, int ret, int err, int len, pj_ssl_sock_t *ssock);
pj_status_t GET_STATUS_FROM_SSL_ERR(unsigned long ssl_err);