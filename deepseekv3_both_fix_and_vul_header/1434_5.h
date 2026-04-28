#include <stdbool.h>
#include <stddef.h>

#define pr_debug(fmt, ...)
#define EOPNOTSUPP 95
#define ENODEV 19
#define EALREADY 114
#define NFC_RF_NONE 0

struct device {
    // minimal device structure needed for compilation
    int dummy;
};

struct nfc_ops {
    int (*dep_link_down)(struct nfc_dev *dev);
};

struct nfc_dev {
    struct device dev;
    struct nfc_ops *ops;
    bool shutting_down;
    bool dep_link_up;
    void *active_target;
    int rf_mode;
};

void device_lock(struct device *dev);
void device_unlock(struct device *dev);
bool device_is_registered(struct device *dev);
const char *dev_name(const struct device *dev);
void nfc_llcp_mac_is_down(struct nfc_dev *dev);
void nfc_genl_dep_link_down_event(struct nfc_dev *dev);