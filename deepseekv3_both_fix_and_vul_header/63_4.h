#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint64_t dma_addr_t;

struct device {
    void *parent;
};

struct virtio_device {
    struct device dev;
    void *priv;
    struct {
        void (*del_vqs)(struct virtio_device *);
    } *config;
};

struct virtqueue {
    unsigned int vring_size;
};

struct rpmsg_device {
    const void *ops;
    bool little_endian;
    struct {
        struct device *parent;
        void (*release)(void);
    } dev;
};

struct scatterlist {
    void *data;
    size_t length;
};

struct idr;
struct mutex;
struct wait_queue_head;

struct virtproc_info {
    struct virtio_device *vdev;
    struct virtqueue *rvq;
    struct virtqueue *svq;
    struct idr *endpoints;
    struct mutex *endpoints_lock;
    struct mutex *tx_lock;
    struct wait_queue_head *sendq;
    unsigned int num_bufs;
    size_t buf_size;
    dma_addr_t bufs_dma;
    void *rbufs;
    void *sbufs;
};

struct virtio_rpmsg_channel {
    struct virtproc_info *vrp;
    struct rpmsg_device rpdev;
};

typedef void (*vq_callback_t)(struct virtqueue *vq);

#define MAX_RPMSG_NUM_BUFS 256
#define MAX_RPMSG_BUF_SIZE 512
#define GFP_KERNEL 0
#define ENOMEM 1
#define PTR_ERR(x) (-1)
#define IS_ERR(x) (0)
#define VIRTIO_RPMSG_F_NS 0
#define WARN_ON(x) 

static void rpmsg_recv_done(struct virtqueue *vq) {}
static void rpmsg_xmit_done(struct virtqueue *vq) {}

static const struct {
    void (*kick)(struct virtqueue *vq);
} virtio_rpmsg_ops;

static void virtio_rpmsg_release_device(void) {}

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline bool virtio_has_feature(struct virtio_device *vdev, int feature) { return false; }
static inline bool virtio_is_little_endian(struct virtio_device *vdev) { return true; }
static inline void *dma_alloc_coherent(void *dev, size_t size, dma_addr_t *dma_handle, int flags) { return malloc(size); }
static inline void dma_free_coherent(void *dev, size_t size, void *cpu_addr, dma_addr_t dma_handle) { free(cpu_addr); }
static inline void rpmsg_sg_init(struct scatterlist *sg, void *data, size_t len) { sg->data = data; sg->length = len; }
static inline int virtio_find_vqs(struct virtio_device *vdev, unsigned nvqs, struct virtqueue *vqs[], vq_callback_t callbacks[], const char * const names[], void *desc) { return 0; }
static inline unsigned virtqueue_get_vring_size(struct virtqueue *vq) { return vq->vring_size; }
static inline int virtqueue_add_inbuf(struct virtqueue *vq, struct scatterlist *sg, unsigned int num, void *data, int gfp) { return 0; }
static inline void virtqueue_disable_cb(struct virtqueue *vq) {}
static inline struct rpmsg_device *rpmsg_virtio_add_ctrl_dev(struct virtio_device *vdev) { return NULL; }
static inline bool virtqueue_kick_prepare(struct virtqueue *vq) { return false; }
static inline void virtio_device_ready(struct virtio_device *vdev) {}
static inline void virtqueue_notify(struct virtqueue *vq) {}
static inline int rpmsg_ns_register_device(struct rpmsg_device *rpdev) { return 0; }
static inline void rpmsg_virtio_del_ctrl_dev(struct rpmsg_device *rpdev) {}
static inline void dev_dbg(struct device *dev, const char *fmt, ...) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void idr_init(struct idr *idr) {}
static inline void mutex_init(struct mutex *mutex) {}
static inline void init_waitqueue_head(struct wait_queue_head *wq) {}