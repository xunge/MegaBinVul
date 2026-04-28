#include <stddef.h>
#include <stdio.h>
#include <time.h>

struct sk_buff {
    unsigned char *data;
    int len;
};

struct net_device {
    char *name;
    unsigned long trans_start;
    unsigned int flags;
    int tbusy;
    void *priv;
};

struct tty_struct {
    struct tty_driver *driver;
    unsigned long flags;
};

struct tty_driver {
    int (*chars_in_buffer)(struct tty_struct *tty);
};

struct mkiss {
    struct tty_struct *tty;
    unsigned int xleft;
};

#define netdev_priv(dev) ((struct mkiss *)dev->priv)
#define netif_running(dev) (dev->flags & 0x1)
#define netif_queue_stopped(dev) (dev->tbusy)
#define netif_start_queue(dev) (dev->tbusy = 0)
#define netif_stop_queue(dev) (dev->tbusy = 1)
#define time_before(a,b) ((long)(b) - (long)(a) > 0)
#define HZ 100
#define TTY_DO_WRITE_WAKEUP 0
#define KERN_ERR ""

extern void ax_encaps(struct net_device *dev, unsigned char *data, int len);
extern void kfree_skb(struct sk_buff *skb);
extern unsigned long jiffies;
extern int printk(const char *fmt, ...);
extern void clear_bit(int nr, unsigned long *addr);