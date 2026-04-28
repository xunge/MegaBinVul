#include <stdbool.h>

#define pr_debug(fmt, ...) 
#define ENODEV 19
#define EINVAL 22

struct device {
    bool is_registered;
};

struct nfc_dev {
    struct device dev;
    bool shutting_down;
    bool polling;
    int rf_mode;
    struct nfc_ops *ops;
};

struct nfc_ops {
    void (*stop_poll)(struct nfc_dev *dev);
};

enum {
    NFC_RF_NONE
};

void device_lock(struct device *dev) {}
void device_unlock(struct device *dev) {}
bool device_is_registered(struct device *dev) { return dev->is_registered; }
char *dev_name(struct device *dev) { return ""; }