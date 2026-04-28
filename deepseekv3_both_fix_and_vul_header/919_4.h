#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

#define EINVAL 22
#define ENODEV 19
#define XENLOG_G_ERR 0
#define ASSERT(cond) ((void)0)
#define PCI_SLOT(devfn) (((devfn) >> 3) & 0x1f)
#define PCI_FUNC(devfn) ((devfn) & 0x07)

struct domain;
struct domain_iommu;
struct pci_dev;

struct domain_iommu {
    struct {
        int (*reassign_device)(struct domain *, struct domain *, uint8_t, void *);
    } *platform_ops;
};

struct pci_dev {
    bool quarantine;
    struct domain *domain;
    uint8_t phantom_stride;
    uint8_t devfn;
    struct {
        int count;
    } fault;
};

extern struct domain *dom_io;
extern struct domain *hardware_domain;
extern bool is_iommu_enabled(struct domain *);
extern const struct domain_iommu *dom_iommu(struct domain *);
extern struct pci_dev *pci_get_pdev_by_domain(struct domain *, uint16_t, uint8_t, uint8_t);
extern void *pci_to_dev(struct pci_dev *);
extern bool pcidevs_locked();

static inline int printk(int level, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}

static inline int dprintk(int level, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}

#define printk(level, fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dprintk(level, fmt, ...) printf(fmt, ##__VA_ARGS__)