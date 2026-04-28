#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

struct virtio_gpu_ctrl_command {
    int error;
};

struct virtio_gpu_simple_resource {
    uint32_t iov_cnt;
    void *addrs;
    void *iov;
};

struct virtio_gpu_resource_attach_backing {
    uint32_t resource_id;
    uint32_t nr_entries;
};

#define VIRTIO_GPU_FILL_CMD(x)
#define VIRTIO_GPU_RESP_ERR_INVALID_RESOURCE_ID 0
#define VIRTIO_GPU_RESP_ERR_UNSPEC 0
#define LOG_GUEST_ERROR 0

typedef struct VirtIOGPU VirtIOGPU;

static inline void trace_virtio_gpu_cmd_res_back_attach(uint32_t id) {}
static inline void qemu_log_mask(int mask, const char *fmt, ...) {}
static inline struct virtio_gpu_simple_resource *virtio_gpu_find_resource(VirtIOGPU *g, uint32_t id) { return NULL; }
static inline int virtio_gpu_create_mapping_iov(struct virtio_gpu_resource_attach_backing *ab, 
                                              struct virtio_gpu_ctrl_command *cmd, 
                                              void **addrs, 
                                              void **iov) { return 0; }