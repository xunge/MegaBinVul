#include <stddef.h>

typedef struct {
    int dummy;
} rwlock_t;

typedef struct list_head {
    struct list_head *next, *prev;
} list_head_t;

struct net_device_ops {
    int dummy;
};

struct ethtool_ops {
    int dummy;
};

struct net_device {
    struct net_device_ops *netdev_ops;
    struct ethtool_ops *ethtool_ops;
    void (*destructor)(struct net_device *);
    int tx_queue_len;
    unsigned int flags;
    unsigned int priv_flags;
    unsigned int features;
    unsigned int hw_features;
};

struct bond_params {
    int mode;
};

struct bonding {
    rwlock_t lock;
    rwlock_t curr_slave_lock;
    struct bond_params params;
    struct net_device *dev;
    list_head_t vlan_list;
};

#define IFF_MASTER 0x0400
#define IFF_MULTICAST 0x1000
#define IFF_BONDING 0x2000
#define IFF_XMIT_DST_RELEASE 0x4000
#define IFF_TX_SKB_SHARING 0x8000

#define NETIF_F_VLAN_CHALLENGED 0x10000
#define NETIF_F_LLTX 0x20000
#define NETIF_F_HW_VLAN_TX 0x40000
#define NETIF_F_HW_VLAN_RX 0x80000
#define NETIF_F_HW_VLAN_FILTER 0x100000
#define NETIF_F_ALL_CSUM 0x200000
#define NETIF_F_NO_CSUM 0x400000
#define BOND_VLAN_FEATURES 0x800000

static struct bond_params bonding_defaults;
static struct net_device_ops bond_netdev_ops;
static struct ethtool_ops bond_ethtool_ops;

static void rwlock_init(rwlock_t *lock) {}
static void INIT_LIST_HEAD(list_head_t *list) {
    list->next = list;
    list->prev = list;
}
static void ether_setup(struct net_device *dev) {}
static void bond_set_mode_ops(struct bonding *bond, int mode) {}
static void bond_destructor(struct net_device *bond_dev) {}
static struct bonding *netdev_priv(struct net_device *dev) { return NULL; }