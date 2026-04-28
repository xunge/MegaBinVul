#include <stddef.h>
#include <stdbool.h>

#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define ENOMEM 12

enum ttm_bo_type {
    ttm_bo_type_device,
    ttm_bo_type_kernel
};

struct virtio_gpu_device {
    struct {
        struct {
            int bdev;
        } mman;
        int ddev;
    };
};

struct virtio_gpu_object {
    int gem_base;
    bool dumb;
    int tbo;
    int placement;
};

void virtio_gpu_init_ttm_placement(struct virtio_gpu_object *bo, bool pinned);
void virtio_gpu_ttm_bo_destroy(struct virtio_gpu_object *bo);
size_t ttm_bo_dma_acc_size(void *bdev, unsigned long size, size_t obj_size);
int drm_gem_object_init(int ddev, int *gem_base, unsigned long size);
int ttm_bo_init(void *bdev, void *tbo, unsigned long size, enum ttm_bo_type type,
                void *placement, int arg1, bool arg2, void *arg3, size_t acc_size,
                void *arg4, void *arg5, void (*destroy)(struct virtio_gpu_object *));
void *kzalloc(size_t size, int flags);
unsigned long roundup(unsigned long size, unsigned long boundary);