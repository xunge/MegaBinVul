#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef int16_t s16;

struct vhost_virtqueue {
    struct {
        int lock;
    } mutex;
    void *private_data;
    struct iovec *iov;
    void *heads;
    void *log;
    void *poll;
};

struct vhost_net_virtqueue {
    struct vhost_virtqueue vq;
    size_t vhost_hlen;
    size_t sock_hlen;
    void *hdr;
};

struct vhost_net {
    struct {
        struct vhost_virtqueue *vq;
    } dev;
    struct vhost_net_virtqueue vqs[1];
};

struct vhost_log;
struct socket {
    void *sk;
    struct {
        int (*recvmsg)(void *, struct socket *, struct msghdr *, size_t, int);
    } *ops;
};
struct iovec;

#define VHOST_NET_VQ_RX 0
#define VHOST_F_LOG_ALL 0
#define VIRTIO_NET_F_MRG_RXBUF 0
#define VIRTIO_NET_HDR_GSO_NONE 0
#define VHOST_NET_WEIGHT 64

#define unlikely(x) (x)
#define likely(x) (x)
#define uninitialized_var(x) x

struct virtio_net_hdr_mrg_rxbuf {
    struct {
        int flags;
        int gso_type;
    } hdr;
    int num_buffers;
};

static void mutex_lock(void *lock) {}
static void mutex_unlock(void *lock) {}
static void vhost_disable_notify(struct vhost_net *net, struct vhost_virtqueue *vq) {}
static int vhost_enable_notify(struct vhost_net *net, struct vhost_virtqueue *vq) { return 0; }
static int vhost_has_feature(struct vhost_net *net, int feature) { return 0; }
static size_t peek_head_len(void *sk) { return 0; }
static int get_rx_bufs(struct vhost_virtqueue *vq, void *heads, size_t len, unsigned *in, 
                      struct vhost_log *log, unsigned *log_num, int max) { return 0; }
static void move_iovec_hdr(struct iovec *iov, void *hdr, size_t len, unsigned in) {}
static void copy_iovec_hdr(struct iovec *iov, void *hdr, size_t len, unsigned in) {}
static void vhost_discard_vq_desc(struct vhost_virtqueue *vq, int count) {}
static void vhost_add_used_and_signal_n(struct vhost_net *net, struct vhost_virtqueue *vq, 
                                      void *heads, int count) {}
static void vhost_log_write(struct vhost_virtqueue *vq, struct vhost_log *log, 
                           unsigned log_num, size_t len) {}
static void vhost_poll_queue(void *poll) {}
static void vq_err(struct vhost_virtqueue *vq, const char *fmt, ...) {}
static int memcpy_toiovecend(void *iov, const void *from, int offset, int len) { return 0; }
static void pr_debug(const char *fmt, ...) {}