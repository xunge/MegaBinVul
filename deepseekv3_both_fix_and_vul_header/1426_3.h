#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct device {
    const char *name;
};

struct timer_list {
    unsigned long expires;
};

struct nfc_target {
    u32 idx;
};

struct nfc_dev;

struct nfc_ops {
    int (*deactivate_target)(struct nfc_dev *dev, struct nfc_target *target, u8 mode);
    int (*check_presence)(struct nfc_dev *dev);
};

struct nfc_dev {
    struct device dev;
    struct nfc_target *active_target;
    struct nfc_ops *ops;
    struct timer_list check_pres_timer;
    bool shutting_down;
};

#define ENODEV 19
#define ENOTCONN 107
#define pr_debug(fmt, ...) 

void device_lock(struct device *dev);
void device_unlock(struct device *dev);
int device_is_registered(struct device *dev);
void del_timer_sync(struct timer_list *timer);
const char *dev_name(const struct device *dev);