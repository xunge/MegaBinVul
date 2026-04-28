#include <stdbool.h>
#include <errno.h>

struct device {
    // Minimal device structure definition
    // Add necessary fields if needed
};

struct rfkill {
    // Minimal rfkill structure definition
    // Add necessary fields if needed  
};

struct nfc_dev;

struct nfc_ops {
    int (*dev_up)(struct nfc_dev *dev);
    int (*discover_se)(struct nfc_dev *dev);
};

struct nfc_dev {
    struct device dev;
    struct rfkill *rfkill;
    bool fw_download_in_progress;
    bool dev_up;
    const struct nfc_ops *ops;
};

// Function declarations
int rfkill_blocked(struct rfkill *rfkill);
void device_lock(struct device *dev);
void device_unlock(struct device *dev);
bool device_is_registered(struct device *dev);
const char *dev_name(const struct device *dev);
int pr_debug(const char *fmt, ...);
int pr_err(const char *fmt, ...);