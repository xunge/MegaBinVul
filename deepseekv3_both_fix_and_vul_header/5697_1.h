#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct _ftpbuf_t {
    void *data;
    void *stream;
    int closestream;
    int fd;
    int ssl_active;
    void *ssl_handle;
} ftpbuf_t;

extern void data_close(ftpbuf_t *ftp, void *data);
extern void ftp_gc(ftpbuf_t *ftp);
extern void efree(void *ptr);
#define TSRMLS_FETCH()
#define HAVE_OPENSSL_EXT 0
#define closesocket close