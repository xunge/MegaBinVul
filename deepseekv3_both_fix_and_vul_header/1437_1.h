#include <stdbool.h>

#define pr_debug(fmt, ...) 
#define ENODEV 19
#define EALREADY 114
#define EBUSY 16

struct device {
    bool is_registered;
};

struct nfc_target;
struct nfc_ops {
    int (*dev_down)(void *dev);
};

struct nfc_dev {
    struct device dev;
    bool shutting_down;
    bool dev_up;
    bool polling;
    struct nfc_target *active_target;
    const struct nfc_ops *ops;
};

static inline void device_lock(struct device *dev) {}
static inline void device_unlock(struct device *dev) {}
static inline const char *dev_name(const struct device *dev) { return ""; }
static inline bool device_is_registered(const struct device *dev) { return dev->is_registered; }