#include <stddef.h>

struct net_bridge_mdb_htable;
struct net_bridge_mdb_entry;
struct br_ip;

static struct net_bridge_mdb_entry *__br_mdb_ip_get(
    struct net_bridge_mdb_htable *mdb, struct br_ip *dst, unsigned int hash);
unsigned int br_ip_hash(struct net_bridge_mdb_htable *mdb, struct br_ip *dst);