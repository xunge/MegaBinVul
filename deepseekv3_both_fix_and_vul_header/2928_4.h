#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

struct file {
    void *private_data;
    int f_flags;
};

struct device {
    char *dev;
};

struct usb_interface {
    struct device dev;
};

struct wdm_device {
    void *rlock;
    int length;
    unsigned long flags;
    int read;
    void *wait;
    void *iuspin;
    int rerr;
    struct usb_interface *intf;
    char *ubuf;
    int reslength;
};

#define WDM_DISCONNECTING 0
#define WDM_OVERFLOW 1
#define WDM_READ 2
#define WDM_RESETTING 3

#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))

#define test_bit(nr, addr) ((*(addr)) & (1UL << (nr)))
#define clear_bit(nr, addr) ((*(addr)) &= ~(1UL << (nr)))

#define mutex_lock_interruptible(lock) 0
#define mutex_unlock(lock)
#define spin_lock_irq(lock)
#define spin_unlock_irq(lock)
#define wait_event_interruptible(wq, condition) 0

#define ERESTARTSYS 512
#define ENODEV 19
#define ENOBUFS 105
#define EAGAIN 11
#define EIO 5
#define EFAULT 14

typedef long ssize_t;
typedef long loff_t;
typedef unsigned long size_t;

#define __user

static inline void usb_mark_last_busy(void *dev) {}
static inline void *interface_to_usbdev(void *intf) { return intf; }
static inline void dev_dbg(struct device *dev, const char *fmt, ...) {}
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }