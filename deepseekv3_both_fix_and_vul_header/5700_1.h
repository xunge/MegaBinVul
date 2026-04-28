#include <stddef.h>

typedef struct _ftpbuf_t {
    int use_ssl;
    int ssl_active;
    int resp;
    int old_ssl;
    int use_ssl_for_data;
    void *ssl_handle;
    int fd;
} ftpbuf_t;

#define HAVE_OPENSSL_EXT 0
#define TSRMLS_DC
#define TSRMLS_CC
#define E_WARNING 0