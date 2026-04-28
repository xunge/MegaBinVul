#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/if.h>
#include <linux/netdevice.h>
#include <linux/sockios.h>

struct net_device {
    unsigned int flags;
};

struct port_status {
    int clocking;
};

typedef struct port_t {
    struct port_status *status;
} port_t;

struct sync_serial_settings {
    int clock_type;
    int clock_rate;
    int loopback;
};

#define SIOCWANDEV 0x894A
#define IF_GET_IFACE 0x0001
#define IF_IFACE_SYNC_SERIAL 0x1005
#define CLOCK_EXT 1
#define CLOCK_TXFROMRX 4
#define CAP_NET_ADMIN 12
#define ENOBUFS 105
#define EFAULT 14
#define EPERM 1
#define EBUSY 16
#define EINVAL 22
#define IFF_UP 0x1

port_t *dev_to_port(struct net_device *dev);
int hdlc_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd);
struct port_status *get_status(port_t *port);
int copy_to_user(void *to, const void *from, unsigned long n);
int copy_from_user(void *to, const void *from, unsigned long n);
int capable(int cap);