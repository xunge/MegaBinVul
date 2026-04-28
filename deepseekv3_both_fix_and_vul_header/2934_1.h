#include <linux/types.h>
#include <linux/if.h>
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/netdevice.h>

struct net_device {
    int ifindex;
};

struct net_bridge_port {
    struct net_device *dev;
};

struct br_ip {
    __u16 proto;
    union {
        __be32 ip4;
        struct in6_addr ip6;
    } u;
};

struct br_mdb_entry {
    int ifindex;
    struct {
        __u16 proto;
        union {
            __be32 ip4;
            struct in6_addr ip6;
        } u;
    } addr;
};

void __br_mdb_notify(struct net_device *dev, struct br_mdb_entry *entry, int type);

#define IS_ENABLED(x) 0