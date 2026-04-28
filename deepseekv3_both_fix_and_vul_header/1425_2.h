#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define NFC_MAX_GT_LEN 48
#define pr_debug(fmt, ...) 

#define EOPNOTSUPP 95
#define ENODEV 19
#define EALREADY 114
#define EINVAL 22
#define ENOTCONN 107
#define NFC_RF_INITIATOR 0

typedef uint8_t u8;

struct device {
    int dummy;
};

struct nfc_dev {
    struct device dev;
    bool shutting_down;
    bool dep_link_up;
    struct nfc_ops *ops;
    struct nfc_target *active_target;
    int rf_mode;
};

struct nfc_ops {
    int (*dep_link_up)(struct nfc_dev *dev, struct nfc_target *target,
                      u8 comm_mode, u8 *gb, size_t gb_len);
};

struct nfc_target {
    int dummy;
};

static inline void device_lock(struct device *dev) {}
static inline void device_unlock(struct device *dev) {}
static inline int device_is_registered(struct device *dev) { return 1; }
static inline const char *dev_name(const struct device *dev) { return ""; }

u8 *nfc_llcp_general_bytes(struct nfc_dev *dev, size_t *gb_len);
struct nfc_target *nfc_find_target(struct nfc_dev *dev, int target_index);