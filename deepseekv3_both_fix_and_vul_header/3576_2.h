#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

typedef unsigned short sa_family_t;

#define IFLA_NET_NS_PID 1
#define IFLA_NET_NS_FD 2
#define IFLA_MAP 3
#define IFLA_ADDRESS 4
#define IFLA_MTU 5
#define IFLA_GROUP 6
#define IFLA_IFALIAS 7
#define IFLA_BROADCAST 8
#define IFLA_MASTER 9
#define IFLA_CARRIER 10
#define IFLA_TXQLEN 11
#define IFLA_OPERSTATE 12
#define IFLA_LINKMODE 13
#define IFLA_VFINFO_LIST 14
#define IFLA_VF_PORTS 15
#define IFLA_PORT_SELF 16
#define IFLA_AF_SPEC 17
#define IFLA_PORT_MAX 17
#define IFLA_PORT_VF 1
#define IFLA_VF_INFO 1
#define IFLA_VF_PORT 2
#define PORT_SELF_VF 0

#define CAP_NET_ADMIN 1
#define EPERM 1
#define EOPNOTSUPP 95
#define ENODEV 19
#define ENOMEM 12
#define EINVAL 22

#define GFP_KERNEL 0
#define NETDEV_CHANGEADDR 1

struct net_device {
    const struct net_device_ops *netdev_ops;
    int addr_len;
    unsigned short type;
    char *broadcast;
    int tx_queue_len;
    unsigned char link_mode;
    char name[16];
};

struct ifinfomsg {
    int ifi_index;
    int ifi_flags;
    int ifi_change;
};

struct nlattr {
    int nla_type;
    void *data;
    int len;
};

struct net {
    struct user_namespace *user_ns;
};

struct user_namespace {
};

struct rtnl_link_ifmap {
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned short base_addr;
    unsigned char irq;
    unsigned char dma;
    unsigned char port;
};

struct ifmap {
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned short base_addr;
    unsigned char irq;
    unsigned char dma;
    unsigned char port;
};

struct sockaddr {
    sa_family_t sa_family;
    char sa_data[14];
};

struct rtnl_af_ops {
    int (*set_link_af)(struct net_device *, struct nlattr *);
};

struct net_device_ops {
    int (*ndo_set_config)(struct net_device *, struct ifmap *);
    int (*ndo_set_vf_port)(struct net_device *, int, struct nlattr **);
};

static void *dev_base_lock;

static inline void *nla_data(const struct nlattr *nla) { return nla->data; }
static inline int nla_get_u32(const struct nlattr *nla) { return *(int *)nla->data; }
static inline unsigned char nla_get_u8(const struct nlattr *nla) { return *(unsigned char *)nla->data; }
static inline void nla_memcpy(void *dest, const struct nlattr *src, int count) { memcpy(dest, src->data, count); }
static inline int nla_parse_nested(struct nlattr **tb, int maxtype, const struct nlattr *nla, const void *policy) { return 0; }
static inline int nla_type(const struct nlattr *nla) { return nla->nla_type; }
static inline int nla_len(const struct nlattr *nla) { return nla->len; }

static inline struct net *dev_net(const struct net_device *dev) { return NULL; }
static inline struct net *rtnl_link_get_net(struct net *net, struct nlattr **tb) { return NULL; }
static inline int IS_ERR(const void *ptr) { return 0; }
static inline int PTR_ERR(const void *ptr) { return 0; }
static inline int ns_capable(struct user_namespace *ns, int cap) { return 1; }
static inline int dev_change_net_namespace(struct net_device *dev, struct net *net, char *name) { return 0; }
static inline void put_net(struct net *net) {}
static inline int netif_device_present(const struct net_device *dev) { return 1; }
static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline int dev_set_mac_address(struct net_device *dev, struct sockaddr *sa) { return 0; }
static inline int dev_set_mtu(struct net_device *dev, int mtu) { return 0; }
static inline void dev_set_group(struct net_device *dev, int group) {}
static inline int dev_change_name(struct net_device *dev, char *name) { return 0; }
static inline int dev_set_alias(struct net_device *dev, const char *alias, int len) { return 0; }
static inline void call_netdevice_notifiers(int val, struct net_device *dev) {}
static inline int dev_change_flags(struct net_device *dev, int flags) { return 0; }
static inline int rtnl_dev_combine_flags(struct net_device *dev, struct ifinfomsg *ifm) { return 0; }
static inline int do_set_master(struct net_device *dev, int master) { return 0; }
static inline int dev_change_carrier(struct net_device *dev, int carrier) { return 0; }
static inline void set_operstate(struct net_device *dev, int state) {}
static inline void write_lock_bh(void *lock) {}
static inline void write_unlock_bh(void *lock) {}
static inline int do_setvfinfo(struct net_device *dev, struct nlattr *attr) { return 0; }
static inline const struct rtnl_af_ops *rtnl_af_lookup(int type) { return NULL; }
static inline void net_warn_ratelimited(const char *fmt, ...) {}
static inline void BUG() {}

static const void *ifla_port_policy;

#define nla_for_each_nested(attr, nla, rem) for (attr = nla, rem = 0; rem < 1; rem++)