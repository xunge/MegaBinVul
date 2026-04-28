#include <stdbool.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>

struct in6_addr {
    unsigned char s6_addr[16];
};

struct dst_entry {
    struct rt6_info *rt6_next;
    unsigned long expires;
    struct net_device *dev;
};

struct list_head {
    struct list_head *next, *prev;
};

struct nlmsghdr {
    unsigned int nlmsg_flags;
};

struct fib6_node {
    struct rt6_info *leaf;
    struct fib6_node *rr_ptr;
    unsigned int fn_flags;
};

struct rt6_info {
    struct dst_entry dst;
    struct fib6_node *rt6i_node;
    struct in6_addr rt6i_gateway;
    struct inet6_dev *rt6i_idev;
    unsigned int rt6i_flags;
    unsigned int rt6i_metric;
    unsigned int rt6i_nsiblings;
    struct list_head rt6i_siblings;
    atomic_int rt6i_ref;
};

struct nl_info {
    struct nlmsghdr *nlh;
    struct net *nl_net;
};

struct rt6_statistics {
    int fib_rt_entries;
    int fib_route_nodes;
};

struct ipv6_net {
    struct rt6_statistics *rt6_stats;
};

struct net {
    struct ipv6_net ipv6;
};

static inline bool ipv6_addr_equal(const struct in6_addr *a1, const struct in6_addr *a2)
{
    return false;
}

static inline bool rt6_qualify_for_ecmp(const struct rt6_info *rt)
{
    return false;
}

static inline void rt6_clean_expires(struct rt6_info *rt)
{
}

static inline void rt6_set_expires(struct rt6_info *rt, unsigned long expires)
{
}

static inline void rt6_release(struct rt6_info *rt)
{
}

static inline void inet6_rt_notify(int event, struct rt6_info *rt, struct nl_info *info)
{
}

static inline void atomic_inc(atomic_int *v)
{
    (*v)++;
}

static inline void pr_warn(const char *fmt, ...) {}

#define list_add_tail(new, head) do { \
    (new)->next = (head); \
    (new)->prev = (head)->prev; \
    (head)->prev->next = (new); \
    (head)->prev = (new); \
} while (0)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define RTN_RTINFO 0
#define RTF_EXPIRES 0
#define RTF_GATEWAY 0
#define NLM_F_REPLACE 0
#define NLM_F_CREATE 0
#define NLM_F_EXCL 0
#define RTM_NEWROUTE 0
#define EEXIST 0
#define ENOENT 0
#define BUG_ON(cond) do { if (cond) {} } while (0)