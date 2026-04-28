#include <stdbool.h>
#include <stddef.h>

#define VHOST_NET_VQ_MAX 2
#define ENOBUFS 105
#define EFAULT 14

struct mutex {
    // dummy implementation
};

struct file {
    // dummy implementation
};

struct device {
    // dummy implementation
};

struct vhost_net_ubuf_ref {
    // dummy implementation
};

struct socket {
    struct file *file;
};

struct vhost_virtqueue {
    struct mutex mutex;
    void *private_data;
};

struct vhost_net_virtqueue {
    struct vhost_virtqueue vq;
    struct vhost_net_ubuf_ref *ubufs;
};

struct vhost_net {
    struct {
        struct mutex mutex;
        struct device dev;
    } dev;
    struct vhost_net_virtqueue vqs[VHOST_NET_VQ_MAX];
    unsigned long tx_packets;
    unsigned long tx_zcopy_err;
    bool tx_flush;
};

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline bool lockdep_is_held(struct mutex *lock) { return true; }
static inline void *rcu_dereference_protected(void *p, bool b) { return p; }
static inline void rcu_assign_pointer(void *p, void *v) {}
static inline bool IS_ERR(const void *ptr) { return false; }
static inline long PTR_ERR(const void *ptr) { return 0; }
static inline void fput(struct file *file) {}

static int vhost_dev_check_owner(struct device *dev) { return 0; }
static bool vhost_vq_access_ok(struct vhost_virtqueue *vq) { return true; }
static struct socket *get_socket(int fd) { return NULL; }
static bool vhost_sock_zcopy(struct socket *sock) { return false; }
static struct vhost_net_ubuf_ref *vhost_net_ubuf_alloc(struct vhost_virtqueue *vq, bool zcopy) { return NULL; }
static void vhost_net_disable_vq(struct vhost_net *n, struct vhost_virtqueue *vq) {}
static int vhost_init_used(struct vhost_virtqueue *vq) { return 0; }
static int vhost_net_enable_vq(struct vhost_net *n, struct vhost_virtqueue *vq) { return 0; }
static void vhost_net_ubuf_put_and_wait(struct vhost_net_ubuf_ref *ubufs) {}
static void vhost_zerocopy_signal_used(struct vhost_net *n, struct vhost_virtqueue *vq) {}
static void vhost_net_flush_vq(struct vhost_net *n, unsigned index) {}