#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Error Error;
typedef struct QIOChannel QIOChannel;

#define QIO_CHANNEL_ERR_BLOCK (-1)
#define G_IO_IN  1
#define G_IO_OUT 4
#define TRACE(...)

static inline void *g_new_iovec(size_t n) {
    return calloc(n, sizeof(struct iovec));
}

static inline void g_free(void *ptr) {
    free(ptr);
}

size_t iov_copy(struct iovec *dst, size_t dst_cnt, struct iovec *src, size_t src_cnt, size_t offset, size_t len);
void iov_discard_front(struct iovec **iov, unsigned int *iov_cnt, size_t bytes);
bool qemu_in_coroutine(void);
void qemu_coroutine_yield(void);
ssize_t qio_channel_readv(QIOChannel *ioc, struct iovec *iov, size_t niov, Error **errp);
ssize_t qio_channel_writev(QIOChannel *ioc, struct iovec *iov, size_t niov, Error **errp);
void qio_channel_wait(QIOChannel *ioc, int condition);
const char *error_get_pretty(Error *err);
void error_free(Error *err);

#define g_new(type, n) g_new_iovec(n)