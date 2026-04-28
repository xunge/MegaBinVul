#include <sys/types.h>
#include <sys/socket.h>
#include <poll.h>
#include <errno.h>

typedef int php_socket_t;
typedef struct ftpbuf_t {
    int timeout_sec;
    int use_ssl;
    php_socket_t fd;
    int ssl_active;
    void *ssl_handle;
    int use_ssl_for_data;
    struct {
        int ssl_active;
        void *ssl_handle;
    } *data;
} ftpbuf_t;

#ifdef HAVE_OPENSSL_EXT
#include <openssl/ssl.h>
#endif

int php_pollfd_for_ms(php_socket_t s, int events, int timeout);