#include <sys/socket.h>
#include <unistd.h>

typedef struct databuf_t {
    int listener;
    int fd;
#if HAVE_OPENSSL_EXT
    void *ssl_handle;
    int ssl_active;
#endif
} databuf_t;

typedef struct ftpbuf_t {
    databuf_t *data;
} ftpbuf_t;

#define HAVE_OPENSSL_EXT 0
#define closesocket close
#define efree free