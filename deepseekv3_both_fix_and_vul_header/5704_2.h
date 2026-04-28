#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stddef.h>

typedef struct databuf_t {
    int fd;
    int listener;
    void *ssl_handle;
    int ssl_active;
} databuf_t;

typedef struct ftpbuf_t {
    int use_ssl;
    int use_ssl_for_data;
    int old_ssl;
    void *ssl_handle;
} ftpbuf_t;

typedef void SSL_CTX;
typedef void SSL;

#define TSRMLS_DC
#define TSRMLS_CC
#define HAVE_OPENSSL_EXT 0
#define SSL_OP_ALL 0
#define SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS 0
#define OPENSSL_VERSION_NUMBER 0

typedef union {
    struct sockaddr sa;
    struct sockaddr_in sin;
    struct sockaddr_in6 sin6;
} php_sockaddr_storage;

int my_accept(ftpbuf_t *ftp, int listener, struct sockaddr *addr, socklen_t *size);
int closesocket(int sock);
void efree(void *ptr);
void php_error_docref(const char *docref, int type, const char *format, ...);