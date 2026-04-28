#include <stdbool.h>
#include <stdio.h>

struct device {
    char name[32];
};
struct pci_dev {
    struct device dev;
};

struct idxd_device {
    struct pci_dev *pdev;
};
struct idxd_wq {
    struct idxd_device *idxd;
    struct device conf_dev;
    int state;
    int id;
    int client_count;
    int wq_lock;
};

enum idxd_wq_state {
    IDXD_WQ_DISABLED,
};

static inline void mutex_lock(int *lock) {}
static inline void mutex_unlock(int *lock) {}
static inline void dev_dbg(struct device *dev, const char *fmt, ...) {}
static inline void dev_warn(struct device *dev, const char *fmt, ...) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline const char *dev_name(struct device *dev) { return dev->name; }
static inline bool is_idxd_wq_dmaengine(struct idxd_wq *wq) { return false; }
static inline bool is_idxd_wq_cdev(struct idxd_wq *wq) { return false; }
static inline void idxd_unregister_dma_channel(struct idxd_wq *wq) {}
static inline void idxd_wq_del_cdev(struct idxd_wq *wq) {}
static inline int idxd_wq_refcount(struct idxd_wq *wq) { return 0; }
static inline void idxd_wq_unmap_portal(struct idxd_wq *wq) {}
static inline void idxd_wq_drain(struct idxd_wq *wq) {}
static inline int idxd_wq_disable(struct idxd_wq *wq) { return 0; }
static inline void idxd_wq_free_resources(struct idxd_wq *wq) {}