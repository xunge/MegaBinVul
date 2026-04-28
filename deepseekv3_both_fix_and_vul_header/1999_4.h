#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#define GFP_ATOMIC 0
#define ENOMEM 12
#define BR_STATE_DISABLED 0
#define __rcu

struct net_device;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct timer_list {
    void (*function)(unsigned long);
    unsigned long data;
};

struct net_bridge_port;

struct br_ip {
    // dummy definition
};

struct net_bridge_mdb_entry {
    struct hlist_node mglist;
    struct net_bridge_port_group *ports;
    struct timer_list timer;
};

struct net_bridge_port_group {
    struct br_ip addr;
    struct net_bridge_port *port;
    struct net_bridge_port_group *next;
    struct hlist_node mglist;
    struct timer_list timer;
    struct timer_list query_timer;
};

struct net_bridge_port {
    int state;
    struct hlist_head mglist;
};

struct net_bridge {
    struct net_device *dev;
    void *multicast_lock;
    struct hlist_head mglist;
    unsigned long multicast_membership_interval;
};

unsigned long jiffies;

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline int netif_running(struct net_device *dev) { return 1; }
static inline void mod_timer(struct timer_list *timer, unsigned long expires) {}
static inline void setup_timer(struct timer_list *timer, void (*function)(unsigned long), unsigned long data) {
    timer->function = function;
    timer->data = data;
}
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
    n->next = h->first;
    if (h->first) h->first->pprev = &n->next;
    h->first = n;
    n->pprev = &h->first;
}
static inline void *mlock_dereference(void *ptr, struct net_bridge *br) { return ptr; }
static inline void rcu_assign_pointer(void *p, void *v) { *(void**)p = v; }
#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define unlikely(x) (x)

static void br_multicast_port_group_expired(unsigned long data) {}
static void br_multicast_port_group_query_expired(unsigned long data) {}

static struct net_bridge_mdb_entry *br_multicast_new_group(struct net_bridge *br,
                                                          struct net_bridge_port *port,
                                                          struct br_ip *group) {
    return NULL;
}