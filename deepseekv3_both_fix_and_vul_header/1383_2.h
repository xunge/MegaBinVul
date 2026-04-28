#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <inttypes.h>
#include <string.h>

#define __rte_unused __attribute__((unused))
#define SOCKET_ID_ANY (-1)
#define RTE_VHOST_MSG_RESULT_ERR 0
#define RTE_VHOST_MSG_RESULT_REPLY 1
#define VHOST_LOG_CONFIG(level, fmt, ...)

struct virtio_net {
    char *ifname;
    unsigned int nr_vring;
    struct virtqueue **virtqueue;
    struct inflight_mem_info *inflight_info;
};

struct vhu_msg_context {
    struct {
        size_t size;
        union {
            struct {
                uint16_t num_queues;
                uint16_t queue_size;
                uint64_t mmap_size;
                uint64_t mmap_offset;
            } inflight;
        } payload;
    } msg;
    int *fds;
    int fd_num;
};

struct rte_vhost_inflight_info_packed {
    uint16_t used_wrap_counter;
    uint16_t old_used_wrap_counter;
    struct {
        uint16_t next;
    } desc[];
};

struct inflight_mem_info {
    void *addr;
    size_t size;
    int fd;
};

struct virtqueue {
    int numa_node;
};

static int vq_is_packed(struct virtio_net *dev);
static uint64_t get_pervq_shm_size_packed(uint16_t queue_size);
static uint64_t get_pervq_shm_size_split(uint16_t queue_size);
static void *inflight_mem_alloc(struct virtio_net *dev, const char *name, uint64_t size, int *fd);