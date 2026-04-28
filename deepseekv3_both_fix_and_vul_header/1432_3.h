#include <stdbool.h>
#include <stdio.h>

struct device {
    int dummy;
};

struct nfc_ops;

struct nfc_dev {
    struct device dev;
    bool shutting_down;
    bool dev_up;
    bool fw_download_in_progress;
    struct nfc_ops *ops;
};

struct nfc_ops {
    int (*fw_download)(struct nfc_dev *dev, const char *firmware_name);
};

#define ENODEV 19
#define EBUSY 16
#define EOPNOTSUPP 95

static inline void pr_debug(const char *fmt, ...) {}
static inline const char *dev_name(const struct device *dev) { return ""; }
static inline void device_lock(struct device *dev) {}
static inline int device_is_registered(struct device *dev) { return 1; }
static inline void device_unlock(struct device *dev) {}