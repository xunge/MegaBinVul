#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TAP_QUEUES 256
#define NET_SKB_PAD 32
#define NET_NAME_UNKNOWN 0
#define KERN_INFO 0
#define CAP_NET_ADMIN 0
#define EINVAL 22
#define EBUSY 16
#define EPERM 1
#define ENOMEM 12

#define IFF_TUN 0x0001
#define IFF_TAP 0x0002
#define IFF_NO_PI 0x1000
#define IFF_ONE_QUEUE 0x2000
#define IFF_VNET_HDR 0x4000
#define IFF_MULTI_QUEUE 0x0100
#define IFF_TUN_EXCL 0x8000
#define IFF_NOFILTER 0x1000
#define TUN_FEATURES (IFF_TUN|IFF_TAP|IFF_NO_PI|IFF_ONE_QUEUE|IFF_VNET_HDR|IFF_MULTI_QUEUE)

#define NETIF_F_SG 0x00000001
#define NETIF_F_FRAGLIST 0x00000002
#define NETIF_F_HW_VLAN_CTAG_TX 0x00000004
#define NETIF_F_HW_VLAN_STAG_TX 0x00000008
#define NETIF_F_LLTX 0x00000010
#define TUN_USER_FEATURES (NETIF_F_SG|NETIF_F_FRAGLIST)

struct net {
    void *user_ns;
};

struct file {
    void *private_data;
};

struct tun_struct {
    struct net_device *dev;
    unsigned long flags;
    int numqueues;
    int numdisabled;
    void *security;
    void *pcpu_stats;
    void *lock;
    void *disabled;
    int align;
    bool filter_attached;
    int sndbuf;
    int rx_batched;
    struct {
        int count;
    } txflt;
    int vnet_hdr_sz;
};

struct tun_file {
    bool detached;
    int ifindex;
    struct {
        struct {
            int sk_sndbuf;
        } *sk;
    } socket;
};

struct net_device {
    const void *netdev_ops;
    void *rtnl_link_ops;
    int ifindex;
    void *sysfs_groups[1];
    unsigned int hw_features;
    unsigned int features;
    unsigned int vlan_features;
    char name[IFNAMSIZ];
};

struct tun_pcpu_stats {
    // dummy structure
};

struct virtio_net_hdr {
    // dummy structure
};

const void *tun_netdev_ops;
const void *tap_netdev_ops;
const void *tun_link_ops;
const void *tun_attr_group;

static int tun_not_capable(struct tun_struct *tun) { return 0; }
static int security_tun_dev_open(void *security) { return 0; }
static int security_tun_dev_create(void) { return 0; }
static int security_tun_dev_alloc_security(void **security) { return 0; }
static void security_tun_dev_free_security(void *security) {}
static void tun_net_init(struct net_device *dev) {}
static void tun_flow_init(struct tun_struct *tun) {}
static void tun_flow_uninit(struct tun_struct *tun) {}
static int tun_attach(struct tun_struct *tun, struct file *file, bool nofilter) { return 0; }
static void tun_detach_all(struct net_device *dev) {}
static void tun_debug(int level, struct tun_struct *tun, const char *fmt, ...) {}
static void tun_setup(struct net_device *dev) {}
static struct net_device *__dev_get_by_name(struct net *net, const char *name) { return NULL; }
static void *netdev_priv(struct net_device *dev) { return NULL; }
static void dev_net_set(struct net_device *dev, struct net *net) {}
static void *netdev_alloc_pcpu_stats(size_t size) { return NULL; }
static void free_percpu(void *ptr) {}
static void free_netdev(struct net_device *dev) {}
static int register_netdevice(struct net_device *dev) { return 0; }
static void netif_carrier_on(struct net_device *dev) {}
static bool netif_running(struct net_device *dev) { return false; }
static void netif_tx_wake_all_queues(struct net_device *dev) {}
static void spin_lock_init(void *lock) {}
static int ns_capable(void *ns, int cap) { return 1; }
static struct net_device *alloc_netdev_mqs(int size, const char *name, 
                                         unsigned char name_assign_type,
                                         void (*setup)(struct net_device *),
                                         unsigned int txqs, unsigned int rxqs) { return NULL; }
static void INIT_LIST_HEAD(void *list) {}

// Fix for the specific error
#define netdev_alloc_pcpu_stats(type) netdev_alloc_pcpu_stats(sizeof(type))