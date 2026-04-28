#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef int irqreturn_t;
typedef uint32_t spinlock_t;

struct device {
    // minimal device structure
};

struct pci_dev {
    struct device dev;
    // minimal pci_dev structure
};

struct msix_entry {
    int entry;
    int vector;
};

struct llist_head {
    // minimal llist_head structure
};

struct list_head {
    // minimal list_head structure
};

struct idxd_irq_entry {
    int id;
    struct idxd_device *idxd;
    spinlock_t list_lock;
    struct llist_head pending_llist;
    struct list_head work_list;
};

struct idxd_device {
    struct pci_dev *pdev;
    struct msix_entry *msix_entries;
    struct idxd_irq_entry *irq_entries;
    int num_wq_irqs;
    uint32_t pasid;
    void *reg_base;
    uint32_t msix_perm_offset;
};

union msix_perm {
    uint32_t bits;
    struct {
        uint32_t pasid:20;
        uint32_t rsvd:11;
        uint32_t pasid_en:1;
    };
};

#define GFP_KERNEL 0
#define ENOMEM 12

static inline void spin_lock_init(spinlock_t *lock) {}
static inline void init_llist_head(struct llist_head *list) {}
static inline void INIT_LIST_HEAD(struct list_head *list) {}
static inline void iowrite32(uint32_t value, void *addr) {}

int pci_msix_vec_count(struct pci_dev *pdev) { return 0; }
int pci_enable_msix_exact(struct pci_dev *pdev, struct msix_entry *entries, int nvec) { return 0; }
void pci_disable_msix(struct pci_dev *pdev) {}

void *devm_kzalloc(struct device *dev, size_t size, uint32_t flags) { return NULL; }
void *devm_kcalloc(struct device *dev, size_t n, size_t size, uint32_t flags) { return NULL; }
int devm_request_threaded_irq(struct device *dev, int irq, 
                            int (*handler)(int, void *),
                            irqreturn_t (*thread_fn)(int, void *),
                            unsigned long flags, const char *name, void *dev_id) { return 0; }

void dev_err(struct device *dev, const char *fmt, ...) {}
void dev_dbg(struct device *dev, const char *fmt, ...) {}

int idxd_irq_handler(int irq, void *data) { return 0; }
irqreturn_t idxd_misc_thread(int irq, void *data) { return 0; }
irqreturn_t idxd_wq_thread(int irq, void *data) { return 0; }
void idxd_unmask_error_interrupts(struct idxd_device *idxd) {}
void idxd_mask_error_interrupts(struct idxd_device *idxd) {}
bool device_pasid_enabled(struct idxd_device *idxd) { return false; }