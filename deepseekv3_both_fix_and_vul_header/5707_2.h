#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

typedef int php_socket_t;

typedef struct _ftpbuf {
    int use_ssl;
    php_socket_t fd;
    int ssl_active;
    void *ssl_handle;
    int timeout_sec;
    struct {
        int ssl_active;
        void *ssl_handle;
    } *data;
    int use_ssl_for_data;
} ftpbuf_t;

#define PHP_POLLREADABLE 1
#define PHP_WIN32 0
#define NETWARE 0
#define USE_WINSOCK 0
#define HAVE_OPENSSL_EXT 0

int php_pollfd_for_ms(php_socket_t s, int event, int timeout);