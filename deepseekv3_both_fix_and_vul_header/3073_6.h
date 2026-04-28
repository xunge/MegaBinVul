#include <stddef.h>
#include <stdbool.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct timer_list {
    int dummy;
};

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct net_device;

struct net_bridge {
    struct net_bridge_mdb_htable *mdb;
    struct net_device *dev;
};

struct net_bridge_port_group {
    struct net_bridge_port_group *next;
    struct hlist_node mglist;
    struct timer_list timer;
    struct rcu_head rcu;
    void *addr;
};

struct net_bridge_mdb_htable;
struct net_bridge_mdb_entry {
    struct net_bridge_port_group *ports;
    struct hlist_node *mglist;
    bool timer_armed;
    struct timer_list timer;
};

#define WARN_ON(condition) (condition)
#define __rcu
#define rcu_assign_pointer(p, v) ((p) = (v))
#define mlock_dereference(p, b) (p)
#define hlist_del_init(p) do { *(p) = (struct hlist_node){0}; } while (0)
#define call_rcu_bh(p, f) do {} while (0)
#define del_timer(p) do {} while (0)
#define mod_timer(p, j) do {} while (0)
#define netif_running(dev) (0)
#define jiffies 0

static struct net_bridge_mdb_entry *br_mdb_ip_get(struct net_bridge_mdb_htable *mdb, void *addr) {
    static struct net_bridge_mdb_entry dummy = {
        .ports = NULL,
        .mglist = NULL,
        .timer_armed = false
    };
    return &dummy;
}