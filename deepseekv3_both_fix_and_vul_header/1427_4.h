#include <stdint.h>
#include <stdbool.h>

#define ENODEV 19
#define EOPNOTSUPP 95
#define EINVAL 22
#define EALREADY 114

typedef uint32_t u32;

struct device {
    bool is_registered;
};

struct nfc_dev;
struct nfc_se;

enum {
    NFC_SE_DISABLED,
    NFC_SE_ENABLED
};

struct nfc_ops {
    int (*enable_se)(struct nfc_dev *dev, u32 se_idx);
    int (*disable_se)(struct nfc_dev *dev, u32 se_idx);
};

struct nfc_dev {
    struct device dev;
    bool dev_up;
    bool shutting_down;
    struct nfc_ops *ops;
};

struct nfc_se {
    int state;
};

extern char *dev_name(struct device *dev);
extern void device_lock(struct device *dev);
extern void device_unlock(struct device *dev);
extern bool device_is_registered(struct device *dev);
extern struct nfc_se *nfc_find_se(struct nfc_dev *dev, u32 se_idx);