#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct device {
    void *parent;
};

struct virtio_device {
    struct device dev;
};

struct virtio_gpu_device {
    struct virtio_device *vdev;
};

struct drm_gem_shmem_object {
    void *base;
};

struct virtio_gpu_object {
    struct drm_gem_shmem_object base;
};

struct virtio_gpu_mem_entry {
    uint64_t addr;
    uint32_t length;
    uint32_t padding;
};

struct scatterlist {
    uint32_t length;
};

struct sg_table {
    unsigned int nents;
    unsigned int orig_nents;
};

struct virtio_gpu_object_shmem {
    struct virtio_gpu_object base;
    struct sg_table *pages;
    unsigned int mapped;
};

#define to_virtio_gpu_shmem(bo) ((struct virtio_gpu_object_shmem *)(bo))
#define GFP_KERNEL 0
#define DMA_TO_DEVICE 0
#define EINVAL 1
#define ENOMEM 2
#define DRM_ERROR(fmt, ...)

static inline bool virtio_has_dma_quirk(struct virtio_device *vdev) { return false; }
static inline int drm_gem_shmem_pin(struct drm_gem_shmem_object *obj) { return 0; }
static inline void drm_gem_shmem_unpin(struct drm_gem_shmem_object *obj) {}
static inline struct sg_table *drm_gem_shmem_get_sg_table(struct drm_gem_shmem_object *obj) { return NULL; }
static inline int dma_map_sgtable(void *dev, struct sg_table *sgt, int dir, int flags) { return 0; }
static inline void *kvmalloc_array(size_t n, size_t size, int flags) { return malloc(n * size); }
static inline uint64_t cpu_to_le64(uint64_t x) { return x; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }
static inline uint64_t sg_dma_address(struct scatterlist *sg) { return 0; }
static inline uint32_t sg_dma_len(struct scatterlist *sg) { return 0; }
static inline uint64_t sg_phys(struct scatterlist *sg) { return 0; }

#define for_each_sgtable_dma_sg(sgt, sg, i) for (i = 0; i < (sgt)->nents; i++, sg = NULL)
#define for_each_sgtable_sg(sgt, sg, i) for (i = 0; i < (sgt)->orig_nents; i++, sg = NULL)