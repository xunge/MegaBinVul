#include <linux/netdevice.h>
#include <linux/net.h>
#include <linux/ip.h>
#include <linux/if_tunnel.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/rtnetlink.h>
#include <stdbool.h>

#define __net_init

struct net;
struct net_device {
    const struct rtnl_link_ops *rtnl_link_ops;
    unsigned int features;
    char name[IFNAMSIZ];
};

struct sit_net {
    struct ip_tunnel *tunnels[4];
    struct ip_tunnel *tunnels_wc;
    struct ip_tunnel *tunnels_l;
    struct ip_tunnel *tunnels_r;
    struct ip_tunnel *tunnels_r_l;
    struct net_device *fb_tunnel_dev;
};

struct ip_tunnel {
    struct {
        char name[IFNAMSIZ];
    } parms;
};

struct rtnl_link_ops;

extern int sit_net_id;
extern const struct rtnl_link_ops sit_link_ops;

#define NET_NAME_UNKNOWN 0
#define NETIF_F_NETNS_LOCAL (1 << 1)
#define ENOMEM 12
#define IFNAMSIZ 16

static inline struct sit_net *net_generic(struct net *net, int id) { return NULL; }
static inline bool net_has_fallback_tunnels(struct net *net) { return false; }
static inline void ipip6_tunnel_setup(struct net_device *dev) {}
static inline void ipip6_tunnel_clone_6rd(struct net_device *dev, struct sit_net *sitn) {}
static inline void ipip6_fb_tunnel_init(struct net_device *dev) {}
static inline void ipip6_dev_free(struct net_device *dev) {}
static inline struct net_device *alloc_netdev(int size, const char *name, unsigned char name_assign_type, void (*setup)(struct net_device *)) { return NULL; }
static inline void dev_net_set(struct net_device *dev, struct net *net) {}
static inline int register_netdev(struct net_device *dev) { return 0; }
static inline void *netdev_priv(const struct net_device *dev) { return NULL; }