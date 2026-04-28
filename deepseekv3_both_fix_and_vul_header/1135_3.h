#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/capability.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define YAM_MAGIC 0xF10A
#define YAM_MAXBITRATE 9600
#define YAM_MAXBAUDRATE 115200
#define YAM_MAXMODE 2
#define YAM_MAXHOLDDLY 100
#define YAM_MAXTXDELAY 1000
#define YAM_MAXTXTAIL 1000
#define YAM_MAXPERSIST 255
#define YAM_MAXSLOTTIME 999

#define SIOCYAMRESERVED (SIOCDEVPRIVATE)
#define SIOCYAMSMCS (SIOCDEVPRIVATE + 1)
#define SIOCYAMSCFG (SIOCDEVPRIVATE + 2)
#define SIOCYAMGCFG (SIOCDEVPRIVATE + 3)

#define YAM_IOBASE 0x0001
#define YAM_IRQ 0x0002
#define YAM_BITRATE 0x0004
#define YAM_BAUDRATE 0x0008
#define YAM_MODE 0x0010
#define YAM_HOLDDLY 0x0020
#define YAM_TXDELAY 0x0040
#define YAM_TXTAIL 0x0080
#define YAM_PERSIST 0x0100
#define YAM_SLOTTIME 0x0200

struct net_device {
    unsigned long base_addr;
    unsigned int irq;
};

struct ifreq;

struct yamdrv_ioctl_cfg {
    int cmd;
    struct {
        unsigned int mask;
        unsigned int iobase;
        unsigned int irq;
        unsigned int bitrate;
        unsigned int baudrate;
        unsigned int mode;
        unsigned int txdelay;
        unsigned int holddly;
        unsigned int txtail;
        unsigned int persist;
        unsigned int slottime;
    } cfg;
};

struct yamdrv_ioctl_mcs {
    int cmd;
    int bitrate;
    unsigned char bits[YAM_MAXBITRATE];
};

struct yam_port {
    unsigned int magic;
    unsigned int iobase;
    unsigned int irq;
    unsigned int bitrate;
    unsigned int baudrate;
    unsigned int dupmode;
    unsigned int holdd;
    unsigned int txd;
    unsigned int txtail;
    unsigned int pers;
    unsigned int slot;
    unsigned int slotcnt;
};

static inline void add_mcs(unsigned char *bits, int bitrate, int dummy) {}

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define capable(x) 1
#define netif_running(x) 0
#define netdev_priv(x) ((struct yam_port *)0)
#define copy_from_user(to, from, size) 0
#define copy_to_user(to, from, size) 0
#define memdup_user(from, size) malloc(size)
#define kfree(x) free(x)
#define EINVAL 22
#define EFAULT 14
#define EPERM 1