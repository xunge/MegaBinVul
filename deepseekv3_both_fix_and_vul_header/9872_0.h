#include <netinet/in.h>
#include <linux/types.h>
#include <linux/if_ether.h>

struct net_bridge_mdb_entry;
struct net_bridge_mdb_htable;
struct br_ip {
    union {
        __be32 ip4;
    } u;
    __be16 proto;
};

static unsigned int __br_ip4_hash(struct net_bridge_mdb_htable *mdb, __be32 dst);
static struct net_bridge_mdb_entry *__br_mdb_ip_get(
    struct net_bridge_mdb_htable *mdb, const struct br_ip *dst, unsigned int hash);