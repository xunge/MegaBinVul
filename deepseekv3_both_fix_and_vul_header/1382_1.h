#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <inttypes.h>

#define SOCKET_ID_ANY -1
#define RTE_VHOST_MSG_RESULT_OK 0
#define RTE_VHOST_MSG_RESULT_ERR -1
#define VHOST_LOG_CONFIG(level, fmt, ...)
#define ERR 0
#define INFO 1
#define __rte_unused __attribute__((unused))

struct inflight_desc {
    uint32_t desc_num;
};

struct inflight_mem_info {
    int fd;
    void *addr;
    size_t size;
};

struct vhost_virtqueue {
    int numa_node;
    struct inflight_desc *inflight_packed;
    struct inflight_desc *inflight_split;
};

struct vhu_inflight_payload {
    uint64_t mmap_size;
    uint64_t mmap_offset;
    uint16_t num_queues;
    uint16_t queue_size;
};

struct vhu_msg_payload {
    struct vhu_inflight_payload inflight;
};

struct vhu_msg {
    uint32_t size;
    struct vhu_msg_payload payload;
};

struct vhu_msg_context {
    int *fds;
    struct vhu_msg msg;
};

struct virtio_net {
    char *ifname;
    unsigned int nr_vring;
    struct vhost_virtqueue **virtqueue;
    struct inflight_mem_info *inflight_info;
};

static int vq_is_packed(struct virtio_net *dev);
static uint32_t get_pervq_shm_size_packed(uint16_t queue_size);
static uint32_t get_pervq_shm_size_split(uint16_t queue_size);