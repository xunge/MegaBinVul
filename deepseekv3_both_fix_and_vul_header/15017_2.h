#include <linux/tty.h>
#include <linux/netdevice.h>
#include <linux/if_arp.h>
#include <linux/errno.h>
#include <stddef.h>

#define X25_ASY_MAGIC 0x5303
#define ARPHRD_X25 271

struct tty_struct;
struct net_device;

struct tty_operations {
    int (*write)(struct tty_struct *tty, const unsigned char *buf, int count);
    void (*flush_buffer)(struct tty_struct *tty);
};

struct tty_struct {
    void *disc_data;
    struct tty_operations *driver;
    int receive_room;
};

struct net_device {
    unsigned short type;
    unsigned long base_addr;
};

struct x25_asy {
    int magic;
    struct tty_struct *tty;
    struct net_device *dev;
    unsigned long base_addr;
};

static struct x25_asy *x25_asy_alloc(void);
static int x25_asy_open(struct net_device *dev);
static void tty_ldisc_flush(struct tty_struct *tty);