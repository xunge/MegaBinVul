#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

#define GFP_ATOMIC 0
#define RTN_ROOT 1
#define RTN_TL_ROOT 2
#define RTN_RTINFO 4

struct net {
    struct {
        void *fib6_null_entry;
    } ipv6;
};

struct fib6_node {
    u32 fn_flags;
    union {
        struct fib6_node *child[2];
        void *leaf;
    };
};

struct inet_peer_base {
    // minimal definition
};

struct hlist_head {
    // minimal definition  
};

struct fib6_table {
    u32 tb6_id;
    struct fib6_node tb6_root;
    struct inet_peer_base tb6_peers;
    struct hlist_head tb6_gc_hlist;
};

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void rcu_assign_pointer(void *p, void *v) { *(void **)p = v; }
static void inet_peer_base_init(struct inet_peer_base *base) {}
static void INIT_HLIST_HEAD(struct hlist_head *head) {}