#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define YAM_MAGIC 0xF10A
#define YAM_MAXBITRATE 9600
#define YAM_MAXBAUDRATE 115200
#define YAM_MAXMODE 2
#define YAM_MAXHOLDDLY 100
#define YAM_MAXTXDELAY 1000
#define YAM_MAXTXTAIL 1000
#define YAM_MAXPERSIST 255
#define YAM_MAXSLOTTIME 1000

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

#define SIOCDEVPRIVATE 0x89F0
#define SIOCYAMRESERVED 0
#define SIOCYAMSMCS 1
#define SIOCYAMSCFG 2
#define SIOCYAMGCFG 3

#define GFP_KERNEL 0
#define CAP_NET_ADMIN 12
#define CAP_SYS_RAWIO 17

#define EINVAL 22
#define EFAULT 14
#define EPERM 1
#define ENOBUFS 105

struct net_device {
    unsigned long base_addr;
    unsigned int irq;
};

struct ifreq {
    void *ifr_data;
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

struct yamdrv_ioctl_cfg {
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
    unsigned int bitrate;
    unsigned char bits[YAM_MAXBITRATE];
};

static inline struct yam_port *netdev_priv(struct net_device *dev) {
    return (struct yam_port *)dev;
}

static inline int netif_running(struct net_device *dev) {
    return 0;
}

static inline int capable(int cap) {
    return 1;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_to_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

int add_mcs(unsigned char *bits, unsigned int bitrate, int predef);