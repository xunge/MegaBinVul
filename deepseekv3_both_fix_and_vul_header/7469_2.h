#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>

struct device {
    // Minimal device structure definition
    char name[32];
};

struct rfkill {
    // Minimal rfkill structure definition
    int dummy;
};

struct timer_list {
    // Minimal timer_list structure definition
    int dummy;
};

struct work_struct {
    // Minimal work_struct structure definition
    int dummy;
};

struct nfc_ops {
    int (*check_presence)(struct nfc_dev *dev);
};

struct nfc_dev {
    struct device dev;
    struct rfkill *rfkill;
    struct nfc_ops *ops;
    bool shutting_down;
    struct timer_list check_pres_timer;
    struct work_struct check_pres_work;
};

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

static pthread_mutex_t nfc_devlist_mutex = PTHREAD_MUTEX_INITIALIZER;
static int nfc_devlist_generation;