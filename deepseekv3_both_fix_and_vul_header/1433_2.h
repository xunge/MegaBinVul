#include <stdbool.h>
#include <pthread.h>

struct device {
    // Minimal device structure needed for compilation
    // Actual implementation would have more fields
};

struct rfkill {
    // Minimal rfkill structure needed for compilation
    // Actual implementation would have more fields
};

struct timer_list {
    // Minimal timer_list structure needed for compilation
    // Actual implementation would have more fields
};

struct work_struct {
    // Minimal work_struct structure needed for compilation
    // Actual implementation would have more fields
};

struct nfc_ops {
    bool (*check_presence)(struct nfc_dev *dev);
};

struct nfc_dev {
    struct device dev;
    struct rfkill *rfkill;
    struct nfc_ops *ops;
    bool shutting_down;
    struct timer_list check_pres_timer;
    struct work_struct check_pres_work;
};

extern int nfc_devlist_generation;
extern pthread_mutex_t nfc_devlist_mutex;

// Function declarations
extern int nfc_genl_device_removed(struct nfc_dev *dev);
extern void nfc_llcp_unregister_device(struct nfc_dev *dev);
extern void device_lock(struct device *dev);
extern void device_unlock(struct device *dev);
extern void device_del(struct device *dev);
extern void rfkill_unregister(struct rfkill *rfkill);
extern void rfkill_destroy(struct rfkill *rfkill);
extern void del_timer_sync(struct timer_list *timer);
extern void cancel_work_sync(struct work_struct *work);
extern const char *dev_name(const struct device *dev);
extern int pr_debug(const char *fmt, ...);