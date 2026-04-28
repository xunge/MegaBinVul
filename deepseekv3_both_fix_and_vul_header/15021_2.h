#include <stdatomic.h>
#include <pthread.h>

struct tty_struct {
    struct tty_driver *driver;
    void *disc_data;
    int receive_room;
};

struct tty_driver {
    int (*write)(struct tty_struct *tty);
};

struct net_device {
    unsigned int mtu;
};

struct sixpack {
    struct net_device *dev;
    pthread_spinlock_t lock;
    atomic_int refcnt;
    pthread_mutex_t dead_sem;
    struct tty_struct *tty;
    char *rbuff;
    char *xbuff;
    unsigned int mtu;
    unsigned int buffsize;
    unsigned int rcount;
    unsigned int rx_count;
    unsigned int rx_count_cooked;
    unsigned int xleft;
    unsigned int flags;
    unsigned int duplex;
    unsigned int tx_delay;
    unsigned int persistence;
    unsigned int slottime;
    unsigned char led_state;
    unsigned char status;
    unsigned char status1;
    unsigned char status2;
    unsigned char tx_enable;
    struct {
        void (*function)(unsigned long);
        unsigned long data;
    } tx_t;
    struct {
        void (*function)(unsigned long);
        unsigned long data;
    } resync_t;
};

#define AX25_MTU 256
#define SIXP_TXDELAY 0
#define SIXP_PERSIST 0
#define SIXP_SLOTTIME 0
#define EPERM 1
#define EOPNOTSUPP 95
#define ENOMEM 12
#define ENOBUFS 105
#define GFP_KERNEL 0
#define CAP_NET_ADMIN 0

static void sp_setup(struct net_device *dev) {}
static void sp_xmit_on_air(unsigned long data) {}
static void tnc_init(struct sixpack *sp) {}
static struct net_device *alloc_netdev(int size, const char *name, void (*setup)(struct net_device *)) { return 0; }
static void *netdev_priv(struct net_device *dev) { return 0; }
static int register_netdev(struct net_device *dev) { return 0; }
static void free_netdev(struct net_device *dev) {}
static void netif_start_queue(struct net_device *dev) {}
static void *kmalloc(size_t size, int flags) { return 0; }
static void kfree(void *ptr) {}
static int capable(int cap) { return 0; }