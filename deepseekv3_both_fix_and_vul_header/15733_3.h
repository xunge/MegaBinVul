#include <stddef.h>

struct device;

struct pci_dev {
    struct device *dev;
};

struct llist_head {
    struct llist_head *first;
};

struct list_head {
    struct list_head *next, *prev;
};

struct workqueue_struct {
    // minimal workqueue_struct
};

struct idxd_irq_entry {
    struct llist_head pending_llist;
    struct list_head work_list;
};

struct msix_entry {
    int vector;
};

struct idxd_device {
    struct msix_entry *msix_entries;
    struct idxd_irq_entry *irq_entries;
    struct workqueue_struct *wq;
    struct device *dev;
};