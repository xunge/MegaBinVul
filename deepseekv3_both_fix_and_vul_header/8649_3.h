#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct pci_dev;

struct vfio_pci_irq_ctx {
    int dummy;  // 添加至少一个成员使结构体完整
};

struct vfio_pci_device {
    struct pci_dev *pdev;
    struct vfio_pci_irq_ctx *ctx;
    int num_ctx;
    int irq_type;
    int msi_qmax;
};

#define PCI_IRQ_MSIX 0
#define PCI_IRQ_MSI 1
#define VFIO_PCI_MSIX_IRQ_INDEX 0
#define VFIO_PCI_MSI_IRQ_INDEX 1
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22

static inline int fls(int x) {
    return x ? sizeof(int) * 8 - __builtin_clz(x) : 0;
}

static inline bool is_irq_none(struct vfio_pci_device *vdev) {
    return false;
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline int pci_alloc_irq_vectors(struct pci_dev *dev, int min_vecs, int max_vecs, unsigned int flags) {
    return max_vecs;
}

static inline void pci_free_irq_vectors(struct pci_dev *dev) {
}