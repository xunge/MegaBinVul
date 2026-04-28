#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct tty_struct;
struct net_device;

struct tty_driver {
    int (*write)(struct tty_struct *);
    void (*flush_buffer)(struct tty_struct *);
};

struct tty_struct {
    struct tty_driver *driver;
    void *disc_data;
    int receive_room;
};

struct net_device {
    int type;
    char name[16];
};

struct mkiss {
    struct net_device *dev;
    int buflock;
    atomic_int refcnt;
    int dead_sem;
    struct tty_struct *tty;
    int crcmode;
    int crcauto;
    unsigned char *rbuff;
    unsigned char *xbuff;
};

enum {
    CRC_MODE_NONE = 0,
    CRC_MODE_FLEX,
    CRC_MODE_SMACK,
    CRC_MODE_SMACK_TEST
};

#define CAP_NET_ADMIN 0
#define EPERM 1
#define EOPNOTSUPP 2
#define ENOMEM 3
#define ARPHRD_AX25 4
#define KERN_INFO ""

static int crc_force;

static int capable(int cap) { return 1; }
static int ax_open(struct net_device *dev) { return 0; }
static void ax_setup(struct net_device *dev) {}
static void spin_lock_init(int *lock) {}
static void atomic_set(atomic_int *atomic, int val) { *atomic = val; }
static void init_MUTEX_LOCKED(int *sem) { *sem = 0; }
static void printk(const char *fmt, ...) { 
    va_list args; 
    va_start(args, fmt); 
    vprintf(fmt, args); 
    va_end(args); 
}
static void *alloc_netdev(size_t size, const char *name, void (*setup)(struct net_device *)) { return calloc(1, size); }
static void *netdev_priv(struct net_device *dev) { return dev; }
static int register_netdev(struct net_device *dev) { return 0; }
static void netif_start_queue(struct net_device *dev) {}
static void free_netdev(struct net_device *dev) { free(dev); }
static void kfree(void *ptr) { free(ptr); }