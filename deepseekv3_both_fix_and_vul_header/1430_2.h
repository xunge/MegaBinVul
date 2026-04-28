#include <stdint.h>
#include <stdbool.h>

#define ENODEV 19
#define EBUSY 16
#define EOPNOTSUPP 95
#define EINVAL 22
#define EALREADY 114
#define NFC_SE_ENABLED 1

typedef uint32_t u32;

struct device {
    bool is_registered;
};

struct nfc_se {
    int state;
};

struct nfc_ops {
    int (*enable_se)(struct nfc_dev *dev, u32 se_idx);
    int (*disable_se)(struct nfc_dev *dev, u32 se_idx);
};

struct nfc_dev {
    struct device dev;
    bool shutting_down;
    bool dev_up;
    bool polling;
    struct nfc_ops *ops;
};

static inline void device_lock(struct device *dev) {}
static inline void device_unlock(struct device *dev) {}
static inline bool device_is_registered(struct device *dev) { return dev->is_registered; }
static inline const char *dev_name(const struct device *dev) { return ""; }
#define pr_debug(fmt, ...) 

struct nfc_se *nfc_find_se(struct nfc_dev *dev, u32 se_idx);