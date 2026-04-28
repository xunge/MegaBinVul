#include <netinet/in.h>
#include <linux/if_ether.h>

struct net_bridge_mdb_entry;
struct net_bridge_mdb_htable;
struct in6_addr;

struct br_ip {
    union {
        struct in6_addr ip6;
    } u;
    __be16 proto;
};

static inline void ipv6_addr_copy(struct in6_addr *a1, const struct in6_addr *a2);
static struct net_bridge_mdb_entry *__br_mdb_ip_get(struct net_bridge_mdb_htable *mdb, const struct br_ip *dst, unsigned int hash);
static unsigned int __br_ip6_hash(struct net_bridge_mdb_htable *mdb, const struct in6_addr *addr);