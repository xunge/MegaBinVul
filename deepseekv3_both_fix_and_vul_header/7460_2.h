#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <assert.h>
#include <stdio.h>

#define VIRTQUEUE_MAX_SIZE 1024
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define PRIx64 "llx"

typedef struct NetClientState NetClientState;

typedef struct VirtIODevice {
    uint64_t guest_features;
} VirtIODevice;

typedef struct VirtIONet {
    struct {
        bool enabled;
        bool enabled_software_rss;
        bool populate_hash;
    } rss_data;
    void *nic;
    size_t guest_hdr_len;
    size_t host_hdr_len;
    bool mergeable_rx_bufs;
    uint64_t guest_features;
} VirtIONet;

typedef struct VirtIONetQueue {
    void *rx_vq;
} VirtIONetQueue;

typedef struct VirtQueueElement {
    unsigned int in_num;
    const struct iovec *in_sg;
} VirtQueueElement;

typedef struct virtio_net_hdr_mrg_rxbuf {
    uint16_t num_buffers;
} virtio_net_hdr_mrg_rxbuf;

#define VIRTIO_DEVICE(obj) ((VirtIODevice *)(obj))

static inline void virtio_stw_p(VirtIODevice *vdev, void *ptr, uint16_t val) {}
static inline void virtio_error(VirtIODevice *vdev, const char *msg, ...) {}
static inline void virtqueue_detach_element(void *vq, VirtQueueElement *elem, unsigned int len) {}
static inline void virtqueue_unpop(void *vq, VirtQueueElement *elem, int len) {}
static inline void virtqueue_fill(void *vq, VirtQueueElement *elem, int len, unsigned int idx) {}
static inline void virtqueue_flush(void *vq, unsigned int count) {}
static inline void virtio_notify(VirtIODevice *vdev, void *vq) {}
static inline void g_free(void *ptr) {}

static inline VirtIONet *qemu_get_nic_opaque(NetClientState *nc) { return NULL; }
static inline VirtIONetQueue *virtio_net_get_subqueue(NetClientState *nc) { return NULL; }
static inline bool virtio_net_can_receive(NetClientState *nc) { return false; }
static inline int virtio_net_process_rss(NetClientState *nc, const uint8_t *buf, size_t size) { return -1; }
static inline NetClientState *qemu_get_subqueue(void *nic, int index) { return NULL; }
static inline bool virtio_net_has_buffers(VirtIONetQueue *q, size_t size) { return false; }
static inline bool receive_filter(VirtIONet *n, const uint8_t *buf, size_t size) { return false; }
static inline VirtQueueElement *virtqueue_pop(void *vq, size_t sz) { return NULL; }
static inline unsigned int iov_copy(struct iovec *dst, unsigned int dst_cnt, const struct iovec *src, unsigned int src_cnt, size_t offset, size_t bytes) { return 0; }
static inline void receive_header(VirtIONet *n, const struct iovec *sg, unsigned int num, const uint8_t *buf, size_t size) {}
static inline size_t iov_from_buf(const struct iovec *sg, unsigned int num, size_t offset, const void *buf, size_t bytes) { return 0; }