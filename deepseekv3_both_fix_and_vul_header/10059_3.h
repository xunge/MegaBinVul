#include <stddef.h>
#include <stdint.h>
#include <sys/uio.h>

typedef struct VirtIOGPU VirtIOGPU;

struct virtio_gpu_ctrl_command {
    int error;
};

struct virtio_gpu_resource_attach_backing {
    uint32_t resource_id;
    uint32_t nr_entries;
};

#define VIRTIO_GPU_FILL_CMD(x)
#define VIRTIO_GPU_RESP_ERR_UNSPEC 0

extern int virtio_gpu_create_mapping_iov(struct virtio_gpu_resource_attach_backing *att_rb,
                                        struct virtio_gpu_ctrl_command *cmd,
                                        void *null, struct iovec **res_iovs);
extern void virtio_gpu_cleanup_mapping_iov(struct iovec *res_iovs, uint32_t nr_entries);
extern int virgl_renderer_resource_attach_iov(uint32_t resource_id,
                                             struct iovec *iov, uint32_t nr_entries);
extern void trace_virtio_gpu_cmd_res_back_attach(uint32_t resource_id);