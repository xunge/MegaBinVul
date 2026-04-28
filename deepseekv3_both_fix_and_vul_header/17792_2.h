#include <stddef.h>
#include <stdint.h>

#define SLCAN_MAGIC 0x53CA

struct tty_struct {
    void *disc_data;
};

struct net_device;

struct work_struct {
    // Minimal definition to make it complete
    int dummy;
};

struct slcan {
    int magic;
    struct tty_struct *tty;
    uintptr_t lock;
    struct work_struct tx_work;
    struct net_device *dev;
};

static inline void spin_lock_bh(uintptr_t *lock) { (void)lock; }
static inline void spin_unlock_bh(uintptr_t *lock) { (void)lock; }
static inline void flush_work(struct work_struct *work) { (void)work; }
static inline void unregister_netdev(struct net_device *dev) { (void)dev; }