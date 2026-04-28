#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define TCP_MIN_SND_MSS 48
#define MAX_TCP_OPTION_SPACE 40
#define GFP_KERNEL 0
#define SLAB_HWCACHE_ALIGN 0
#define SLAB_PANIC 0
#define SK_MEM_QUANTUM 4096
#define PAGE_SHIFT 12

struct tcp_skb_cb {
    char cb[48];
};

struct sk_buff {
    struct tcp_skb_cb cb;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_nulls_node {
    struct hlist_nulls_node *next, **pprev;
};

struct hlist_nulls_head {
    struct hlist_nulls_node *first;
};

struct inet_bind_bucket {
    int dummy;
};

struct inet_ehash_bucket {
    struct hlist_nulls_head chain;
};

struct inet_bind_hashbucket {
    struct {
        int lock;
    } spinlock_t;
    struct hlist_head chain;
};

struct inet_hashinfo {
    struct inet_bind_bucket *bind_bucket_cachep;
    struct inet_ehash_bucket *ehash;
    unsigned int ehash_mask;
    struct inet_bind_hashbucket *bhash;
    unsigned int bhash_size;
};

struct net {
    struct {
        int sysctl_tcp_wmem[3];
        int sysctl_tcp_rmem[3];
    } ipv4;
};

struct tcp_congestion_ops {
    int dummy;
};

struct tcp_reno {
    struct tcp_congestion_ops ops;
};

extern struct net init_net;
extern struct inet_hashinfo tcp_hashinfo;
extern struct tcp_reno tcp_reno;
extern int tcp_sockets_allocated;
extern int tcp_orphan_count;
extern unsigned long nr_free_buffer_pages(void);
extern void tcp_init_mem(void);
extern void tcp_v4_init(void);
extern void tcp_metrics_init(void);
extern int tcp_register_congestion_control(struct tcp_congestion_ops *);
extern void tcp_tasklet_init(void);
extern unsigned int thash_entries;
extern int sysctl_tcp_max_orphans;

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))
#define INIT_HLIST_NULLS_HEAD(p, i) ((p)->first = NULL)
#define INIT_HLIST_HEAD(p) ((p)->first = NULL)
#define spin_lock_init(lock) do {} while (0)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define pr_info(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define panic(fmt) { printf(fmt); exit(1); }
#define BUG_ON(condition) if (condition) { panic("BUG"); }

static inline void percpu_counter_init(void *counter, int value, int flags) {}
static inline void inet_hashinfo_init(void *hashinfo) {}
static inline void inet_hashinfo2_init(void *hashinfo, const char *name, unsigned int entries, int shift, int flags, int limit) {}
static inline void *kmem_cache_create(const char *name, size_t size, int flags, unsigned long align, void *ctor) { return NULL; }
static inline void *alloc_large_system_hash(const char *name, size_t size, unsigned int entries, int scale, int flags, void *arg1, void *arg2, int arg3, int limit) { return NULL; }
static inline int inet_ehash_locks_alloc(void *hashinfo) { return 0; }

#define __init