#include <stddef.h>

struct dst_entry {
    int error;
};

struct sk_buff;

struct flowi6 {
    // dummy definition
};

struct net {
    struct {
        int fib6_has_custom_rules;
        void *fib6_rules_ops;
        void *fib6_local_tbl;
        void *fib6_main_tbl;
        struct rt6_info *ip6_null_entry;
    } ipv6;
};

struct rt6_info {
    struct dst_entry dst;
};

struct fib6_result {
    struct rt6_info *rt6;
};

typedef struct dst_entry *(*pol_lookup_t)(struct net *, void *, struct flowi6 *, const struct sk_buff *, int);

struct fib_lookup_arg {
    pol_lookup_t lookup_ptr;
    const struct sk_buff *lookup_data;
    struct dst_entry *result;
    int flags;
};

#define FIB_LOOKUP_NOREF 1
#define EAGAIN 11

static inline void *flowi6_to_flowi(struct flowi6 *fl6) {
    return (void *)fl6;
}

void l3mdev_update_flow(struct net *net, void *fl);
void fib_rules_lookup(void *ops, void *fl, int flags, struct fib_lookup_arg *arg);
void ip6_rt_put(struct rt6_info *rt);
void dst_hold(struct dst_entry *dst);