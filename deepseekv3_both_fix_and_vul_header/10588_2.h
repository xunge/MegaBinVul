#include <stdint.h>
#include <stdlib.h>

typedef uint32_t pixman_format_code_t;
typedef struct pixman_image pixman_image_t;

struct virtio_gpu_rect {
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
};

struct virtio_gpu_set_scanout {
    uint32_t scanout_id;
    uint32_t resource_id;
    struct virtio_gpu_rect r;
};

struct virtio_gpu_simple_resource {
    pixman_image_t *image;
    uint32_t width;
    uint32_t height;
    uint32_t scanout_bitmask;
};

struct virtio_gpu_scanout {
    uint32_t resource_id;
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
    void *ds;
    void *con;
};

struct virtio_gpu_ctrl_command {
    uint32_t error;
};

struct VirtIOGPUConf {
    uint32_t max_outputs;
};

typedef struct VirtIOGPU {
    struct VirtIOGPUConf conf;
    uint32_t enable;
    struct virtio_gpu_scanout *scanout;
} VirtIOGPU;

#define VIRTIO_GPU_FILL_CMD(cmd)
#define VIRTIO_GPU_RESP_ERR_INVALID_SCANOUT_ID 0
#define VIRTIO_GPU_RESP_ERR_INVALID_RESOURCE_ID 0
#define VIRTIO_GPU_RESP_ERR_INVALID_PARAMETER 0
#define VIRTIO_GPU_RESP_ERR_UNSPEC 0

#define LOG_GUEST_ERROR 0
#define qemu_log_mask(mask, fmt, ...)
#define trace_virtio_gpu_cmd_set_scanout(id, res_id, w, h, x, y)

#define PIXMAN_FORMAT_BPP(format) (32)

void virtio_unref_resource(pixman_image_t *image, void *data);
void *surface_data(void *ds);
void dpy_gfx_replace_surface(void *con, void *ds);
void *qemu_create_displaysurface_pixman(pixman_image_t *image);
struct virtio_gpu_simple_resource *virtio_gpu_find_resource(VirtIOGPU *g, uint32_t res_id);

uint32_t pixman_image_get_format(pixman_image_t *image);
uint32_t pixman_image_get_stride(pixman_image_t *image);
void *pixman_image_get_data(pixman_image_t *image);
pixman_image_t *pixman_image_create_bits(uint32_t format, int width, int height, void *bits, int stride);
void pixman_image_ref(pixman_image_t *image);
void pixman_image_set_destroy_function(pixman_image_t *image, void (*function)(pixman_image_t *, void *), void *data);