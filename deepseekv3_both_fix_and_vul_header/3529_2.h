#include <stddef.h>
#include <stdbool.h>

#define UIO_MAXIOV 1024
#define ENOBUFS 105
#define EINVAL 22

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct vring_used_elem {
    unsigned int id;
    unsigned int len;
};

struct vhost_virtqueue {
    void *dev;
    struct iovec *iov;
    unsigned int num;
};

struct vhost_log {
    unsigned long addr;
    unsigned long len;
};

static inline bool unlikely(bool x) {
    return x;
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

unsigned long iov_length(const struct iovec *iov, unsigned long nr_segs);
void vq_err(struct vhost_virtqueue *vq, const char *fmt, ...);
void vhost_discard_vq_desc(struct vhost_virtqueue *vq, int n);
int vhost_get_vq_desc(void *dev, struct vhost_virtqueue *vq,
                     struct iovec *iov, unsigned int iov_size,
                     unsigned int *out, unsigned int *in,
                     struct vhost_log *log, unsigned *log_num);