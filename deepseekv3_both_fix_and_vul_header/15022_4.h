#include <stddef.h>
#include <linux/types.h>
#include <linux/capability.h>
#include <linux/errno.h>
#include <linux/tty.h>
#include <linux/netdevice.h>
#include <linux/rtnetlink.h>
#include <linux/sched.h>

#define SLIP_MAGIC 0x5302
#define SL_MTU 296
#define SLF_INUSE 0

struct tty_struct {
    struct tty_driver *driver;
    void *disc_data;
    int receive_room;
};

struct tty_driver {
    int (*write)(struct tty_struct *tty);
};

struct net_device {
    int base_addr;
};

struct task_struct {
    pid_t pid;
};

#define current ((struct task_struct *)0)

static inline int test_bit(int nr, const volatile unsigned long *addr)
{
    return 1 & (addr[nr >> 5] >> (nr & 31));
}

static inline void set_bit(int nr, volatile unsigned long *addr)
{
    addr[nr >> 5] |= 1UL << (nr & 31);
}

static inline void clear_bit(int nr, volatile unsigned long *addr)
{
    addr[nr >> 5] &= ~(1UL << (nr & 31));
}

struct slip {
    int magic;
    struct tty_struct *tty;
    int line;
    pid_t pid;
    struct net_device *dev;
    unsigned long flags;
#ifdef CONFIG_SLIP_SMART
    int keepalive;
    int outfill;
    struct timer_list keepalive_timer;
    struct timer_list outfill_timer;
#endif
};

extern int capable(int cap);
extern void rtnl_lock(void);
extern void rtnl_unlock(void);
extern void sl_sync(void);
extern struct slip *sl_alloc(int line);
extern int sl_alloc_bufs(struct slip *sl, int mtu);
extern void sl_free_bufs(struct slip *sl);
extern int register_netdevice(struct net_device *dev);
extern int tty_devnum(struct tty_struct *tty);