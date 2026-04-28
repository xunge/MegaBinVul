#include <stddef.h>
#include <sys/types.h>

#define GFP_KERNEL 0
#define ENOMEM 12
#define EFAULT 14

struct kiocb {
    struct file *ki_filp;
};

struct iov_iter;
struct file {
    void *private_data;
};

struct qrtr_endpoint {
    // 最小化定义以满足编译
    int dummy;
};

struct qrtr_tun {
    struct qrtr_endpoint ep;
};

size_t iov_iter_count(struct iov_iter *i);
int copy_from_iter_full(void *addr, size_t bytes, struct iov_iter *i);
ssize_t qrtr_endpoint_post(struct qrtr_endpoint *ep, const void *data, size_t len);

void *kzalloc(size_t size, int flags);