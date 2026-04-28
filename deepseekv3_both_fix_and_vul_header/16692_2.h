#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

#define VRING_PAGE_BITS 12
#define VIRTIO_PCI_VRING_ALIGN 4096
#define VQ_ALLOC 1

struct virtio_device {
    void *vmctx;
};

struct virtio_base {
    struct virtio_vq_info *queues;
    unsigned int curq;
    struct virtio_device *dev;
};

struct virtio_vq_info {
    uint32_t pfn;
    uint16_t qsize;
    struct vring_desc *desc;
    struct vring_avail *avail;
    struct vring_used *used;
    uint16_t last_avail;
    uint16_t save_used;
    uint16_t flags;
};

struct vring_desc {
    uint64_t addr;
    uint32_t len;
    uint16_t flags;
    uint16_t next;
};

struct vring_avail {
    uint16_t flags;
    uint16_t idx;
    uint16_t ring[];
};

struct vring_used_elem {
    uint32_t id;
    uint32_t len;
};

struct vring_used {
    uint16_t flags;
    uint16_t idx;
    struct vring_used_elem ring[];
};

static inline void mb(void) { asm volatile("" ::: "memory"); }

static inline size_t vring_size(unsigned int qsize, unsigned int align) {
    return sizeof(struct vring_desc) * qsize +
           sizeof(uint16_t) * (3 + qsize) +
           sizeof(struct vring_used_elem) * qsize;
}

static inline char *paddr_guest2host(void *vmctx, uint64_t phys, size_t size) {
    return NULL;
}

static inline uintptr_t roundup2(uintptr_t x, unsigned int align) {
    return (x + align - 1) & ~(align - 1);
}