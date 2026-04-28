#include <stdbool.h>
#include <stddef.h>

struct fib_rule {
    int suppress_prefixlen;
    int suppress_ifgroup;
};

struct fib_lookup_arg {
    void *result;
};

struct fib6_result {
    void *rt6;
};

struct inet6_dev {
    struct net_device *dev;
};

struct rt6_info {
    struct inet6_dev *rt6i_idev;
    struct {
        int plen;
    } rt6i_dst;
};

struct net_device {
    int group;
};

void ip6_rt_put(struct rt6_info *rt);