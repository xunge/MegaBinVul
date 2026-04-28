#include <stdio.h>
#include <stdint.h>

#define KERN_WARNING ""
#define TTY_DO_WRITE_WAKEUP 0

struct net_device {
    char *name;
    void *priv;
};

struct tty_struct {
    uint32_t flags;
    struct {
        int (*chars_in_buffer)(struct tty_struct *);
    } *driver;
};

struct x25_asy {
    uint32_t lock;
    struct tty_struct *tty;
    int xleft;
};

void x25_asy_unlock(struct x25_asy *sl);
void spin_lock(uint32_t *lock);
void spin_unlock(uint32_t *lock);
int netif_queue_stopped(struct net_device *dev);
int printk(const char *fmt, ...);