#include <stdbool.h>
#include <stdio.h>

struct device {
    bool is_registered;
};

struct rfkill {
    bool blocked;
};

struct nfc_dev;

struct nfc_ops {
    int (*dev_up)(struct nfc_dev *dev);
    int (*discover_se)(struct nfc_dev *dev);
};

struct nfc_dev {
    struct device dev;
    bool shutting_down;
    bool fw_download_in_progress;
    bool dev_up;
    struct rfkill *rfkill;
    const struct nfc_ops *ops;
};

int device_is_registered(struct device *dev) { return dev->is_registered; }
void device_lock(struct device *dev) {}
void device_unlock(struct device *dev) {}
char *dev_name(struct device *dev) { return "nfc_device"; }
int rfkill_blocked(struct rfkill *rfkill) { return rfkill->blocked; }
void pr_debug(const char *fmt, ...) {}
void pr_err(const char *fmt, ...) {}

#define ENODEV 19
#define ERFKILL 132
#define EBUSY 16
#define EALREADY 114