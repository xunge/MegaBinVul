#include <stdint.h>
#include <string.h>

typedef uint32_t u32;

struct device {
    // dummy device structure
};

struct pci_dev {
    struct device dev;
};

struct wqcfg {
    uint32_t wq_size;
    uint32_t wq_thresh;
    uint32_t priv;
    uint32_t mode;
    uint32_t priority;
    uint32_t max_xfer_shift;
    uint32_t max_batch_shift;
    uint32_t bits[];
};

struct idxd_device {
    struct pci_dev *pdev;
    void *reg_base;
    unsigned int wqcfg_size;
};

struct idxd_wq {
    struct idxd_device *idxd;
    struct wqcfg *wqcfg;
    unsigned int size;
    unsigned int threshold;
    unsigned int type;
    unsigned int priority;
    unsigned int max_xfer_bytes;
    unsigned int max_batch_size;
    int id;
    void *group;
};

enum idxd_wq_type {
    IDXD_WQT_KERNEL,
    IDXD_WQT_USER
};

#define WQCFG_STRIDES(idxd) (0)
#define WQCFG_OFFSET(idxd, id, i) (0)

static inline uint32_t ioread32(const volatile void *addr) { return 0; }
static inline void iowrite32(uint32_t val, volatile void *addr) {}
static inline int ilog2(unsigned long n) { return 0; }
#define dev_warn(dev, fmt, ...)
#define dev_dbg(dev, fmt, ...)
#define EINVAL 22