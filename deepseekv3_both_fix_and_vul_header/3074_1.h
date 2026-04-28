#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define __rcu
#define ETH_P_IP 0x0800
#define EINVAL 22
#define EBUSY 16
#define BR_STATE_DISABLED 0
#define CONFIG_IPV6 0
#define IS_ENABLED(x) 0

typedef unsigned long spinlock_t;
typedef unsigned long jiffies_t;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct timer_list {
    unsigned long data;
    unsigned int timer_armed;
};

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct net_device {
    int ifindex;
};

struct net_bridge_port {
    struct net_device *dev;
    int state;
};

struct net_bridge_port_group {
    struct net_bridge_port *port;
    struct net_bridge_port_group *next;
    struct hlist_node mglist;
    struct timer_list timer;
    struct rcu_head rcu;
};

struct net_bridge_mdb_entry {
    struct net_bridge_port_group *ports;
    struct hlist_node *mglist;
    struct timer_list timer;
    unsigned int timer_armed;
};

struct net_bridge_mdb_htable {
    // dummy structure
};

struct br_mdb_entry {
    struct {
        uint16_t proto;
        union {
            uint32_t ip4;
            struct in6_addr ip6;
        } u;
    } addr;
    int ifindex;
};

struct net_bridge {
    struct net_device *dev;
    int multicast_disabled;
    struct timer_list multicast_querier_timer;
    spinlock_t multicast_lock;
    struct net_bridge_mdb_htable *mdb;
};

struct br_ip {
    uint16_t proto;
    union {
        uint32_t ip4;
        struct in6_addr ip6;
    } u;
};

static inline int netif_running(struct net_device *dev) { return 1; }
static inline int timer_pending(struct timer_list *timer) { return 0; }
static inline void spin_lock_bh(spinlock_t *lock) {}
static inline void spin_unlock_bh(spinlock_t *lock) {}
static inline void hlist_del_init(struct hlist_node *n) {}
static inline void del_timer(struct timer_list *timer) {}
static inline void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *head)) {}
static inline void mod_timer(struct timer_list *timer, jiffies_t expires) {}
static inline struct net_bridge_mdb_entry *br_mdb_ip_get(struct net_bridge_mdb_htable *mdb, struct br_ip *ip) { return NULL; }
static inline void br_multicast_free_pg(struct rcu_head *head) {}

#define mlock_dereference(ptr, br) (ptr)
#define rcu_assign_pointer(ptr, val) (ptr = val)
#define jiffies 0