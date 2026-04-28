#include <stddef.h>
#include <stdint.h>

struct in6_addr {
    uint8_t s6_addr[16];
};

struct list_head {
    struct list_head *next, *prev;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct nlmsghdr {
    uint32_t nlmsg_flags;
};

struct fib6_node;
struct fib6_info;
struct fib6_table;
struct nl_info;
struct netlink_ext_ack;
struct net;
struct nh_info;

#define CONFIG_IPV6_SUBTREES 1
#define RTN_ROOT 0
#define RTN_RTINFO 0
#define RTN_TL_ROOT 0
#define NLM_F_CREATE 0x200
#define NLM_F_REPLACE 0x100
#define ENOMEM 12

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(intptr_t)(x))
#define RCU_INIT_POINTER(p, v) ((p) = (v))
#define rcu_access_pointer(p) (p)
#define rcu_dereference_protected(p, c) (p)
#define rcu_assign_pointer(p, v) ((p) = (v))
#define lockdep_is_held(x) 1

struct fib6_node {
    struct fib6_node *parent;
    struct fib6_node *subtree;
    struct fib6_info *leaf;
    unsigned int fn_flags;
};

struct fib6_info {
    struct fib6_table *fib6_table;
    struct {
        struct in6_addr addr;
        int plen;
    } fib6_dst, fib6_src;
    struct list_head nh_list;
    struct hlist_node gc_link;
    struct nh_info *nh;
};

struct fib6_table {
    struct hlist_head tb6_gc_hlist;
    int tb6_lock;
};

struct nl_info {
    struct nlmsghdr *nlh;
    struct net *nl_net;
};

struct net {
    struct {
        struct fib6_info *fib6_null_entry;
    } ipv6;
};

struct nh_info {
    struct list_head f6i_list;
};

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
    n->next = h->first;
    n->pprev = &h->first;
    if (h->first)
        h->first->pprev = &n->next;
    h->first = n;
}

static inline void fib6_info_hold(struct fib6_info *rt) {}
static inline void fib6_info_release(struct fib6_info *rt) {}
static inline int fib6_has_expires(struct fib6_info *rt) { return 0; }
static inline int fib6_requires_src(struct fib6_info *rt) { return 0; }
static inline void fib6_routes_require_src_inc(struct net *net) {}
static inline void fib6_start_gc(struct net *net, struct fib6_info *rt) {}
static inline void __fib6_update_sernum_upto_root(struct fib6_info *rt, int sernum) {}
static inline int fib6_new_sernum(struct net *net) { return 0; }
static inline struct fib6_info *fib6_find_prefix(struct net *net, struct fib6_table *table, struct fib6_node *fn) { return NULL; }
static inline void fib6_repair_tree(struct net *net, struct fib6_table *table, struct fib6_node *fn) {}
static inline struct fib6_node *fib6_add_1(struct net *net, struct fib6_table *table, struct fib6_node *root, struct in6_addr *addr, int plen, int offset, int allow_create, int replace_required, struct netlink_ext_ack *extack) { return NULL; }
static inline int fib6_add_rt2node(struct fib6_node *fn, struct fib6_info *rt, struct nl_info *info, struct netlink_ext_ack *extack) { return 0; }
static inline struct fib6_node *node_alloc(struct net *net) { return NULL; }
static inline void node_free_immediate(struct net *net, struct fib6_node *fn) {}

#define FIB6_SUBTREE(fn) (fn)->subtree
#define pr_warn(fmt, ...)