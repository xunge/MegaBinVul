#include <stdint.h>
#include <stddef.h>

#define SLIP_MAGIC 0x5302

struct tty_struct {
    void *disc_data;
};

struct net_device;

struct work_struct {
    // dummy definition
    int dummy;
};

struct timer_list {
    // dummy definition
    int dummy;
};

struct slip {
    int magic;
    struct tty_struct *tty;
    uintptr_t lock;
    struct work_struct tx_work;
    struct timer_list keepalive_timer;
    struct timer_list outfill_timer;
    struct net_device *dev;
};

static void spin_lock_bh(uintptr_t *lock) {}
static void spin_unlock_bh(uintptr_t *lock) {}
static void flush_work(struct work_struct *work) {}
static void del_timer_sync(struct timer_list *timer) {}
static void unregister_netdev(struct net_device *dev) {}