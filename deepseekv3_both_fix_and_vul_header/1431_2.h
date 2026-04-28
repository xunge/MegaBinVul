#include <stdint.h>
#include <string.h>

typedef uint32_t u32;

struct device {
    const char *name;
};

struct timer_list {
    unsigned long expires;
};

struct nfc_dev {
    struct device dev;
    struct nfc_target *active_target;
    u32 rf_mode;
    struct {
        int (*activate_target)(struct nfc_dev *, struct nfc_target *, u32);
        int (*check_presence)(struct nfc_dev *);
    } *ops;
    int shutting_down;
    struct timer_list check_pres_timer;
};

struct nfc_target {
    u32 idx;
};

#define ENODEV 19
#define EBUSY 16
#define ENOTCONN 107
#define NFC_RF_INITIATOR 0
#define NFC_CHECK_PRES_FREQ_MS 1000

#define pr_debug(fmt, ...) 

static inline void device_lock(struct device *dev) {}
static inline void device_unlock(struct device *dev) {}
static inline int device_is_registered(struct device *dev) { return 1; }
static inline const char *dev_name(const struct device *dev) { return ""; }
static inline struct nfc_target *nfc_find_target(struct nfc_dev *dev, u32 target_idx) { return NULL; }
static inline unsigned long msecs_to_jiffies(unsigned int msecs) { return 0; }
static inline void mod_timer(struct timer_list *timer, unsigned long expires) {}
static inline unsigned long jiffies = 0;