#include <stdbool.h>
#include <stdint.h>

typedef uint32_t u32;

struct device {
    // Minimal stub for compilation
};

struct nfc_dev {
    struct device dev;
    bool shutting_down;
    bool dev_up;
    bool polling;
    int rf_mode;
    struct nfc_ops *ops;
};

struct nfc_ops {
    int (*start_poll)(struct nfc_dev *dev, u32 im_protocols, u32 tm_protocols);
};

#define NFC_RF_NONE 0
#define ENODEV 19
#define EBUSY 16
#define EINVAL 22
#define pr_debug(fmt, ...)
#define dev_name(dev) ""
#define device_lock(dev)
#define device_unlock(dev)
#define device_is_registered(dev) true