#include <stdint.h>

struct net_device;
struct tty_struct;

struct slip {
    uintptr_t lock;
    struct tty_struct *tty;
    int xleft;
};

#define spin_lock(lock) 
#define spin_unlock(lock) 
#define netdev_priv(dev) ((struct slip *)0)
#define netif_queue_stopped(dev) (0)
#define netif_running(dev) (0)
#define time_before(a, b) (0)
#define jiffies (0)
#define HZ (1)
#define dev_trans_start(dev) (0)
#define KERN_WARNING ""
#define tty_chars_in_buffer(tty) (0)
#define TTY_DO_WRITE_WAKEUP (0)
#define clear_bit(nr, addr) 
#define sl_unlock(sl)