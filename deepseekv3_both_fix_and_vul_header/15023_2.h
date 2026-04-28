#include <stdint.h>
#include <stddef.h>

struct net_device {
    unsigned long trans_start;
    char *name;
};

struct tty_driver;
struct tty_struct {
    struct tty_driver *driver;
    unsigned long flags;
};

struct slip {
    uintptr_t lock;
    struct tty_struct *tty;
    int xleft;
};

#define HZ 100
#define KERN_WARNING ""
#define jiffies 0
#define TTY_DO_WRITE_WAKEUP 0

static inline void spin_lock(uintptr_t *lock) {}
static inline void spin_unlock(uintptr_t *lock) {}
static inline int netif_queue_stopped(struct net_device *dev) { return 0; }
static inline int netif_running(struct net_device *dev) { return 0; }
static inline struct slip *netdev_priv(struct net_device *dev) { return NULL; }
static inline int time_before(unsigned long a, unsigned long b) { return 0; }
static inline void sl_unlock(struct slip *sl) {}