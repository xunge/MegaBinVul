#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

typedef uint32_t u32;

struct fib_rule;
struct fib_lookup_arg;
struct fib6_result;
struct fib6_table;
struct net;
struct flowi6;
struct dst_entry;
struct rt6_info;

struct net_device {
    struct net_device *dev;
};

typedef struct rt6_info *(*pol_lookup_t)(struct net *, struct fib6_table *, struct flowi6 *, void *, int);

enum {
    FR_ACT_TO_TBL,
    FR_ACT_UNREACHABLE,
    FR_ACT_BLACKHOLE,
    FR_ACT_PROHIBIT
};

#define EINVAL 22
#define EACCES 13
#define EAGAIN 11
#define ENETUNREACH 101

struct flowi6 {
    /* flowi6 members would be defined here */
};

struct dst_entry {
    struct net_device *dev;
    int error;
};

struct rt6_info {
    struct dst_entry dst;
};

struct net {
    struct {
        struct rt6_info *ip6_null_entry;
        struct rt6_info *ip6_blk_hole_entry;
        struct rt6_info *ip6_prohibit_entry;
    } ipv6;
};

struct flowi {
    union {
        struct flowi6 ip6;
    } u;
};

struct fib_rule {
    int action;
    struct net *fr_net;
};

struct fib_lookup_arg {
    union {
        struct fib6_result *result;
        struct rt6_info *rt;
    };
    pol_lookup_t lookup_ptr;
    void *lookup_data;
};

struct fib6_result {
    struct rt6_info *rt6;
};

u32 fib_rule_get_table(struct fib_rule *rule, struct fib_lookup_arg *arg);
struct fib6_table *fib6_get_table(struct net *net, u32 id);
int fib6_rule_saddr(struct net *net, struct fib_rule *rule, int flags, struct flowi6 *flp6, struct net_device *dev);
void ip6_rt_put(struct rt6_info *rt);
void dst_hold(struct dst_entry *dst);
struct net_device *ip6_dst_idev(struct dst_entry *dst);