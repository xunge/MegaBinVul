typedef int pj_status_t;

typedef struct pj_ssl_sock_t {
    unsigned long last_err;
} pj_ssl_sock_t;

#define SSL_ERROR_SSL 1
#define ERROR_LOG(func, err, sock)
#define GET_STATUS_FROM_SSL_ERR(err) (0)
#define ERR_get_error() 0