#include <stdio.h>
#include <stdlib.h>

struct tty_struct {
    void *driver_data;
};

struct file;

struct kref {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct hvc_struct {
    int lock;
    struct tty_struct *tty;
    int count;
    int vtermno;
    struct kref kref;
    struct work_struct tty_resize;
    struct {
        void (*notifier_del)(struct hvc_struct *, void *);
    } *ops;
    void *data;
};

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define tty_kref_get(tty) ((void)0)
#define tty_kref_put(tty) ((void)0)
#define cancel_work_sync(work) ((void)0)
#define tty_wait_until_sent(tty, timeout) ((void)0)
#define KERN_ERR ""
#define printk(fmt, ...) ((void)0)
#define kref_put(kref, release) ((void)0)
#define tty_hung_up_p(filp) (0)
#define HVC_CLOSE_WAIT 0
void destroy_hvc_struct(struct kref *kref) {}