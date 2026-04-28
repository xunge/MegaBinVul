#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define ETH_ALEN 6
#define IFNAMSIZ 16
#define GFP_KERNEL 0
#define ARPHRD_ETHER 1
#define IFF_SLAVE 0x1000
#define IFF_UP 0x1
#define IFF_BONDING 0x10000
#define IFF_PROMISC 0x100
#define IFF_ALLMULTI 0x200
#define IFF_TX_SKB_SHARING 0x10000
#define NETIF_F_VLAN_CHALLENGED 0x80000000
#define EBUSY 16
#define EPERM 1
#define EINVAL 22
#define EOPNOTSUPP 95
#define ENOMEM 12
#define NETDEV_PRE_TYPE_CHANGE 0
#define NETDEV_POST_TYPE_CHANGE 1
#define NETDEV_JOIN 2

typedef uint8_t u8;

struct net_device {
    char name[IFNAMSIZ];
    unsigned long flags;
    unsigned int features;
    const struct net_device_ops *netdev_ops;
    const void *ethtool_ops;
    unsigned char dev_addr[ETH_ALEN];
    unsigned char addr_len;
    int type;
    int mtu;
    unsigned long priv_flags;
    void *npinfo;
};

struct net_device_ops {
    int (*ndo_do_ioctl)(struct net_device *dev);
    int (*ndo_set_mac_address)(struct net_device *dev, void *addr);
};

struct netdev_hw_addr {
    unsigned char addr[ETH_ALEN];
    struct netdev_hw_addr *next;
};

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct slave {
    struct net_device *dev;
    void *bond;
    unsigned char perm_hwaddr[ETH_ALEN];
    int queue_id;
    int original_mtu;
    int link;
    int delay;
    unsigned long jiffies;
    unsigned long last_arp_rx;
    int link_failure_count;
    struct slave *prev;
    struct slave *next;
    struct {
        int id;
    } ad_info;
};

struct bonding {
    struct net_device *dev;
    struct slave *primary_slave;
    struct slave *curr_active_slave;
    int slave_cnt;
    bool force_primary;
    struct {
        char primary[IFNAMSIZ];
        int fail_over_mac;
        int use_carrier;
        int miimon;
        int updelay;
        int arp_interval;
        int mode;
    } params;
    void *lock;
    void *curr_slave_lock;
};

#define BOND_FOM_ACTIVE 1
#define BOND_LINK_UP 1
#define BOND_LINK_DOWN 2
#define BOND_LINK_BACK 3
#define BOND_MODE_ACTIVEBACKUP 1
#define BOND_MODE_8023AD 4
#define BOND_MODE_TLB 5
#define BOND_MODE_ALB 6
#define MULTICAST_LACPDU_ADDR {0x01, 0x80, 0xC2, 0x00, 0x00, 0x02}
#define AD_TIMER_INTERVAL 100
#define BMSR_LSTATUS 0x04

extern unsigned long jiffies;

static inline void *netdev_priv(const struct net_device *dev) { return (void*)dev + sizeof(*dev); }
static inline int bond_is_lb(const struct bonding *bond) { return 0; }
static inline int bond_vlan_used(const struct bonding *bond) { return 0; }
static inline int USES_PRIMARY(int mode) { return 0; }
static inline int bond_is_active_slave(const struct slave *slave) { return 0; }
static inline void bond_set_slave_inactive_flags(struct slave *slave) {}
static inline void bond_select_active_slave(struct bonding *bond) {}
static inline void bond_set_active_slave(struct slave *slave) {}
static inline void bond_3ad_initialize(struct bonding *bond, int interval) {}
static inline void bond_3ad_bind_slave(struct slave *slave) {}
static inline void bond_set_carrier(struct bonding *bond) {}
static inline int bond_check_dev_link(struct bonding *bond, struct net_device *slave_dev, int polling) { return 0; }
static inline int bond_update_speed_duplex(struct slave *slave) { return 0; }
static inline void bond_compute_features(struct bonding *bond) {}
static inline void bond_attach_slave(struct bonding *bond, struct slave *slave) {}
static inline int bond_alb_init_slave(struct bonding *bond, struct slave *slave) { return 0; }
static inline int bond_create_slave_symlinks(struct net_device *bond_dev, struct net_device *slave_dev) { return 0; }
static inline void bond_destroy_slave_symlinks(struct net_device *bond_dev, struct net_device *slave_dev) {}
static inline int bond_handle_frame(void *skb) { return 0; }
static inline int netdev_rx_handler_register(struct net_device *dev, int (*handler)(void *), void *priv) { return 0; }
static inline int netdev_set_bond_master(struct net_device *slave_dev, struct net_device *bond_dev) { return 0; }
static inline int dev_set_mac_address(struct net_device *dev, struct sockaddr *addr) { return 0; }
static inline int dev_set_mtu(struct net_device *dev, int mtu) { return 0; }
static inline int dev_open(struct net_device *dev) { return 0; }
static inline void dev_close(struct net_device *dev) {}
static inline void dev_uc_flush(struct net_device *dev) {}
static inline void dev_mc_flush(struct net_device *dev) {}
static inline void dev_mc_add(struct net_device *dev, const unsigned char *addr) {}
static inline int dev_set_promiscuity(struct net_device *dev, int inc) { return 0; }
static inline int dev_set_allmulti(struct net_device *dev, int inc) { return 0; }
static inline void netif_addr_lock_bh(struct net_device *dev) {}
static inline void netif_addr_unlock_bh(struct net_device *dev) {}
static inline void write_lock_bh(void *lock) {}
static inline void write_unlock_bh(void *lock) {}
static inline void read_lock(void *lock) {}
static inline void read_unlock(void *lock) {}
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline int is_zero_ether_addr(const unsigned char *addr) { return 0; }
static inline void ether_setup(struct net_device *dev) {}
static inline void bond_setup_by_slave(struct net_device *bond_dev, struct net_device *slave_dev) {}
static inline int netdev_bonding_change(struct net_device *dev, int event) { return 0; }
static inline int notifier_to_errno(int ret) { return 0; }
static inline void call_netdevice_notifiers(int event, struct net_device *dev) {}
static inline int slave_enable_netpoll(struct slave *slave) { return 0; }
static inline void *bond_netpoll_info(struct bonding *bond) { return NULL; }
static inline void bond_add_vlans_on_slave(struct bonding *bond, struct net_device *slave_dev) {}
static inline void pr_warning(const char *fmt, ...) {}
static inline void pr_debug(const char *fmt, ...) {}
static inline void pr_err(const char *fmt, ...) {}
static inline void pr_info(const char *fmt, ...) {}

#define netdev_for_each_mc_addr(ha, dev) \
    for (ha = (struct netdev_hw_addr *)(dev); ha; ha = ha->next)

#define SLAVE_AD_INFO(slave) ((slave)->ad_info)