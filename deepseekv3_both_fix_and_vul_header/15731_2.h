#include <stdint.h>
#include <string.h>

struct device {
    // minimal device structure
};

struct pci_dev {
    struct device dev;
};

struct idxd_device {
    struct pci_dev *pdev;
    void *reg_base;
    unsigned int wqcfg_size;
    void *dev_lock;
};

struct idxd_wq {
    struct idxd_device *idxd;
    void *wqcfg;
    int type;
    unsigned int size;
    void *group;
    unsigned int threshold;
    unsigned int priority;
    unsigned long flags;
    char name[32];
    int id;
};

#define IDXD_WQT_NONE 0
#define WQ_NAME_SIZE 32
#define WQ_FLAG_DEDICATED 0
#define WQCFG_STRIDES(x) 4
#define WQCFG_OFFSET(x, y, z) ((y) * 0x100 + (z) * 0x10)

static inline void iowrite32(uint32_t val, void *addr) {
    *(volatile uint32_t *)addr = val;
}
static inline uint32_t ioread32(void *addr) {
    return *(volatile uint32_t *)addr;
}

static inline void clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

#define dev_dbg(dev, fmt, ...)
#define lockdep_assert_held(lock)