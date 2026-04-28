#include <stddef.h>

struct platform_device;
struct notifier_block {
    int dummy;
};
struct work_struct {
    int dummy;
};

struct da9150_charger {
    void *battery;
    void *usb;
    void *ibus_chan;
    void *vbus_chan;
    void *tjunc_chan;
    void *vbat_chan;
    void *usb_phy;
    struct notifier_block otg_nb;
    struct work_struct otg_work;
};

#define IS_ERR_OR_NULL(x) ((x) == NULL)