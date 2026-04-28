#include <stddef.h>
#include <linux/netdevice.h>
#include <linux/if_arp.h>
#include <linux/if_ether.h>
#include <linux/errno.h>

#define HDLC_MAX_MTU 1500
#define IFF_TX_SKB_SHARING (1 << 0)

typedef struct pvc_device pvc_device;
typedef struct hdlc_device hdlc_device;

struct net_device {
    unsigned char dev_addr[32];
    unsigned char broadcast[32];
    const struct net_device_ops *netdev_ops;
    unsigned int mtu;
    unsigned int tx_queue_len;
    void *ml_priv;
    unsigned int priv_flags;
    void (*destructor)(struct net_device *dev);
};

struct pvc_device {
    struct net_device *ether;
    struct net_device *main;
};

struct hdlc_device {
    struct net_device *dev;
    struct hdlc_state *state;
};

struct hdlc_state {
    int dce_changed;
    int dce_pvc_count;
};

struct net_device_ops {
    int dummy;
};

static inline pvc_device *add_pvc(struct net_device *frad, unsigned int dlci) { return NULL; }
static inline struct net_device **get_dev_p(pvc_device *pvc, int type) { return NULL; }
static inline int pvc_is_used(pvc_device *pvc) { return 0; }
static inline void delete_unused_pvcs(hdlc_device *hdlc) {}
static inline struct hdlc_state *state(hdlc_device *hdlc) { return NULL; }
static inline hdlc_device *dev_to_hdlc(struct net_device *dev) { return NULL; }
static const struct net_device_ops pvc_ops;
static void pvc_setup(struct net_device *dev) {}
static void ether_setup(struct net_device *dev) {}
static void free_netdev(struct net_device *dev) {}
static int register_netdevice(struct net_device *dev) { return 0; }
static void random_ether_addr(unsigned char *addr) {}
static void dlci_to_q922(unsigned char *addr, unsigned int dlci) {}
static unsigned short htons(unsigned short hostshort) { return 0; }
static void netdev_warn(struct net_device *dev, const char *fmt) {}
static struct net_device *alloc_netdev(int size, const char *name, void (*setup)(struct net_device *)) { return NULL; }