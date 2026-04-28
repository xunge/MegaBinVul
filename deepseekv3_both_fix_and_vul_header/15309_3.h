#include <stdint.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>

typedef uint32_t u32;

struct sk_buff {
    void *unused;
};

struct net_device {
    char name[16];
};

struct dst_entry {
    atomic_int __refcnt;
    struct dst_entry *rt_next;
    struct net_device *dev;
};

struct flowi {
    int iif;
};

struct net {
    struct {
        int current_rt_cache_rebuild_count;
    } ipv4;
};

struct rtable {
    union {
        struct dst_entry dst;
    } u;
    struct flowi fl;
    int rt_type;
    uint32_t rt_dst;
    struct rtable *rt_next;  // Add this to match dst_entry.rt_next
};

struct rt_hash_bucket {
    struct rtable *chain;
};

static struct rt_hash_bucket rt_hash_table[1];
static int rt_chain_length_max;
static int ip_rt_gc_elasticity;
static int ip_rt_gc_min_interval;
static void *ipv4_dst_ops;
static unsigned long jiffies;

#define RTN_UNICAST 0
#define KERN_WARNING ""
#define KERN_DEBUG ""
#define ENOBUFS 0

static int in_softirq(void) { return 0; }
static int rt_caching(struct net *net) { return 1; }
static void rt_drop(struct rtable *rt) {}
static void rt_free(struct rtable *rt) {}
static int rt_is_expired(struct rtable *rt) { return 0; }
static int compare_keys(struct flowi *fl1, struct flowi *fl2) { return 0; }
static int compare_netns(struct rtable *rth1, struct rtable *rth2) { return 0; }
static void dst_use(struct dst_entry *dst, unsigned long now) {}
static void skb_dst_set(struct sk_buff *skb, struct dst_entry *dst) {}
static u32 rt_score(struct rtable *rt) { return 0; }
static void rt_garbage_collect(void *ops) {}
static int rt_emergency_hash_rebuild(struct net *net) { return 0; }
static int arp_bind_neighbour(struct dst_entry *dst) { return 0; }
static int net_ratelimit(void) { return 1; }
static void spin_lock_bh(void *lock) {}
static void spin_unlock_bh(void *lock) {}
static void *rt_hash_lock_addr(unsigned hash) { return NULL; }
static struct net *dev_net(struct net_device *dev) { return NULL; }
static void rcu_assign_pointer(void *p, void *v) {}
static int printk(const char *fmt, ...) { return 0; }
static int atomic_read(const atomic_int *v) { return atomic_load(v); }