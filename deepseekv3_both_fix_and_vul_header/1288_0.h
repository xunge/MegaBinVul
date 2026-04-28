#include <stdint.h>

#define VHOST_MAX_VRING 64
#define VHOST_USER_VRING_IDX_MASK 0xff
#define ERR 0

enum vhost_user_request {
    VHOST_USER_SET_VRING_KICK,
    VHOST_USER_SET_VRING_CALL,
    VHOST_USER_SET_VRING_ERR,
    VHOST_USER_SET_VRING_NUM,
    VHOST_USER_SET_VRING_BASE,
    VHOST_USER_GET_VRING_BASE,
    VHOST_USER_SET_VRING_ENABLE,
    VHOST_USER_SET_VRING_ADDR,
    VHOST_USER_SET_INFLIGHT_FD
};

struct virtio_net {
    char *ifname;
    void *virtqueue[VHOST_MAX_VRING];
};

struct vhu_msg_payload {
    uint64_t u64;
    struct {
        uint32_t index;
    } state;
    struct {
        uint32_t index;
    } addr;
    struct {
        uint32_t num_queues;
    } inflight;
};

struct vhu_msg_request {
    enum vhost_user_request master;
};

struct vhu_msg_context {
    struct {
        struct vhu_msg_request request;
        struct vhu_msg_payload payload;
    } msg;
};

#define VHOST_LOG_CONFIG(level, fmt, ...)

extern int alloc_vring_queue(struct virtio_net *dev, uint32_t vring_idx);